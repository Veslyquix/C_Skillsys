#include "common-chax.h"
#include "kernel-lib.h"
#include "skill-system.h"
#include "constants/skills.h"
#include "battle-system.h"
#include "unit-expa.h"

extern void ForEachAdjacentUnit(int x, int y, void (*)(struct Unit *));

//! FE8U: 0x080B1F64
LYN_REPLACE_CHECK(SetGameOption);
void SetGameOption(u8 index, u8 newValue)
{

    switch (index)
    {
    case GAME_OPTION_ANIMATION:
        switch (newValue)
        {
        case 0:
            gPlaySt.config.animationType = 0;
            return;

        case 1:
            gPlaySt.config.animationType = 3;
            return;

        case 2:
            gPlaySt.config.animationType = 1;
            return;

        case 3:
            gPlaySt.config.animationType = 2;
            return;
        }

        // fallthrough

    case GAME_OPTION_TERRAIN:
        gPlaySt.config.disableTerrainDisplay = newValue;

        break;

    case GAME_OPTION_UNIT:
        gPlaySt.config.unitDisplayType = newValue;

        break;

    case GAME_OPTION_AUTOCURSOR:
        gPlaySt.config.autoCursor = newValue;

        break;

    case GAME_OPTION_TEXT_SPEED:
        gPlaySt.config.textSpeed = newValue;

        break;

    case GAME_OPTION_GAME_SPEED:
        gPlaySt.config.gameSpeed = newValue;

        break;

    case GAME_OPTION_MUSIC:
        gPlaySt.config.disableBgm = newValue;

        break;

    case GAME_OPTION_SOUND_EFFECTS:
        gPlaySt.config.disableSoundEffects = newValue;

        break;

    case GAME_OPTION_WINDOW_COLOR:
        gPlaySt.config.windowColor = newValue;

        break;

    case GAME_OPTION_COMBAT:
        gPlaySt.config.battleForecastType = newValue;

        break;

    case GAME_OPTION_SUBTITLE_HELP:
        gPlaySt.config.noSubtitleHelp = newValue;

        break;

    case GAME_OPTION_AUTOEND_TURNS:
        gPlaySt.config.disableAutoEndTurns = newValue;

        break;

    case GAME_OPTION_UNIT_COLOR:
        gPlaySt.config.unitColor = newValue;

        break;

    case GAME_OPTION_OBJECTIVE:
        gPlaySt.config.disableGoalDisplay = newValue;

        break;

    case GAME_OPTION_CONTROLLER:
        gPlaySt.config.controller = newValue;

        break;

    case GAME_OPTION_RANK_DISPLAY:
        gPlaySt.config.rankDisplay = newValue;

        break;
    }

    return;
}

LYN_REPLACE_CHECK(TryAddUnitToTradeTargetList);
void TryAddUnitToTradeTargetList(struct Unit *unit)
{

    /**
     *  With capture, a unit should be able to trade with rescued enemies
     */
    if (
        !IsSameAllegiance(gSubjectUnit->index, unit->index) &&
#if (defined(SID_Capture) && (COMMON_SKILL_VALID(SID_Capture)))
        !SkillTester(gSubjectUnit, SID_Capture)
#endif
    )
    {
        return;
    }

    if (gSubjectUnit->pClassData->number == CLASS_PHANTOM || unit->pClassData->number == CLASS_PHANTOM)
    {
        return;
    }

    if (unit->statusIndex != UNIT_STATUS_BERSERK)
    {

        if (gSubjectUnit->items[0] != 0 || unit->items[0] != 0)
        {

            if (!(UNIT_CATTRIBUTES(unit) & CA_SUPPLY))
            {
                AddTarget(unit->xPos, unit->yPos, unit->index, 0);
            }
        }
    }

    if (unit->state & US_RESCUING)
    {
        struct Unit *rescue = GetUnit(unit->rescue);

        if (UNIT_FACTION(rescue) != FACTION_BLUE)
        {
            return;
        }

        if (gSubjectUnit->items[0] == 0 && rescue->items[0] == 0)
        {
            return;
        }

        AddTarget(unit->xPos, unit->yPos, rescue->index, 0);
    }

    AddTarget(unit->xPos, unit->yPos, unit->index, 0);

    return;
}

