/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Item_Scripts
SD%Complete: 100
SDComment: Items for a range of different items. See content below (in script)
SDCategory: Items
EndScriptData */

/* ContentData
item_nether_wraith_beacon(i31742)   Summons creatures for quest Becoming a Spellfire Tailor (q10832)
item_flying_machine(i34060, i34061)  Engineering crafted flying machines
item_gor_dreks_ointment(i30175)     Protecting Our Own(q10488)
item_only_for_flight                Items which should only useable while flying
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "Player.h"

/*#####
# item_only_for_flight
#####*/

enum OnlyForFlight
{
    SPELL_ARCANE_CHARGES    = 45072
};

class item_only_for_flight : public ItemScript
{
public:
    item_only_for_flight() : ItemScript("item_only_for_flight") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) override
    {
        uint32 itemId = item->GetEntry();
        bool disabled = false;

        //for special scripts
        switch (itemId)
        {
           case 24538:
                if (player->GetAreaId() != 3628)
                    disabled = true;
                    break;
           case 34489:
                if (player->GetZoneId() != 4080)
                    disabled = true;
                    break;
           case 34475:
                if (const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(SPELL_ARCANE_CHARGES))
                    Spell::SendCastResult(player, spellInfo, 1, SPELL_FAILED_NOT_ON_GROUND);
                    break;
        }

        // allow use in flight only
        if (player->IsInFlight() && !disabled)
            return false;

        // error
        player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, item, NULL);
        return true;
    }
};

/*#####
# item_nether_wraith_beacon
#####*/

class item_nether_wraith_beacon : public ItemScript
{
public:
    item_nether_wraith_beacon() : ItemScript("item_nether_wraith_beacon") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/) override
    {
        if (player->GetQuestStatus(10832) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* nether = player->SummonCreature(22408, player->GetPositionX(), player->GetPositionY()+20, player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                nether->AI()->AttackStart(player);

            if (Creature* nether = player->SummonCreature(22408, player->GetPositionX(), player->GetPositionY()-20, player->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                nether->AI()->AttackStart(player);
        }
        return false;
    }
};

/*#####
# item_gor_dreks_ointment
#####*/

class item_gor_dreks_ointment : public ItemScript
{
public:
    item_gor_dreks_ointment() : ItemScript("item_gor_dreks_ointment") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& targets) override
    {
        if (targets.GetUnitTarget() && targets.GetUnitTarget()->GetTypeId() == TYPEID_UNIT &&
            targets.GetUnitTarget()->GetEntry() == 20748 && !targets.GetUnitTarget()->HasAura(32578))
            return false;

        player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, item, NULL);
        return true;
    }
};

/*#####
# item_incendiary_explosives
#####*/

class item_incendiary_explosives : public ItemScript
{
public:
    item_incendiary_explosives() : ItemScript("item_incendiary_explosives") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const & /*targets*/) override
    {
        if (player->FindNearestCreature(26248, 15) || player->FindNearestCreature(26249, 15))
            return false;
        else
        {
            player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE, item, NULL);
            return true;
        }
    }
};

/*#####
# item_mysterious_egg
#####*/

class item_mysterious_egg : public ItemScript
{
public:
    item_mysterious_egg() : ItemScript("item_mysterious_egg") { }

    bool OnExpire(Player* player, ItemTemplate const* /*pItemProto*/) override
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 39883, 1); // Cracked Egg
        if (msg == EQUIP_ERR_OK)
            player->StoreNewItem(dest, 39883, true, Item::GenerateItemRandomPropertyId(39883));

        return true;
    }
};

/*#####
# item_disgusting_jar
#####*/

class item_disgusting_jar : public ItemScript
{
public:
    item_disgusting_jar() : ItemScript("item_disgusting_jar") { }

    bool OnExpire(Player* player, ItemTemplate const* /*pItemProto*/) override
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 44718, 1); // Ripe Disgusting Jar
        if (msg == EQUIP_ERR_OK)
            player->StoreNewItem(dest, 44718, true, Item::GenerateItemRandomPropertyId(44718));

        return true;
    }
};

/*#####
# item_pile_fake_furs
#####*/

