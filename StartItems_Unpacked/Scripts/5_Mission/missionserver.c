modded class MissionServer
{
	JsonItemPool itemPool
	const string profilePath = "$profile:";
	const string configFolderName = "PlayerSpawn";
	const string configName = "playerSpawnConfig.json";
	
	override void OnInit()
	{
		super.OnInit();
		loadPoolConfig();
	}
	
	bool loadPoolConfig()
	{		
		if (FileExist(profilePath + configFolderName + "/" + configName))
        {
			JsonFileLoader<JsonItemPool>.JsonLoadFile(profilePath + configFolderName + "/" + configName, itemPool);
			Print("[PlayerSpawn] Json Initialized");
            return true;
        }
        else
        {
            Print("[PlayerSpawn] Json does not exist.");
            return false;
        }
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{	
		InventoryController iC = new InventoryController(player, itemPool);
		iC.ClearStartInventory();
		iC.GiveStartLoot();
	}
	
};