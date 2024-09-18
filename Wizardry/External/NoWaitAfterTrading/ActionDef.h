#ifndef UNIT_ACTION_DEF_H
#define UNIT_ACTION_DEF_H

/*
 * Unit Actions
 */
#define UNIT_ACTION_WAIT 0x01
#define UNIT_ACTION_COMBAT 0x02
#define UNIT_ACTION_STAFF 0x03
#define UNIT_ACTION_DANCE 0x04
#define UNIT_ACTION_STEAL 0x06
#define UNIT_ACTION_SUMMON 0x07
#define UNIT_ACTION_SUMMON_DK 0x08
#define UNIT_ACTION_RESCUE 0x09
#define UNIT_ACTION_DROP 0x0A
#define UNIT_ACTION_TAKE 0x0B
#define UNIT_ACTION_GIVE 0x0C
#define UNIT_ACTION_TALK 0x0E
#define UNIT_ACTION_SUPPORT 0x0F
#define UNIT_ACTION_VISIT 0x10
#define UNIT_ACTION_SEIZE 0x11
#define UNIT_ACTION_DOOR 0x12
#define UNIT_ACTION_CHEST 0x14
#define UNIT_ACTION_PICK 0x15
#define UNIT_ACTION_SHOPPED 0x17
#define UNIT_ACTION_ARENA 0x19
#define UNIT_ACTION_USE_ITEM 0x1A
#define UNIT_ACTION_TRADED 0x1B
#define UNIT_ACTION_TRADED_SUPPLY 0x1C
#define UNIT_ACTION_TRADED_1D 0x1D
#define UNIT_ACTION_TRAPPED 0x1E
#define UNIT_ACTION_RIDE_BALLISTA 0x21
#define UNIT_ACTION_EXIT_BALLISTA 0x22

/**
 * BM masks
 */
#define BM_TAKEN_ACTION_TAKE (1 << 0)
#define BM_TAKEN_ACTION_TRADE (1 << 1)
#define BM_TAKEN_ACTION_SUPPLY (1 << 2)
#define BM_TAKEN_ACTION_BALLISTA (1 << 3)

#endif
