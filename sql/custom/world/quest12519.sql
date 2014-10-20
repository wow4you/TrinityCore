DELETE FROM npc_spellclick_spells WHERE npc_entry=28162;

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES('28162','57323','1','0');
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES('28162','61286','2','0');

DELETE FROM smart_scripts WHERE entryorguid=28162;

INSERT INTO `smart_scripts`
(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('28162','0','0','1','8','0','100','1','57323','0','0','0','11','50737','2','0','0','0','0','7','0','0','0','0','0','0','0','Drakkari Corpse - On Spellhit \'Trigger Test\' - Cast \'Create Drakkari Medallion\''),
('28162','0','1','0','61','0','100','0','0','0','0','0','41','1000','0','0','0','0','0','1','0','0','0','0','0','0','0','Drakkari Corpse - Despawn after interaction');
