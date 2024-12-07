#include <common-chax.h>
#include <battle-system.h>

#include <gaiden-magic.h>

/**
 * Battle generate
 */
STATIC_DECLAR void SetBattleActorWeaponGaidenBMag(struct BattleUnit *bu, int slot)
{
	struct GaidenMagicList *list = GetGaidenMagicList(gActiveUnit);

	Assert((slot >= CHAX_BUISLOT_GAIDEN_BMAG1) && (slot <= CHAX_BUISLOT_GAIDEN_BMAG7));

	bu->weaponSlotIndex = slot;
	bu->weapon = MakeNewItem(list->bmags[slot - CHAX_BUISLOT_GAIDEN_BMAG1]);
	bu->weaponBefore = bu->weapon;
	bu->weaponAttributes = GetItemAttributes(bu->weapon);
	bu->weaponType = GetItemType(bu->weapon);
	bu->canCounter = false;
}

STATIC_DECLAR void BattleGenerateGaidenBMagRealInternal(struct Unit *actor, struct Unit *target)
{
	InitBattleUnit(&gBattleActor, actor);
	InitBattleUnit(&gBattleTarget, target);

	gBattleStats.range = RECT_DISTANCE(
		gBattleActor.unit.xPos, gBattleActor.unit.yPos,
		gBattleTarget.unit.xPos, gBattleTarget.unit.yPos
	);

	SetBattleActorWeaponGaidenBMag(&gBattleActor, gActionData.itemSlotIndex);
	SetBattleUnitWeapon(&gBattleTarget, BU_ISLOT_AUTO);

	BattleInitTargetCanCounter();
	BattleApplyWeaponTriangleEffect(&gBattleActor, &gBattleTarget);

	DisableAllLightRunes();

	SetBattleUnitTerrainBonusesAuto(&gBattleActor);
	SetBattleUnitTerrainBonusesAuto(&gBattleTarget);
	BattleGenerate(actor, target);
	EnableAllLightRunes();

	BattleUnitTargetCheckCanCounter(&gBattleTarget);
	BattleUnitTargetSetEquippedWeapon(&gBattleTarget);

	if (gBattleTarget.unit.index) {
		BattleApplyExpGains();
		PidStatsRecordBattleRes();

		PidStatsAddBattleAmt(actor);
		PidStatsAddBattleAmt(target);
	}
}

STATIC_DECLAR void BattleGenerateGaidenBMagSimulationInternal(struct Unit *actor, struct Unit *target, int x, int y)
{
	InitBattleUnit(&gBattleActor, actor);
	InitBattleUnit(&gBattleTarget, target);

	gBattleActor.unit.xPos = x;
	gBattleActor.unit.yPos = y;

	gBattleStats.range = RECT_DISTANCE(
		gBattleActor.unit.xPos, gBattleActor.unit.yPos,
		gBattleTarget.unit.xPos, gBattleTarget.unit.yPos
	);

	SetBattleActorWeaponGaidenBMag(&gBattleActor, gActionData.itemSlotIndex);
	SetBattleUnitWeapon(&gBattleTarget, BU_ISLOT_AUTO);

	BattleInitTargetCanCounter();
	BattleApplyWeaponTriangleEffect(&gBattleActor, &gBattleTarget);

	DisableAllLightRunes();

	SetBattleUnitTerrainBonusesAuto(&gBattleActor);
	SetBattleUnitTerrainBonusesAuto(&gBattleTarget);
	BattleGenerate(actor, target);
	EnableAllLightRunes();
}

void BattleGenerateGaidenBMagSimulation(struct Unit *actor, struct Unit *target, int x, int y)
{
	gBattleStats.config = BATTLE_CONFIG_SIMULATE;
	BattleGenerateGaidenBMagSimulationInternal(actor, target, x, y);
}

void BattleGenerateGaidenBMagReal(struct Unit *actor, struct Unit *target)
{
	gBattleStats.config = BATTLE_CONFIG_REAL;
	BattleGenerateGaidenBMagRealInternal(actor, target);
}

/**
 * Action
 */
bool ActionGaidenBMagCombat(ProcPtr proc)
{
	struct Unit *uactor  = GetUnit(gActionData.subjectIndex);
	struct Unit *utarget = GetUnit(gActionData.targetIndex);

	gBattleActor.hasItemEffectTarget = false;

	if (!utarget)
		InitObstacleBattleUnit();

	BattleGenerateGaidenBMagReal(uactor, utarget);
	Proc_StartBlocking(sProcScr_CombatAction, proc);
	return false;
}
