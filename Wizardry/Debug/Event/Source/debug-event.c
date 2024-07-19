#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"

/**
 * Udefs
 */
static const struct REDA REDA_Eirika[] = {
    {
        .x = 14,
        .y = 27,
        .b = -1,
    }
};

static const struct REDA REDA_Seth[] = {
    {
        .x = 15,
        .y = 27,
        .b = -1,
        .delayFrames = 8,
    }
};

static const struct REDA REDA_Myrrh[] = {
    {
        .x = 13,
        .y = 25,
        .b = -1,
        .delayFrames = 16,
    }
};

static const struct REDA REDA_Tana[] = {
    {
        .x = 16,
        .y = 21,
        .b = -1,
        .delayFrames = 32,
    }
};

static const struct REDA REDA_Vanessa[] = {
    {
        .x = 17,
        .y = 19,
        .b = -1,
        .delayFrames = 48,
    }
};

static const struct REDA REDA_Ephraim[] = {
    {
        .x = 17,
        .y = 28,
        .b = -1,
    }
};

static const struct UnitDefinition UnitDef_Ally1[] = {
    {
        .charIndex = CHARACTER_EIRIKA,
        .classIndex = CLASS_EIRIKA_LORD,
        .allegiance = FACTION_ID_BLUE,
        .autolevel = true,
        .level = 10,
        .xPosition = 16,
        .yPosition = 29,
        .redaCount = 1,
        .redas = REDA_Eirika,
        .items = {
            ITEM_SWORD_RAPIER,
            ITEM_VULNERARY,
        },
    },
    {
        .charIndex = CHARACTER_SETH,
        .classIndex = CLASS_PALADIN,
        .autolevel = true,
        .level = 10,
        .xPosition = 16,
        .yPosition = 29,
        .redaCount = 1,
        .redas = REDA_Seth,
        .items = {
            ITEM_SWORD_SILVER,
            ITEM_LANCE_SILVER,
            ITEM_ELIXIR
        },
    },
    {
        .charIndex = CHARACTER_MYRRH,
        .classIndex = CLASS_MANAKETE_MYRRH,
        .allegiance = FACTION_ID_BLUE,
        .autolevel = true,
        .level = 15,
        .xPosition = 16,
        .yPosition = 29,
        .redaCount = 1,
        .redas = REDA_Myrrh,
        .items = {
            ITEM_DIVINESTONE,
            ITEM_VULNERARY,
        },
    },
    {
        .charIndex = CHARACTER_TANA,
        .classIndex = CLASS_PEGASUS_KNIGHT,
        .autolevel = true,
        .level = 10,
        .xPosition = 19,
        .yPosition = 15,
        .redaCount = 1,
        .redas = REDA_Tana,
        .items = {
            ITEM_LANCE_SLIM,
            ITEM_VULNERARY
        },
    },
    {
        .charIndex = CHARACTER_VANESSA,
        .classIndex = CLASS_PEGASUS_KNIGHT,
        .autolevel = true,
        .level = 10,
        .xPosition = 19,
        .yPosition = 15,
        .redaCount = 1,
        .redas = REDA_Vanessa,
        .items = {
            ITEM_LANCE_SLIM,
            ITEM_VULNERARY
        },
    },
    {
        .charIndex = CHARACTER_EPHRAIM,
        .classIndex = CLASS_EPHRAIM_LORD,
        .autolevel = true,
        .level = 10,
        .xPosition = 16,
        .yPosition = 29,
        .redaCount = 1,
        .redas = REDA_Ephraim,
        .items = {
            ITEM_LANCE_IRON,
            ITEM_VULNERARY
        },
    },
    {}
};

static const struct REDA REDA_ONeill[] = {
    {
        .x = 16,
        .y = 19,
        .b = -1,
    }
};

static const struct REDA REDA_Saar[] = {
    {
        .x = 10,
        .y = 25,
        .b = -1,
    }
};

