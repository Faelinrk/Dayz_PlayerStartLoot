# Dayz_PlayerStartLoot (Server)

Зачем?
На случай, если на сервере надо сделать рандомный стартовый лут

Установка
1) Берёшь @StartItems, кидаешь её в папку с сервером. 
2) Берёшь папку PlayerSpawn, пидаешь в profile своего сервера (или что там у тебя указано в батнике запуска в параметре -profiles)
3) Исправляешь настройки в файле playerSpawnConfig.json
4) Удаляешь ко всем чертям всё что есть в modded class MissionServer (по крайней мере, override void StartingEquipSetup и то что в нём точно надо бы снести)
5) Ключ из папочки кидаем в keys сервера
6) В бинарнике сервера указываем "-servermod=@StartItems;"

