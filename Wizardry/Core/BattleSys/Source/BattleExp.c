#include "common-chax.h"
#include "skill-system.h"
#include "battle-system.h"
#include "bwl.h"
#include "constants/skills.h"

LYN_REPLACE_CHECK(GetUnitExpLevel);
int GetUnitExpLevel(struct Unit *unit)
{
    int base, bonus;
    base = unit->level;

    if (CheckHasBwl(UNIT_CHAR_ID(unit)))
        bonus = GetUnitHiddenLevel(unit);
    else
        bonus = gpClassPreLoadHiddenLevel[UNIT_CLASS_ID(unit)];

    return base + bonus;
}

STATIC_DECLAR int KernelModifyBattleUnitExp(int base, struct BattleUnit *actor, struct BattleUnit *target)
{
    int status = base;

#if defined(SID_Blossom) && (COMMON_SKILL_VALID(SID_Blossom))
    if (BattleSkillTester(actor, SID_Blossom))
        status = status / 2;
#endif

#if defined(SID_Paragon) && (COMMON_SKILL_VALID(SID_Paragon))
    if (BattleSkillTester(actor, SID_Paragon))
        status = status * 2;
#endif

#if defined(SID_Mentorship) && (COMMON_SKILL_VALID(SID_Mentorship))
    if (BattleSkillTester(actor, SID_Mentorship))
        status = status * 1.2;
    else
    {
        for (int i = 0; i < ARRAY_COUNT_RANGE2x2; i++)
        {
            int _x = actor->unit.xPos + gVecs_2x2[i].x;
            int _y = actor->unit.yPos + gVecs_2x2[i].y;

            struct Unit *unit_ally = GetUnitAtPosition(_x, _y);

            if (!UNIT_IS_VALID(unit_ally))
                continue;

            if (unit_ally->state & (US_HIDDEN | US_DEAD | US_RESCUED | US_BIT16))
                continue;

            if (!AreUnitsAllied(actor->unit.index, unit_ally->index))
                continue;

            if (SkillTester(unit_ally, SID_Mentorship))
            {
                status = status * 1.2;
                break;
            }
        }
    }
#endif

    /* Check last */
#if defined(SID_VoidCurse) && (COMMON_SKILL_VALID(SID_VoidCurse))
    if (BattleSkillTester(target, SID_VoidCurse))
        status = 0;
#endif

    LIMIT_AREA(status, 1, 100);
    return status;
}

LYN_REPLACE_CHECK(GetBattleUnitExpGain);
int GetBattleUnitExpGain(struct BattleUnit *actor, struct BattleUnit *target)
{
    int result;

    if (!CanBattleUnitGainLevels(actor) || (actor->unit.curHP == 0) || UNIT_CATTRIBUTES(&target->unit) & CA_NEGATE_LETHALITY)
        return 0;

    if (!actor->nonZeroDamage)
        return 1;

    result = GetUnitRoundExp(&actor->unit, &target->unit);
    result += GetUnitKillExpBonus(&actor->unit, &target->unit);

    result = KernelModifyBattleUnitExp(result, actor, target);

#if !CHAX
    ModifyUnitSpecialExp(&actor->unit, &target->unit, &result);
#endif

    return result;
}

LYN_REPLACE_CHECK(BattleApplyMiscActionExpGains);
void BattleApplyMiscActionExpGains(void)
{
    int exp;

    if (UNIT_FACTION(&gBattleActor.unit) != FACTION_BLUE)
        return;

    if (!CanBattleUnitGainLevels(&gBattleActor))
        return;

    if (gPlaySt.chapterStateBits & PLAY_FLAG_EXTRA_MAP)
        return;

    exp = 10;
    exp = KernelModifyBattleUnitExp(exp, &gBattleActor, &gBattleTarget);

    gBattleActor.expGain = exp;
    gBattleActor.unit.exp += exp;

    CheckBattleUnitLevelUp(&gBattleActor);
}

LYN_REPLACE_CHECK(GetBattleUnitStaffExp);
int GetBattleUnitStaffExp(struct BattleUnit *bu)
{
    int result;

    if (!CanBattleUnitGainLevels(bu))
        return 0;

    if (gBattleHitArrayRe->attributes & BATTLE_HIT_ATTR_MISS)
        return 1;

    result = 10 + GetItemCostPerUse(bu->weapon) / 20;

    if (UNIT_CATTRIBUTES(&bu->unit) & CA_PROMOTED)
        result = result / 2;

    result = KernelModifyBattleUnitExp(
        result,
        bu,
        bu == &gBattleActor
            ? &gBattleTarget
            : &gBattleActor);

    if (result > 100)
        result = 100;

    return result;
}