enum PileFakeFur
{
    GO_CARIBOU_TRAP_1                                      = 187982,
    GO_CARIBOU_TRAP_2                                      = 187995,
    GO_CARIBOU_TRAP_3                                      = 187996,
    GO_CARIBOU_TRAP_4                                      = 187997,
    GO_CARIBOU_TRAP_5                                      = 187998,
    GO_CARIBOU_TRAP_6                                      = 187999,
    GO_CARIBOU_TRAP_7                                      = 188000,
    GO_CARIBOU_TRAP_8                                      = 188001,
    GO_CARIBOU_TRAP_9                                      = 188002,
    GO_CARIBOU_TRAP_10                                     = 188003,
    GO_CARIBOU_TRAP_11                                     = 188004,
    GO_CARIBOU_TRAP_12                                     = 188005,
    GO_CARIBOU_TRAP_13                                     = 188006,
    GO_CARIBOU_TRAP_14                                     = 188007,
    GO_CARIBOU_TRAP_15                                     = 188008,
    GO_HIGH_QUALITY_FUR                                    = 187983,
    NPC_NESINGWARY_TRAPPER                                 = 25835
};

#define CaribouTrapsNum 15
const uint32 CaribouTraps[CaribouTrapsNum] =
{
    GO_CARIBOU_TRAP_1, GO_CARIBOU_TRAP_2, GO_CARIBOU_TRAP_3, GO_CARIBOU_TRAP_4, GO_CARIBOU_TRAP_5,
    GO_CARIBOU_TRAP_6, GO_CARIBOU_TRAP_7, GO_CARIBOU_TRAP_8, GO_CARIBOU_TRAP_9, GO_CARIBOU_TRAP_10,
    GO_CARIBOU_TRAP_11, GO_CARIBOU_TRAP_12, GO_CARIBOU_TRAP_13, GO_CARIBOU_TRAP_14, GO_CARIBOU_TRAP_15,
};

class item_pile_fake_furs : public ItemScript
{
public:
    item_pile_fake_furs() : ItemScript("item_pile_fake_furs") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const & /*targets*/) override
    {
        GameObject* go = NULL;
        for (uint8 i = 0; i < CaribouTrapsNum; ++i)
        {
            go = player->FindNearestGameObject(CaribouTraps[i], 5.0f);
            if (go)
                break;
        }

        if (!go)
            return false;

        if (go->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, true) || go->FindNearestCreature(NPC_NESINGWARY_TRAPPER, 10.0f, false) || go->FindNearestGameObject(GO_HIGH_QUALITY_FUR, 2.0f))
            return true;

        float x, y, z;
        go->GetClosePoint(x, y, z, go->GetObjectSize() / 3, 7.0f);
        go->SummonGameObject(GO_HIGH_QUALITY_FUR, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, 0, 0, 0, 0, 1);
        if (TempSummon* summon = player->SummonCreature(NPC_NESINGWARY_TRAPPER, x, y, z, go->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 1000))
        {
            summon->SetVisible(false);
            summon->SetReactState(REACT_PASSIVE);
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        }
        return false;
    }
};

/*#####
# item_petrov_cluster_bombs
#####*/

enum PetrovClusterBombs
{
    SPELL_PETROV_BOMB           = 42406,
    AREA_ID_SHATTERED_STRAITS   = 4064,
    ZONE_ID_HOWLING             = 495
};

class item_petrov_cluster_bombs : public ItemScript
{
public:
    item_petrov_cluster_bombs() : ItemScript("item_petrov_cluster_bombs") { }

    bool OnUse(Player* player, Item* item, const SpellCastTargets & /*targets*/) override
    {
        if (player->GetZoneId() != ZONE_ID_HOWLING)
            return false;

        if (!player->GetTransport() || player->GetAreaId() != AREA_ID_SHATTERED_STRAITS)
        {
            player->SendEquipError(EQUIP_ERR_NONE, item, NULL);

            if (const SpellInfo* spellInfo = sSpellMgr->GetSpellInfo(SPELL_PETROV_BOMB))
                Spell::SendCastResult(player, spellInfo, 1, SPELL_FAILED_NOT_HERE);

            return true;
        }

        return false;
    }
};

