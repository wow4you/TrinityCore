-- Dead Mage Hunter Fix

DELETE FROM npc_spellclick_spells WHERE npc_entry=26477;

INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`)
VALUES
('26477','47096','2','0'),
('26477','61286','2','0'),
('26477','61832','1','0');