static const struct UnitDefinition UnitDef_Enemy1[] = {
    {
        .charIndex = CHARACTER_ONEILL,
        .classIndex = CLASS_FIGHTER,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 4,
        .xPosition = 12,
        .yPosition = 21,
        .redaCount = 1,
        .redas = REDA_ONeill,
        .items = {
            ITEM_AXE_IRON,
        },
        .ai = { 0, 4, 9, 0 },
    },
    {
        .charIndex = CHARACTER_SAAR,
        .classIndex = CLASS_ARMOR_KNIGHT,
        .autolevel = true,
        .allegiance = FACTION_ID_RED,
        .level = 10,
        .xPosition = 4,
        .yPosition = 22,
        .redaCount = 1,
        .redas = REDA_Saar,
        .items = {
            ITEM_LANCE_IRON,
        },
        .ai = { 0, 4, 9, 0 },
    },
    {}
};

/**
 * Main events
 */
static const EventScr EventScr_Beginning[] = {
    LOAD1(0x1, UnitDef_Ally1)
    ENUN
    LOAD1(0x1, UnitDef_Enemy1)
    ENUN

    Evt_AddSkill(SID_Obstruct, CHARACTER_SAAR)
    Evt_AddSkill(SID_Aerobatics, CHARACTER_MYRRH)
    Evt_AddSkill(SID_FlierGuidance, CHARACTER_TANA)
    Evt_AddSkill(SID_FlierGuidance, CHARACTER_VANESSA)

    // PREP
    CALL(EventScr_08591FD8)

    NoFade
    ENDA
};

static const EventScr EventScr_Ending[] = {
    MNC2(1)
    ENDA
};

/**
 * Misc events
 */
static const EventListScr EventScr_Talk_EirikaSeth[] = {
    ConvoEvent(0xB32)
};

/**
 * Event list
 */
static const EventListScr EventListScr_Turn[] = {
    END_MAIN
};

static const EventListScr EventListScr_Character[] = {
    CharacterEventBothWays(EVFLAG_TMP(7), EventScr_Talk_EirikaSeth, CHARACTER_EIRIKA, CHARACTER_SETH)
    END_MAIN
};

static const EventListScr EventListScr_Location[] = {
    END_MAIN
};

static const EventListScr EventListScr_Misc[] = {
    DefeatAll(EventScr_Ending)
    CauseGameOverIfLordDies
    END_MAIN
};

static const EventListScr EventListScr_SelectUnit[] = {
    END_MAIN
};

static const EventListScr EventListScr_SelectDestination[] = {
    END_MAIN
};

static const EventListScr EventListScr_UnitMove[] = {
    END_MAIN
};

static void const * const EventListScr_Tutorial[] = {
    NULL
};

static const u8 TrapData_ThisEvent[] = {
    TRAP_NONE
};

static const u8 TrapData_ThisEventHard[] = {
    TRAP_NONE
};

const struct ChapterEventGroup ThisEvent = {
    .turnBasedEvents               = EventListScr_Turn,
    .characterBasedEvents          = EventListScr_Character,
    .locationBasedEvents           = EventListScr_Location,
    .miscBasedEvents               = EventListScr_Misc,
    .specialEventsWhenUnitSelected = EventListScr_SelectUnit,
    .specialEventsWhenDestSelected = EventListScr_SelectDestination,
    .specialEventsAfterUnitMoved   = EventListScr_UnitMove,
    .tutorialEvents                = EventListScr_Tutorial,

    .traps            = TrapData_ThisEvent,
    .extraTrapsInHard = TrapData_ThisEventHard,

    .playerUnitsInNormal = UnitDef_Ally1,
    .playerUnitsInHard   = UnitDef_Ally1,

    .playerUnitsChoice1InEncounter = NULL,
    .playerUnitsChoice2InEncounter = NULL,
    .playerUnitsChoice3InEncounter = NULL,

    .enemyUnitsChoice1InEncounter = NULL,
    .enemyUnitsChoice2InEncounter = NULL,
    .enemyUnitsChoice3InEncounter = NULL,

    .beginningSceneEvents = EventScr_Beginning,
    .endingSceneEvents    = EventScr_Ending,
};