/*######
# item_dehta_trap_smasher
# For quest 11876, Help Those That Cannot Help Themselves
######*/
enum HelpThemselves
{
    QUEST_CANNOT_HELP_THEMSELVES                  =  11876,
    NPC_TRAPPED_MAMMOTH_CALF                      =  25850,
    GO_MAMMOTH_TRAP_1                             = 188022,
    GO_MAMMOTH_TRAP_2                             = 188024,
    GO_MAMMOTH_TRAP_3                             = 188025,
    GO_MAMMOTH_TRAP_4                             = 188026,
    GO_MAMMOTH_TRAP_5                             = 188027,
    GO_MAMMOTH_TRAP_6                             = 188028,
    GO_MAMMOTH_TRAP_7                             = 188029,
    GO_MAMMOTH_TRAP_8                             = 188030,
    GO_MAMMOTH_TRAP_9                             = 188031,
    GO_MAMMOTH_TRAP_10                            = 188032,
    GO_MAMMOTH_TRAP_11                            = 188033,
    GO_MAMMOTH_TRAP_12                            = 188034,
    GO_MAMMOTH_TRAP_13                            = 188035,
    GO_MAMMOTH_TRAP_14                            = 188036,
    GO_MAMMOTH_TRAP_15                            = 188037,
    GO_MAMMOTH_TRAP_16                            = 188038,
    GO_MAMMOTH_TRAP_17                            = 188039,
    GO_MAMMOTH_TRAP_18                            = 188040,
    GO_MAMMOTH_TRAP_19                            = 188041,
    GO_MAMMOTH_TRAP_20                            = 188042,
    GO_MAMMOTH_TRAP_21                            = 188043,
    GO_MAMMOTH_TRAP_22                            = 188044,
};

#define MammothTrapsNum 22
const uint32 MammothTraps[MammothTrapsNum] =
{
    GO_MAMMOTH_TRAP_1, GO_MAMMOTH_TRAP_2, GO_MAMMOTH_TRAP_3, GO_MAMMOTH_TRAP_4, GO_MAMMOTH_TRAP_5,
    GO_MAMMOTH_TRAP_6, GO_MAMMOTH_TRAP_7, GO_MAMMOTH_TRAP_8, GO_MAMMOTH_TRAP_9, GO_MAMMOTH_TRAP_10,
    GO_MAMMOTH_TRAP_11, GO_MAMMOTH_TRAP_12, GO_MAMMOTH_TRAP_13, GO_MAMMOTH_TRAP_14, GO_MAMMOTH_TRAP_15,
    GO_MAMMOTH_TRAP_16, GO_MAMMOTH_TRAP_17, GO_MAMMOTH_TRAP_18, GO_MAMMOTH_TRAP_19, GO_MAMMOTH_TRAP_20,
    GO_MAMMOTH_TRAP_21, GO_MAMMOTH_TRAP_22
};

class item_dehta_trap_smasher : public ItemScript
{
public:
    item_dehta_trap_smasher() : ItemScript("item_dehta_trap_smasher") { }

    bool OnUse(Player* player, Item* /*item*/, const SpellCastTargets & /*targets*/) override
    {
        if (player->GetQuestStatus(QUEST_CANNOT_HELP_THEMSELVES) != QUEST_STATUS_INCOMPLETE)
            return false;

        Creature* pMammoth = player->FindNearestCreature(NPC_TRAPPED_MAMMOTH_CALF, 5.0f);
        if (!pMammoth)
            return false;

        GameObject* pTrap = NULL;
        for (uint8 i = 0; i < MammothTrapsNum; ++i)
        {
            pTrap = player->FindNearestGameObject(MammothTraps[i], 11.0f);
            if (pTrap)
            {
                pMammoth->AI()->DoAction(1);
                pTrap->SetGoState(GO_STATE_READY);
                player->KilledMonsterCredit(NPC_TRAPPED_MAMMOTH_CALF);
                return true;
            }
        }
        return false;
    }
};

enum TheEmissary
{
    QUEST_THE_EMISSARY      =   11626,
    NPC_LEVIROTH            =   26452
};

class item_trident_of_nazjan : public ItemScript
{
public:
    item_trident_of_nazjan() : ItemScript("item_Trident_of_Nazjan") { }

    bool OnUse(Player* player, Item* item, const SpellCastTargets & /*targets*/) override
    {
        if (player->GetQuestStatus(QUEST_THE_EMISSARY) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* pLeviroth = player->FindNearestCreature(NPC_LEVIROTH, 10.0f)) // spell range
            {
                pLeviroth->AI()->AttackStart(player);
                return false;
            } else
                player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE, item, NULL);
        } else
            player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, item, NULL);
        return true;
    }
};

enum CapturedFrog
{
    QUEST_THE_PERFECT_SPIES      = 25444,
    NPC_VANIRAS_SENTRY_TOTEM     = 40187
};

class item_captured_frog : public ItemScript
{
public:
    item_captured_frog() : ItemScript("item_captured_frog") { }

