

class InventoryController
{
	JsonItemPool itemPool;
	PlayerBase player;
	
	
	void InventoryController(PlayerBase player, JsonItemPool itemPool)
	{
		
		this.player = player;
		this.itemPool = itemPool;
	}

	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.45, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}
	
	void ClearStartInventory()
	{
		player.RemoveAllItems();
	}
	

	
	void GiveStartLoot()
	{

		if(itemPool.startJackets)
			GiveAttachment(itemPool.startJackets.GetRandomElement());//jacket			
		if(itemPool.startJeans)
			GiveAttachment(itemPool.startJeans.GetRandomElement());//pants
		if(itemPool.startBoots)
			GiveAttachment(itemPool.startBoots.GetRandomElement());//boots
		
	
		foreach(string item: itemPool.startItems) //other stuff
		{
			GiveItemFromString(item);
		}

		for (int i = 0; i < itemPool.foodCount; i++) //food
		{
			GiveItemFromString(itemPool.startFood.GetRandomElement());
		}
	}
	
	
	void GiveAttachment(string attachment, bool randomHealth = true)
	{
		EntityAI itemAttachment;
		itemAttachment = player.GetInventory().CreateAttachment(attachment);
		if (randomHealth)
			SetRandomHealth( itemAttachment );
	}
	
	void Giveitem(string item, int quantity = 0, bool randomHealth = true)
	{
		EntityAI itemToGive;
		ItemBase itemBs;
		itemToGive = player.GetInventory().CreateInInventory(item);	
		if (randomHealth)
			SetRandomHealth( itemToGive );
		if (quantity != 0)
		{
			if ( Class.CastTo( itemBs, itemToGive ) )
				itemBs.SetQuantity( quantity );
		}
	}
	
	void GiveItemFromString(string itemString)
	{
		TStringArray itemArray = new TStringArray;
		itemString.Split(",",itemArray);
		string item = itemArray[0];
		int quantity = itemArray[1].ToInt();
		Giveitem(item, quantity, itemPool.randomQuality);
	}
}
