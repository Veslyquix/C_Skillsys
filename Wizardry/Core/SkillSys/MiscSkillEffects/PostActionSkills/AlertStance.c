#include "common-chax.h"
#include "debuff.h"
#include "skill-system.h"
#include "constants/skills.h"

bool PostActionAlertStance(ProcPtr parent)
{
    struct Unit * unit = gActiveUnit;

    if (!UNIT_ALIVE(gActiveUnit) || UNIT_STONED(gActiveUnit))
        return false;

    if (gActionData.unitActionType == UNIT_ACTION_WAIT)
    {
#if defined(SID_AlertStancePlus) && (COMMON_SKILL_VALID(SID_AlertStancePlus))
        if (SkillTester(unit, SID_AlertStancePlus))
        {
            SetUnitStatus(unit, NEW_UNIT_STATUS_AVOID_PLUS);
            EndAllMus();
            StartStatusHealEffect(unit, parent);
            return true;
        }
#endif

#if defined(SID_AlertStance) && (COMMON_SKILL_VALID(SID_AlertStance))
        if (SkillTester(unit, SID_AlertStance))
        {
            SetUnitStatus(unit, NEW_UNIT_STATUS_AVOID);
            EndAllMus();
            StartStatusHealEffect(unit, parent);
            return true;
        }
#endif
    }
    return false;
}