    bool OnUse(Player* player, Item* item, SpellCastTargets const& /*targets*/) override
    {
        if (player->GetQuestStatus(QUEST_THE_PERFECT_SPIES) == QUEST_STATUS_INCOMPLETE)
        {
            if (player->FindNearestCreature(NPC_VANIRAS_SENTRY_TOTEM, 10.0f))
                return false;
            else
                player->SendEquipError(EQUIP_ERR_OUT_OF_RANGE, item, NULL);
        }
        else
            player->SendEquipError(EQUIP_ERR_CANT_DO_RIGHT_NOW, item, NULL);
        return true;
    }
};

class item_bank_stone : public ItemScript
{
public:
    item_bank_stone() : ItemScript("item_bank_stone") { }

    bool OnUse(Player* player, Item* item, const SpellCastTargets & /*targets*/) override
    {
        player->CastCustomSpell(player, 836, NULL, NULL, NULL, true);
        player->GetSession()->SendShowBank(player->GetSession()->GetPlayer()->GetGUID());
        return true;
    }
};

struct ItemCastData
{
    uint32 uiSpellId;
    uint8 uiDays;
    uint32 uiHours;
    uint8 uiChance;
};

enum WoW4YouTabardTimeFlags
{
    DAY_SUNDAY = 1,
    DAY_MONDAY = 2,
    DAY_TUESDAY = 4,
    DAY_WEDNESDAY = 8,
    DAY_THURSDAY = 16,
    DAY_FRIDAY = 32,
    DAY_SATURDAY = 64,
    DAY_EVERY_DAY = DAY_SUNDAY | DAY_MONDAY | DAY_TUESDAY | DAY_WEDNESDAY | DAY_THURSDAY | DAY_FRIDAY | DAY_SATURDAY,

    HOUR_MIDNIGHT = 1,
    HOUR_1 = 2,
    HOUR_2 = 4,
    HOUR_3 = 8,
    HOUR_4 = 16,
    HOUR_5 = 32,
    HOUR_6 = 64,
    HOUR_7 = 128,
    HOUR_8 = 256,
    HOUR_9 = 512,
    HOUR_10 = 1024,
    HOUR_11 = 2048,
    HOUR_12 = 4096,
    HOUR_13 = 8192,
    HOUR_14 = 16384,
    HOUR_15 = 32768,
    HOUR_16 = 65536,
    HOUR_17 = 131072,
    HOUR_18 = 262144,
    HOUR_19 = 524288,
    HOUR_20 = 1048576,
    HOUR_21 = 2097152,
    HOUR_22 = 4194304,
    HOUR_23 = 8388608,
    HOUR_EVERY_HOUR = HOUR_MIDNIGHT | HOUR_1 | HOUR_2 | HOUR_3 | HOUR_4 | HOUR_5 | HOUR_6 | HOUR_7 | HOUR_8 | HOUR_9 | HOUR_10 | HOUR_11 | HOUR_12 | HOUR_13 | HOUR_14 | HOUR_15 | HOUR_16 | HOUR_17 | HOUR_18 | HOUR_19 | HOUR_20 | HOUR_21 | HOUR_22 | HOUR_23
};

enum WoW4YouTabardSpells
{
    SPELL_BLACKWHELP_TRANSFORMATION  = 38318,
    SPELL_BLOATED                    = 49822,
    SPELL_DIRE_WOLF_FORM             = 22660,
    SPELL_FROG_FORM                  =  3329,
    SPELL_GNOMISH_BINARY             = 50242,
    SPELL_GOBLIN_BINARY              = 50246,
    SPELL_GROUND_SLAM                = 33525,
    SPELL_I_CANT_DRIVE_55            = 31565,
    SPELL_LICH_SLAP                  = 60924,
    SPELL_MEAT_SLAP                  = 37597,
    SPELL_PURPLE_FIREWORK            = 30161,
    SPELL_RABBIT_FORM                = 61716,
    SPELL_SUICIDE                    = 27965,
    SPELL_TABARD_OF_THE_LIGHTBRINGER = 73326,
    SPELL_TEST_TICKLE                =  5025,
    SPELL_ZOMBIE_FORM                =  7293
};

