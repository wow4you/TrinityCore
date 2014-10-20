-- Grishna Falconwing

UPDATE creature_template SET AIName='SmartAI' WHERE entry = 19988;
DELETE FROM smart_scripts WHERE entryorguid=19988;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
('19988','0','0','1','6','0','100','0','0','0','0','0','11','37473','1','0','0','0','0','16','0','0','0','0','0','0','0','Cast Spell Animation \'Detect Whispers\' ID 37473\r\n'),
('19988','0','1','2','61','0','100','0','0','0','0','0','85','37642','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37642 (BUFF)'),
('19988','0','2','0','61','0','100','0','0','0','0','0','85','37466','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37466 (SPELL tracking)'),
('19988','0','3','4','1','0','100','0','1','5000','0','0','11','35109','0','0','0','0','0','1','0','0','0','0','0','0','0','Spawn pet'),
('19988','0','4','0','61','0','100','0','0','0','0','0','22','1','0','0','0','0','0','1','0','0','0','0','0','0','0','Set Phase 1'),
('19988','0','5','0','0','0','100','1','1','3000','1','1','11','37587','1','0','0','0','0','26','15','0','0','0','0','0','0','Pet enrage buff');


-- Grishna HARBINGER

UPDATE creature_template SET AIName='SmartAI' WHERE entry = 19989;
DELETE FROM smart_scripts WHERE entryorguid=19989;


INSERT INTO `smart_scripts`
(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
('19989','0','0','1','6','0','100','0','0','0','0','0','11','37473','1','0','0','0','0','16','0','0','0','0','0','0','0','Cast Spell Animation \'Detect Whispers\' ID 37473\r\n'),
('19989','0','1','2','61','0','100','0','0','0','0','0','85','37642','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37642 (BUFF)'),
('19989','0','2','0','61','0','100','0','0','0','0','0','85','37466','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37466 (SPELL tracking)'),
('19989','0','3','0','0','0','100','0','0','0','0','0','11','9532','64','0','0','0','0','2','0','0','0','0','0','0','0','lightning Bolt Cast'),
('19989','0','4','0','0','0','100','1','1','5000','1','1','11','37589','1','0','0','0','0','2','0','0','0','0','0','0','0','cast shriveling gaze spellID=37589');


-- Grishna Matriarch

UPDATE creature_template SET AIName='SmartAI' WHERE entry = 20329;
DELETE FROM smart_scripts WHERE entryorguid=20329;


INSERT INTO `smart_scripts`
(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
('20329','0','0','1','6','0','100','0','0','0','0','0','11','37473','1','0','0','0','0','16','0','0','0','0','0','0','0','Cast Spell Animation \'Detect Whispers\' ID 37473\r\n'),
('20329','0','1','2','61','0','100','0','0','0','0','0','85','37642','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37642 (BUFF)'),
('20329','0','2','0','61','0','100','0','0','0','0','0','85','37466','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37466 (SPELL tracking)'),
('20329','0','5','0','0','0','100','0','0','0','0','0','11','9613','64','0','0','0','0','2','0','0','0','0','0','0','0','Shadow Bolt Cast'),
('20329','0','4','0','0','0','100','1','1','5000','1','1','11','37579','1','0','0','0','0','2','0','0','0','0','0','0','0','cast impeding doom spellID=37579'),
('20329','0','3','0','14','0','100','0','500','35','0','0','11','34110','0','0','0','0','0','7','0','0','0','0','0','0','0','Heal Cast Spell ID 34110');

UPDATE creature_template SET AIName='SmartAI' WHERE entry = 19990;
DELETE FROM smart_scripts WHERE entryorguid=19990;


INSERT INTO `smart_scripts`
(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
('19990','0','0','1','6','0','100','0','0','0','0','0','11','37473','1','0','0','0','0','16','0','0','0','0','0','0','0','Cast Spell Animation \'Detect Whispers\' ID 37473\r\n'),
('19990','0','1','2','61','0','100','0','0','0','0','0','85','37642','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37642 (BUFF)'),
('19990','0','2','0','61','0','100','0','0','0','0','0','85','37466','1','0','0','0','0','7','0','0','0','0','0','0','0','Apply Understanding Ravenspeech on death ID 37466 (SPELL tracking)'),
('19990','0','3','0','0','0','100','1','0','0','0','0','11','35321','0','0','0','0','0','2','0','0','0','0','0','0','0','Goushing Wound Cast');

-- Quest Aura Buff Apply

INSERT INTO spell_area VALUES(37475,3781,10607,10607,0,0,2,1,74,11);



-- TOTEM UPDATE

DELETE FROM gameobject_template WHERE entry = 184950 OR entry=184967 OR entry=184968 OR entry=184969;

INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES('184950','10','7249','The First Prophecy','','','','35','0','2','0','0','0','0','0','0','0','10607','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartGameObjectAI','','12340');
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES('184967','10','7249','The Second Prophecy','','','','35','0','2','0','0','0','0','0','0','0','10607','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartGameObjectAI','','12340');
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES('184968','10','7249','The Third Prophecy','','','','35','0','2','0','0','0','0','0','0','0','10607','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartGameObjectAI','','12340');
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES('184969','10','7249','The Fourth Prophecy','','','','35','0','2','0','0','0','0','0','0','0','10607','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartGameObjectAI','','12340');

DELETE FROM smart_scripts WHERE entryorguid = 184950 OR entryorguid=184967 OR entryorguid=184968 OR entryorguid=184969;

INSERT INTO `smart_scripts`
(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
('184950','1','0','0','64','0','100','0','0','0','0','0','33','22798','0','0','0','0','0','7','0','0','0','0','0','0','0','The First Prophecy KillCredit \'Whispers of the Raven God\''),
('184967','1','0','0','64','0','100','0','0','0','0','0','33','22799','0','0','0','0','0','7','0','0','0','0','0','0','0','The Second Prophecy KillCredit \'Whispers of the Raven God\''),
('184968','1','0','0','64','0','100','0','0','0','0','0','33','22800','0','0','0','0','0','7','0','0','0','0','0','0','0','The Third Prophecy KillCredit \'Whispers of the Raven God\''),
('184969','1','0','0','64','0','100','0','0','0','0','0','33','22801','0','0','0','0','0','7','0','0','0','0','0','0','0','The Fourth Prophecy KillCredit \'Whispers of the Raven God\'');
