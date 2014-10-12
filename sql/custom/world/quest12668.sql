DELETE FROM smart_scripts WHERE entryorguid=28747 AND id=5;
insert into smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask,
event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type,
action_param1, action_param2, action_param3, action_param4, action_param5, action_param6,
target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z,
target_o, comment) values
(28747,0,5,6,61,0,100,0,0,0,0,0,80,2874700,2,0,0,0,0,1,0,0,0,0,
0,0,0,'Quetz\'lun Worshipper - Between 0-0% Health - Run Script (Phase 1) (No Repeat)');

DELETE FROM smart_scripts WHERE entryorguid=28747 AND id=6;
insert into smart_scripts (entryorguid, source_type, id, link, event_type, event_phase_mask,
event_chance, event_flags, event_param1, event_param2, event_param3, event_param4, action_type,
action_param1, action_param2, action_param3, action_param4, action_param5, action_param6,
target_type, target_param1, target_param2, target_param3, target_x, target_y, target_z,
target_o, comment) values
(28747,0,6,0,61,0,100,0,0,0,0,0,33,28713,0,0,0,0,0,16,0,0,0,0,0
,0,0,'Quetz\'lun Worshipper - On Just Died - Quest Credit \'Foundation for Revenge\' (Phase 1) (No
Repeat)');