#define WoW4YouTabardSpellsNum 16
const static ItemCastData aItemCastData[WoW4YouTabardSpellsNum] =
{
    { SPELL_TABARD_OF_THE_LIGHTBRINGER, DAY_FRIDAY | DAY_SATURDAY | DAY_SUNDAY, HOUR_15 | HOUR_16 | HOUR_17 | HOUR_18 | HOUR_19 | HOUR_20 | HOUR_21, 50 },
    { SPELL_MEAT_SLAP, DAY_MONDAY | DAY_TUESDAY | DAY_WEDNESDAY | DAY_THURSDAY | DAY_FRIDAY, HOUR_7 | HOUR_8 | HOUR_9 | HOUR_10 | HOUR_11 | HOUR_12 | HOUR_13, 50 },
    { SPELL_I_CANT_DRIVE_55, DAY_TUESDAY | DAY_WEDNESDAY | DAY_THURSDAY, HOUR_15 | HOUR_16 | HOUR_17 | HOUR_18 | HOUR_19, 50 },
    { SPELL_BLOATED, DAY_SATURDAY | DAY_SUNDAY, HOUR_7 | HOUR_8 | HOUR_9 | HOUR_10 | HOUR_11 | HOUR_12 | HOUR_13, 25 },
    { SPELL_ZOMBIE_FORM, DAY_EVERY_DAY, HOUR_22 | HOUR_23 | HOUR_MIDNIGHT | HOUR_1, 50 },
    { SPELL_LICH_SLAP, DAY_MONDAY | DAY_TUESDAY | DAY_WEDNESDAY | DAY_THURSDAY | DAY_FRIDAY, HOUR_7 | HOUR_8 | HOUR_9 | HOUR_10 | HOUR_11 | HOUR_12 | HOUR_13, 50 },
    { SPELL_GOBLIN_BINARY, DAY_EVERY_DAY, HOUR_22, 25 },
    { SPELL_GNOMISH_BINARY, DAY_EVERY_DAY, HOUR_23, 25 },
    { SPELL_GROUND_SLAM, DAY_EVERY_DAY, HOUR_20 | HOUR_21, 25 },
    { SPELL_BLACKWHELP_TRANSFORMATION, DAY_FRIDAY | DAY_SATURDAY | DAY_SUNDAY, HOUR_15 | HOUR_16 | HOUR_17 | HOUR_18 | HOUR_19 | HOUR_20 | HOUR_21, 50 },
    { SPELL_SUICIDE, DAY_EVERY_DAY, HOUR_MIDNIGHT, 45 },
    { SPELL_FROG_FORM, DAY_EVERY_DAY, HOUR_2 | HOUR_3 | HOUR_4, 50 },
    { SPELL_RABBIT_FORM, DAY_EVERY_DAY, HOUR_5 | HOUR_6, 35 },
    { SPELL_TEST_TICKLE, DAY_EVERY_DAY, HOUR_14 | HOUR_15 | HOUR_16 | HOUR_17 | HOUR_18 | HOUR_19, 75 },
    { SPELL_DIRE_WOLF_FORM, DAY_EVERY_DAY, HOUR_EVERY_HOUR, 15 },
    { SPELL_PURPLE_FIREWORK, DAY_EVERY_DAY, HOUR_EVERY_HOUR, 100 } // Wird immer gecastet wenn nichts gefunden wurde
};

class item_wow4you_tabard : public ItemScript
{
public:
    item_wow4you_tabard() : ItemScript("item_wow4you_tabard") { }

    bool OnUse(Player* player, Item* item, const SpellCastTargets & /*targets*/) override
    {
        uint32 uiSpellId = 0;
        time_t tTime = time(NULL);
        tm* pLocalTime = localtime(&tTime);
        uint8 uiDay = pow((float)2, (float)pLocalTime->tm_wday);
        uint32 uiHour = pow((float)2, (float)pLocalTime->tm_hour);

        for (uint8 i = 0; i < WoW4YouTabardSpellsNum && !uiSpellId; ++i)
            if ((aItemCastData[i].uiDays & uiDay) && (aItemCastData[i].uiHours & uiHour))
                if (roll_chance_i(aItemCastData[i].uiChance))
                    uiSpellId = aItemCastData[i].uiSpellId;

        if (uiSpellId)
        {
            player->CastSpell(player, uiSpellId, true);
            return true;
        }

        return false;
    }
};

void AddSC_item_scripts()
{
    new item_only_for_flight();
    new item_nether_wraith_beacon();
    new item_gor_dreks_ointment();
    new item_incendiary_explosives();
    new item_mysterious_egg();
    new item_disgusting_jar();
    new item_pile_fake_furs();
    new item_petrov_cluster_bombs();
    new item_dehta_trap_smasher();
    new item_trident_of_nazjan();
    new item_captured_frog();
    new item_bank_stone();
    new item_wow4you_tabard();
}
