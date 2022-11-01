class CfgPatches
{
	class classslection_scripts
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class classslection
	{
		
		dir = "StartItems";
		picture = "";
		hideName = 1;
		hidePicture = 1;
		name = "Change Spawn Loot";
		action = "";
		author = "Faelin";
		authorID = "FaelinHere"; 
		version = "0.1"; 
		extra = 0;
		type = "mod";

		dependencies[] = { "Game", "World", "Mission" };
		
		class defs
		{	
			class missionScriptModule
			{
				value = "";
				files[] = {"StartItems/Scripts/5_Mission"};
			};
		};
	};
};