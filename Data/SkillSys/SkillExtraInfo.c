#include "common-chax.h"
#include "skill-system.h"
#include "constants/skills.h"

const struct SkillExtraInfo gSkillExtraInfo[MAX_SKILL_NUM + 1] = {
    [SID_HpBonus] = {{ 2 }},
    [SID_StrBonus] = {{ 2 }},
    [SID_MagBonus] = {{ 2 }},
    [SID_SklBonus] = {{ 2 }},
    [SID_SpdBonus] = {{ 2 }},
    [SID_LckBonus] = {{ 2 }},
    [SID_DefBonus] = {{ 2 }},
    [SID_ResBonus] = {{ 2 }},
    [SID_MovBonus] = {{ 2 }},

    [SID_DefiantStr] = {{ 7 }},
    [SID_DefiantMag] = {{ 7 }},
    [SID_DefiantSkl] = {{ 7 }},
    [SID_DefiantSpd] = {{ 7 }},
    [SID_DefiantLck] = {{ 7 }},
    [SID_DefiantDef] = {{ 7 }},
    [SID_DefiantRes] = {{ 7 }},
    [SID_DefiantCrit] = {{ 50 }},
    [SID_DefiantAvoid] = {{ 30 }},

    [SID_PushStrength] = {{ 5 }},
    [SID_PushMagic] = {{ 5 }},
    [SID_PushSkill] = {{ 5 }},
    [SID_PushSpeed] = {{ 5 }},
    [SID_PushLuck] = {{ 5 }},
    [SID_PushDefense] = {{ 5 }},
    [SID_PushResistance] = {{ 5 }},
    [SID_PushMovement] = {{ 5 }},
    [SID_PushSpectrum] = {{ 5 }},

    [SID_Fury] = {{ 3 }},
    [SID_FuryPlus] = {{ 4 }},
    [SID_EvenFooted] = {{ 1 }},
    [SID_OddFooted] = {{ 1 }},
    [SID_DefenseBoost] = {{ 6 }},
    [SID_LuckBoost] = {{ 6 }},
    [SID_MagicBoost] = {{ 6 }},
    [SID_MoveBoost] = {{ 6 }},
    [SID_ResistanceBoost] = {{ 6 }},
    [SID_SpeedBoost] = {{ 6 }},
    [SID_SkillBoost] = {{ 6 }},
    [SID_StrengthBoost] = {{ 6 }},
    [SID_SpectrumBoost] = {{ 6 }},
    [SID_LuckySeven] = {{ 7 }},
    [SID_Poise] = {{ 1 }},
    [SID_ShrewdPotential] = {{ 1 }},

    [SID_FortressDef] = {{ -3, +5 }},
    [SID_FortressRes] = {{ -3, +5 }},
    [SID_LifeAndDeath] = {{ 5, -5 }},

    [SID_CritSword] = {{ 10 }},
    [SID_CritAxe] = {{ 10 }},
    [SID_CritLance] = {{ 10 }},
    [SID_CritBow] = {{ 10 }},

    [SID_FaireSword] = {{ 5 }},
    [SID_FaireLance] = {{ 5 }},
    [SID_FaireAxe] = {{ 5 }},
    [SID_FaireBow] = {{ 5 }},
    [SID_FaireBMag] = {{ 5 }},
    [SID_FaireAnima] = {{ 5 }},
    [SID_FaireLight] = {{ 5 }},
    [SID_FaireDark] = {{ 5 }},

    [SID_Avoid] = {{ 10 }},
    [SID_AvoidSword] = {{ 20 }},
    [SID_Vigilance] = {{ 20 }},
    [SID_RuinedBlade] = {{ -5, +5, +5 }},
    [SID_RuinedBladePlus] = {{ 5, 5, 1 }},
    [SID_HeavyBlade] = {{ 15 }},
    [SID_FlashingBlade] = {{ 15 }},
    [SID_HeavyBladePlus] = {{ 5, 25 }},
    [SID_FlashingBladePlus] = {{ 3, 25 }},

    [SID_BattleVeteran] = {{ 1, 5 }},
    [SID_ElbowRoom] = {{ 3 }},
    [SID_ChaosStyle] = {{ 3 }},
    [SID_ArcaneBlade] = {{ 3 }},
    [SID_QuickDraw] = {{ 4 }},
    [SID_KeenFighter] = {{ 50 }},
    [SID_DragonSkin] = {{ 50 }},
    [SID_WaterBoost] = {{ 6, 3 }},
    [SID_EarthBoost] = {{ 6, 3 }},
    [SID_WindBoost] = {{ 6, 3 }},
    [SID_FireBoost] = {{ 6, 3 }},
    [SID_Pursuit] = {{ 2 }},
    [SID_Patience] = {{ 10 }},
    [SID_StrongRiposte] = {{ 3 }},
    [SID_Perfectionist] = {{ 15, 15 }},
    [SID_WindDisciple] = {{ 10, 10 }},
    [SID_Pragmatic] = {{ 3, 1 }},
    [SID_Chivalry] = {{ 2, 2 }},
    [SID_Charge] = {{ 1 }},
    [SID_FieryBlood] = {{ 4 }},
    [SID_Wrath] = {{ 20 }},
    [SID_OutdoorFighter] = {{ 10, 10 }},
    [SID_KnightAspirant] = {{ 2, 15 }},
    // [SID_Outrider] = {{ 1, 3 }},
    [SID_EvenRhythm] = {{ 10, 10 }},
    [SID_OddRhythm] = {{ 10, 10 }},
    [SID_Puissance] = {{ 3 }},
    [SID_Prescience] = {{ 15, 15 }},
    [SID_SilentPride] = {{ 2, 2 }},
    [SID_RightfulKing] = {{ 10 }},
    [SID_RightfulGod] = {{ 30 }},
    [SID_Hero] = {{ 30 }},
    [SID_Guts] = {{ 5 }},
    [SID_StrongCon] = {{ 5, 5 }},
    [SID_Spurn] = {{ 5, 4 }},
    [SID_Astra] = {{ 4, 50 }},
    [SID_Aether] = {{ 80 }},
    [SID_DragonFang] = {{ 50 }},
    [SID_Colossus] = {{ 20 }},
    [SID_Impale] = {{ 30 }},
    [SID_DivinePulse] = {{ 30 }},
    [SID_Multiscale] = {{ 50 }},
    [SID_Expertise] = {{ 50 }},

    [SID_BlowDarting] = {{ 6 }},
    [SID_BlowDeath] = {{ 6 }},
    [SID_BlowArmored] = {{ 6 }},
    [SID_BlowFiendish] = {{ 6 }},
    [SID_BlowWarding] = {{ 6 }},
    [SID_BlowDuelist] = {{ 20 }},
    [SID_BlowUncanny] = {{ 30 }},
    [SID_BlowKilling] = {{ 20 }},

    [SID_StanceBracing] = {{ 4 }},
    [SID_StanceDarting] = {{ 6 }},
    [SID_StanceFierce] = {{ 6 }},
    [SID_StanceKestrel] = {{ 4, 4 }},
    [SID_StanceMirror] = {{ 4, 4 }},
    [SID_StanceReady] = {{ 4, 4 }},
    [SID_StanceSteady] = {{ 6 }},
    [SID_StanceSturdy] = {{ 4, 4 }},
    [SID_StanceSwift] = {{ 4, 4 }},
    [SID_StanceWarding] = {{ 6 }},
    [SID_StanceSpectrum] = {{ 2, 2, 2 }},

    [SID_RangeBonusBMag1] = {{ 1 }},
    [SID_RangeBonusBMag2] = {{ 2 }},
    [SID_RangeBonusBow1] = {{ 1 }},
    [SID_RangeBonusBow2] = {{ 2 }},
    [SID_StaffSavant] = {{ 1 }},
    [SID_HighGround] = {{ 2 }},

    [SID_BattleRange_Todo1] = {{ 10 }},
    [SID_BattleRange_Todo2] = {{ 7 }},
    [SID_BattleRange_Todo3] = {{ 5 }},

    [SID_SavageBlow] = {{ 20 }},
    [SID_BreathOfLife] = {{ 20 }},
    [SID_Thunderstorm] = {{ 10 }},
    [SID_SoulSap] = {{ 10 }},

    [SID_Renewal] = {{ 30 }},
    [SID_Forager] = {{ 20 }},
    [SID_RainDish] = {{ 30 }},
    [SID_Relief] = {{ 20 }},
    [SID_Camaraderie] = {{ 10 }},
    [SID_Amaterasu] = {{ 20 }},

    [SID_Anathema] = {{ 10, 10 }},
    [SID_Bond] = {{ 2, 10 }},
    [SID_Charm] = {{ 3 }},
    [SID_Intimidate] = {{ 10 }},
    [SID_Tantivy] = {{ 10, 10 }},
    [SID_Focus] = {{ 10 }},
    [SID_Hex] = {{ 15 }},
    [SID_Infiltrator] = {{ 3, 15 }},
    [SID_Inspiration] = {{ 2, 2 }},
    [SID_DivinelyInspiring] = {{ 3, 1 }},
    [SID_VoiceOfPeace] = {{ 2 }},
    [SID_Peacebringer] = {{ 2 }},
    [SID_BloodTide] = {{ 5, 5 }},
    [SID_WhitePool] = {{ 5, 5 }},
    [SID_NightTide] = {{ 5 }},

    [SID_DriveStr] = {{ 4 }},
    [SID_DriveMag] = {{ 4 }},
    [SID_DriveSpd] = {{ 4 }},
    [SID_DriveDef] = {{ 4 }},
    [SID_DriveRes] = {{ 4 }},

    [SID_Charisma] = {{ 10, 10 }},
    [SID_Gentilhomme] = {{ 2 }},
    [SID_Demoiselle] = {{ 2 }},
    [SID_LilysPoise] = {{ 1, 3 }},
    [SID_Daunt] = {{ 5, 5 }},
    [SID_MaleficAura] = {{ 2}},

    [SID_SpurStr] = {{ 4 }},
    [SID_SpurMag] = {{ 4 }},
    [SID_SpurDef] = {{ 4 }},
    [SID_SpurRes] = {{ 4 }},
    [SID_SpurSpd] = {{ 4 }},
    [SID_Solidarity] = {{ 10, 10 }},

    [SID_Aptitude] = {{ 20 }},

    [SID_Assist] = {{ 5 }},
    [SID_Synergism] = {{ 3 }},
    [SID_Skyguard] = {{ 4 }},
    [SID_Horseguard] = {{ 4 }},
    [SID_Armorboost] = {{ 4, 4 }},
    [SID_Teleportation] = {{ 50 }},
    [SID_Provoke] = {{ 50 }},
    [SID_Crit] = {{ 15 }},
    [SID_InfinityEdge] = {{ 100 }},
    [SID_WatchfulEye] = {{ 20 }},
    [SID_AversaNight] = {{ 3 }},
    [SID_LightWeight] = {{ 3 }},
    [SID_Analytic] = {{ 4, 10, 5 }},
    [SID_Lifetaker] = {{ 25 }},
    [SID_MysticBoost] = {{ 6 }},
    [SID_GuardBearing] = {{ 50 }},
    [SID_YuneWhispers] = {{ 3 }},
    [SID_CounterRoar] = {{ 30, 70 }},
    [SID_Gambit] = {{ 50 }},
    [SID_MagicGambit] = {{ 50 }},
    [SID_BeastAssault] = {{ 40 }},
    [SID_LightAndDark] = {{ 5, 5, 5, 5 }},
    [SID_Bushido] = {{ 4, 7 }},
    [SID_DragonWall] = {{ 4 }},
    [SID_DragonWarth] = {{ 20, 20, }},
    [SID_BlueLionRule] = {{ 4 }},
    [SID_CrusaderWard] = {{ 80 }},
    [SID_Vanity] = {{ 2, 10 }},
    [SID_ShortShield] = {{ 6 }},
    [SID_Opportunist] = {{ 4 }},
    [SID_TowerShield] = {{ 6 }},
    [SID_StunningSmile] = {{ 6 }},
    [SID_Trample] = {{ 5 }},
    [SID_Loyalty] = {{ 15, 3 }},
    [SID_HolyAura] = {{ 1, 5, 5, 5 }},
    [SID_BlueFlame] = {{ 2, 2 }},
    [SID_DancingBlade] = {{ 4, 2 }},
    [SID_QuickBurn] = {{ 15 }},
    [SID_SlowBurn] = {{ 15 }},
    [SID_NaturalCover] = {{ 3 }},
    [SID_FlierGuidance] = {{ 3 }},
    [SID_Guidance] = {{ 2 }},
    [SID_SoaringGuidance] = {{ 1 }},
    [SID_FlierFormation] = {{ 3 }},
    [SID_Aerobatics] = {{ 2 }},
    [SID_SoaringWings] = {{ 1 }},
    [SID_MageSlayer] = {{ 2, 10 }},
    [SID_SolarPower] = {{ 25 }},
    [SID_Obstruct] = {{ 25, 1 }},
    [SID_DetailedReport] = {{ 50, 2, 2 }},
    [SID_AirRaidAttack] = {{ 5 }},
    [SID_AirRaidAvoid] = {{ 15 }},
    [SID_AirRaidCrit] = {{ 15 }},
    [SID_AirRaidDefense] = {{ 5 }},
    [SID_AirRaidHit] = {{ 15 }},
    [SID_AirRaidResistance] = {{ 5 }},
    [SID_AirRaidSpeed] = {{ 5 }},
    [SID_HealingFocus] = {{ 50 }},
    [SID_LightRune] = {{ 20 }},
    [SID_Mine] = {{ 20 }},
    [SID_RallyDefense] = {{ 4 }},
    [SID_RallyLuck] = {{ 4 }},
    [SID_RallyMagic] = {{ 4 }},
    [SID_RallyMovement] = {{ 4 }},
    [SID_RallyResistance] = {{ 4 }},
    [SID_RallySkill] = {{ 4 }},
    [SID_RallySpeed] = {{ 4 }},
    [SID_RallyStrength] = {{ 4 }},
    // [SID_SteadyBrawler] = {{ 4 }},
    [SID_CloseCombat] = {{ 2 }},
    [SID_Barricade] = {{ 50 }},
    [SID_BarricadePlus] = {{ 50 }},
    [SID_Pursuer] = {{ 5, 4 }},
    [SID_GoldDigger] = {{ 100 }},
    [SID_EffectSpore] = {{ 50 }},
    [SID_DominantArm] = {{ 50 }},
    [SID_FranticSwing] = {{ 50 }},
    [SID_CriticalOverload] = {{ 3 }},
    [SID_VigorDance] = {{ 2, 2}},
    [SID_Accost] = {{ 20 }},
    [SID_Mentorship] = {{ 20 }},
    [SID_HeavyMetal] = {{ 5 }},

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealDefense] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealLuck] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealMagic] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealResistance] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealSkill] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealSpeed] = {{ 6 }},
#endif

#if (defined(SID_SealDefense) && COMMON_SKILL_VALID(SID_SealDefense))
    [SID_SealStrength] = {{ 6 }},
#endif
};
