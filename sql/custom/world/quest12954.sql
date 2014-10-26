-- Fix Zul'Drak outdatedQuest
DELETE FROM creature_queststarter WHERE id=30007 AND quest=12954;
