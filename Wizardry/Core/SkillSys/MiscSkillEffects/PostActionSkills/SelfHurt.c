#include "common-chax.h"
#include "skill-system.h"
#include "debuff.h"
#include "battle-system.h"
#include "constants/skills.h"

struct ProcPostActionSelfHurt {
    PROC_HEADER;
    struct Unit * unit;
    int damage;
    u32 lock;
};

STATIC_DECLAR void PostActionWaitSelfHurtAnimDone(struct ProcPostActionSelfHurt * proc)
{
    if (proc->lock == GetGameClock())
        Proc_Break(proc);
}

STATIC_DECLAR void PostActionWaitSelfHurtReal(struct ProcPostActionSelfHurt * proc)
{
    AddUnitHp(proc->unit, -proc->damage);
}

STATIC_DECLAR const struct ProcCmd ProcScr_PostActionSelfHurt[] = {
    PROC_NAME("PostActionSelfHurt"),
    PROC_SLEEP(4),
    PROC_WHILE(PostActionWaitSelfHurtAnimDone),
    PROC_SLEEP(4),
    PROC_CALL(PostActionWaitSelfHurtReal),
    PROC_END
};

STATIC_DECLAR void PostActionSelfHurtCommon(ProcPtr parent, struct Unit * unit, int damage)
{
    struct ProcPostActionSelfHurt * proc;

    if (damage <= 0)
        return;

    EndAllMus();
    RefreshUnitSprites();
    HideUnitSprite(unit);

    proc = Proc_StartBlocking(ProcScr_PostActionSelfHurt, parent);
    proc->unit = unit;
    proc->damage = damage;
    proc->lock = GetGameClock();

    BeginUnitCritDamageAnim(unit, damage);
}

bool PostActionBattleActorSelfHurt(ProcPtr parent)
{
    struct Unit * unit = gActiveUnit;
    struct Unit * target = GetUnit(gActionData.targetIndex);
    int damage = 0;

    switch (gActionData.unitActionType) {
    case UNIT_ACTION_COMBAT:
#if defined(SID_GrislyWound) && (COMMON_SKILL_VALID(SID_GrislyWound))
        if (SkillTester(target, SID_GrislyWound))
        {
            int GrislyWoundDamage = unit->maxHP / 5;

            if (GrislyWoundDamage > unit->curHP)
                GrislyWoundDamage = unit->curHP - 1;

            damage += GrislyWoundDamage;
        }
#endif
        break;
    case UNIT_ACTION_STAFF:
#if defined(SID_Fury) && (COMMON_SKILL_VALID(SID_Fury))
        if (SkillTester(unit, SID_Fury))
            damage += 6;
#endif

#if defined(SID_FuryPlus) && (COMMON_SKILL_VALID(SID_FuryPlus))
        if (SkillTester(unit, SID_FuryPlus))
            damage += 8;
#endif

#if defined(SID_DoubleLion) && (COMMON_SKILL_VALID(SID_DoubleLion))
        if (SkillTester(unit, SID_DoubleLion) && (gBattleActorGlobalFlag.skill_activated_double_lion))
            damage += 1;
#endif

        break;
    };

    if (damage == 0)
        return false;

    if (damage >= GetUnitCurrentHp(unit))
        damage = GetUnitCurrentHp(unit) - 1;

    PostActionSelfHurtCommon(parent, unit, damage);
    return true;
}

bool PostActionBattleTargetSelfHurt(ProcPtr parent)
{
    struct Unit * unit = GetUnit(gActionData.targetIndex);
    struct Unit * actor = GetUnit(gActionData.subjectIndex);

    int damage = 0;

    if (!UNIT_ALIVE(gActiveUnit) || UNIT_STONED(gActiveUnit))
        return false;

    switch (gActionData.unitActionType) {
    case UNIT_ACTION_COMBAT:
#if defined(SID_PoisonStrike) && (COMMON_SKILL_VALID(SID_PoisonStrike))
        if (SkillTester(actor, SID_PoisonStrike))
        {
            int poisonStrikeDamage = unit->maxHP / 5;

            if (poisonStrikeDamage > unit->curHP)
                poisonStrikeDamage = unit->curHP - 1;

            damage += poisonStrikeDamage;
        }
#endif

#if defined(SID_GrislyWound) && (COMMON_SKILL_VALID(SID_GrislyWound))
        if (SkillTester(actor, SID_GrislyWound))
        {
            int GrislyWoundDamage = unit->maxHP / 5;

            if (GrislyWoundDamage > unit->curHP)
                GrislyWoundDamage = unit->curHP - 1;

            damage += GrislyWoundDamage;
        }
#endif
        break;
    case UNIT_ACTION_STAFF:
#if defined(SID_Fury) && (COMMON_SKILL_VALID(SID_Fury))
        if (SkillTester(unit, SID_Fury))
            damage += 6;
#endif

#if defined(SID_FuryPlus) && (COMMON_SKILL_VALID(SID_FuryPlus))
        if (SkillTester(unit, SID_FuryPlus))
            damage += 8;
#endif

        break;
    };

    if (damage == 0)
        return false;

    if (damage >= GetUnitCurrentHp(unit))
        damage = GetUnitCurrentHp(unit) - 1;

    PostActionSelfHurtCommon(parent, unit, damage);
    return true;
}
