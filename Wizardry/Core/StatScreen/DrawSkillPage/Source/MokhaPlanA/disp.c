#include "common-chax.h"
#include "stat-screen.h"
#include "skill-system.h"

#define STAT_SKILL_NUM_MAX 8

void DrawSkillPage_MokhaPlanA(void)
{
    int i;
    const u8 text_id[8] = {
        STATSCREEN_TEXT_ITEM0,
        STATSCREEN_TEXT_ITEM1,
        STATSCREEN_TEXT_ITEM2,
        STATSCREEN_TEXT_ITEM3,
        STATSCREEN_TEXT_ITEM4,
        STATSCREEN_TEXT_SUPPORT0,
        STATSCREEN_TEXT_SUPPORT1,
        STATSCREEN_TEXT_SUPPORT2,
    };

    struct SkillList * list = GetUnitSkillList(gStatScreen.unit);

    DisplayWeaponExp(0, 1, 0x1, ITYPE_SWORD);
    DisplayWeaponExp(1, 1, 0x3, ITYPE_LANCE);
    DisplayWeaponExp(2, 1, 0x5, ITYPE_AXE);
    DisplayWeaponExp(3, 1, 0x7, ITYPE_BOW);

    DisplayWeaponExp(4, 1, 0x9, ITYPE_ANIMA);
    DisplayWeaponExp(5, 1, 0xB, ITYPE_LIGHT);
    DisplayWeaponExp(6, 1, 0xD, ITYPE_DARK);
    DisplayWeaponExp(7, 1, 0xF, ITYPE_STAFF);

    for (i = 0; i < STAT_SKILL_NUM_MAX; i++)
    {
        struct Text * text = &gStatScreen.text[text_id[i]];
        if (i >= list->amt)
            break;

        DrawIcon(gUiTmScratchA + TILEMAP_INDEX(8, 0x1 + 2 * i),
                 SKILL_ICON(list->sid[i]),
                 TILEREF(0, STATSCREEN_BGPAL_ITEMICONS));

        ClearText(text);

        PutDrawText(
            text,
            gUiTmScratchA + TILEMAP_INDEX(10, 0x1 + 2 * i),
            TEXT_COLOR_SYSTEM_WHITE, 0, 0,
            GetSkillNameStr(list->sid[i]));
    }
}


/* HelpBox API */
void HbPopuplate_SkillPageMokhaPlanA(struct HelpBoxProc * proc)
{
    struct SkillList * list = GetUnitSkillList(gStatScreen.unit);
    proc->mid = GetSkillDescMsg(list->sid[proc->info->mid]);
}

void HbRedirect_SkillPageMokhaPlanA(struct HelpBoxProc * proc)
{
    if (proc->info->mid < GetUnitSkillList(gStatScreen.unit)->amt)
        return;

    switch (proc->moveKey) {
    case DPAD_DOWN:
        TryRelocateHbDown(proc);
        break;

    case DPAD_UP:
        TryRelocateHbUp(proc);
        break;

    case DPAD_LEFT:
        TryRelocateHbLeft(proc);
        break;

    case DPAD_RIGHT:
    default:
        TryRelocateHbRight(proc);
        break;
    } // switch
}