LYN_REPLACE_CHECK(MakeTradeTargetList);
void MakeTradeTargetList(struct Unit *unit)
{
    int x = unit->xPos;
    int y = unit->yPos;

    gSubjectUnit = unit;

    BmMapFill(gBmMapRange, 0);
    ForEachAdjacentUnit(x, y, TryAddUnitToTradeTargetList);

    if (gSubjectUnit->state & US_RESCUING)
    {
        int count = GetSelectTargetCount();
        TryAddUnitToTradeTargetList(GetUnit(gSubjectUnit->rescue));

        if (count != GetSelectTargetCount())
        {
            GetTarget(count)->x = gSubjectUnit->xPos;
            GetTarget(count)->y = gSubjectUnit->yPos;
        }
    }

    return;
}

//! FE8U = 0x08032728
LYN_REPLACE_CHECK(KillUnitOnCombatDeath);
void KillUnitOnCombatDeath(struct Unit *unitA, struct Unit *unitB)
{
    if (GetUnitCurrentHp(unitA) != 0)
    {
        return;
    }

#if (defined(SID_Capture) && (COMMON_SKILL_VALID(SID_Capture)))
    // CheckBitUES(unitB, UES_BIT_CAPTURE_SKILL_USED)
    if (SkillTester(unitB, SID_Capture) && unitB->_u3A == 8)
    {
        UnitRescue(unitB, unitA);
        HideUnitSprite(unitA);
        // ClearBitUES(unitB, UES_BIT_CAPTURE_SKILL_USED);
        unitB->_u3A = 0;
        return;
    }
#endif

    PidStatsRecordDefeatInfo(unitA->pCharacterData->number, unitB->pCharacterData->number, DEFEAT_CAUSE_COMBAT);

    UnitKill(unitA);

    return;
}

LYN_REPLACE_CHECK(TryAddUnitToRescueTargetList);
void TryAddUnitToRescueTargetList(struct Unit *unit)
{

    if (!AreUnitsAllied(gSubjectUnit->index, unit->index))
    {
        return;
    }

    if (gSubjectUnit->pClassData->number == CLASS_PHANTOM || unit->pClassData->number == CLASS_PHANTOM)
    {
        return;
    }

    if (unit->statusIndex == UNIT_STATUS_BERSERK)
    {
        return;
    }

    if (unit->state & (US_RESCUING | US_RESCUED))
    {
        return;
    }

    if (!CanUnitRescue(gSubjectUnit, unit))
    {
        return;
    }

    AddTarget(unit->xPos, unit->yPos, unit->index, 0);

    return;
}

LYN_REPLACE_CHECK(UnitDrop);
void UnitDrop(struct Unit *actor, int xTarget, int yTarget)
{
    struct Unit *target = GetUnit(actor->rescue);

    actor->state = actor->state & ~(US_RESCUING | US_RESCUED);
    target->state = target->state & ~(US_RESCUING | US_RESCUED | US_HIDDEN);

    if (UNIT_FACTION(target) == gPlaySt.faction)
        target->state |= US_UNSELECTABLE; // TODO: US_GRAYED

    actor->rescue = 0;
    target->rescue = 0;

    target->xPos = xTarget;
    target->yPos = yTarget;

    /**
     * If we've captured an enemy, dropping them will kill them immediately
     */
    if (target->curHP == 0)
    {
        PidStatsRecordDefeatInfo(target->pCharacterData->number, actor->pCharacterData->number, DEFEAT_CAUSE_COMBAT);
        UnitKill(target);
    }
}