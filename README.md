# Dayz_PlayerStartLoot (Server)

Зачем?
На случай, если на сервере надо сделать рандомный стартовый лут

Установка
1) Берёшь @StartItems, кидаешь её в папку с сервером. 
2) Берёшь папку PlayerSpawn, кидаешь в profile своего сервера (или что там у тебя указано в батнике запуска в параметре -profiles)
3) Исправляешь настройки в файле playerSpawnConfig.json
4) Удаляешь ко всем чертям override void StartingEquipSetup и то что в нём в файле init.c твоей миссии
5) В бинарнике сервера указываем "-servermod=@StartItems;"

