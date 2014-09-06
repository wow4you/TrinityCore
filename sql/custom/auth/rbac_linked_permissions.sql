DELETE FROM `rbac_linked_permissions` WHERE `id` IN(192, 193, 194, 195) AND `linkedId` IN(24, 25, 26, 27, 28, 29);
INSERT INTO `rbac_linked_permissions`(`id`, `linkedId`) VALUES
(195, 24), -- Player: Two side faction characters on the same account
(195, 25), -- Player: Allow say chat between factions
(195, 26), -- Player: Allow channel chat between factions
(195, 27), -- Player: Allow two side mail interaction
(195, 28), -- Player: See two side who list
(195, 29); -- Player: Add friends of other faction
