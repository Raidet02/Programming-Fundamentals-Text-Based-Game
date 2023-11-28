#pragma once

#include "Main.h"

void ListEnemies() //lists all the enmeies on the field
{
	cout << "The enemies that lay before you are: " << endl << endl;

	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyName != emptyEnemySlot.enemyName)
		{
			cout << i + 1 << ". " << dungeon1.enemyList[i].enemyName << " health: " << dungeon1.enemyList[i].enemyStats.currentHealth << " / " << dungeon1.enemyList[i].enemyStats.maxHealth << endl;
		}

		i++;
	}

	cout << endl << "Your current health is: " << player1.playerStats.currentHealth << " / " << player1.playerStats.maxHealth << endl; //displays health
}

void EnemyTurn() //makes the enemy attack the player 
{
	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyName != emptyEnemySlot.enemyName)
		{
			cout << endl << dungeon1.enemyList[i].enemyName << " has dealt " << dungeon1.enemyList[i].enemyStats.strength - player1.playerStats.fortitude << " damage to you" << endl; //outputs the enemies damage

			player1.playerStats.currentHealth -= (dungeon1.enemyList[i].enemyStats.strength - player1.playerStats.fortitude); //damage is attack - fortitude of player
		}

		i++;
	}

	sleep_for(milliseconds(2500));
}

void CheckLvl() //checks if the player has levelled up or not and if so gets the player to select a stat to increase
{
	int xpThreshold = 0;
	xpThreshold = player1.playerLevel * 100; //xp threshold is the players level x 100
	string playerCommand = "";

	if (player1.xp >= xpThreshold)
	{
		player1.playerLevel++; //increase player level, health and mana and set health and mana to max

		player1.playerStats.maxHealth++;
		player1.playerStats.maxMana++;

		player1.playerStats.currentHealth = player1.playerStats.maxHealth;
		player1.playerStats.currentMana = player1.playerStats.maxMana;

		player1.xp = 0; //current xp = 0

		Clear();

		cout << "You have leveled up please choose a stat to increase by 1: " << endl; //asks what stat to increase
		cout << endl << "strength: " << player1.playerStats.strength << endl << "intelligence: " << player1.playerStats.intelligence;
		cout << endl << "charisma: " << player1.playerStats.charisma << endl << "fortitude: " << player1.playerStats.fortitude << endl;
		
		for (int i = 0; i != 1;)
		{
			i++;

			cout << endl << "> ";
			cin >> playerCommand;

			if (playerCommand == "strength")
			{
				player1.playerStats.strength++;
			}
			else if (playerCommand == "intelligence")
			{
				player1.playerStats.intelligence++;
			}
			else if (playerCommand == "charisma")
			{
				player1.playerStats.charisma;
			}
			else if (playerCommand == "fortitude")
			{
				player1.playerStats.fortitude++;
			}
			else
			{
				cout << endl << "Please enter a valid command" << endl;

				i--;
			}

			CinIgnore();
		}
	}
}

bool CheckIfEnemiesAreDead() //checks to see if the player has killed all the enmeies
{
	bool endCombat = true;

	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyStats.currentHealth <= 0) //if enemy has died increase xp and gold
		{
			cout << endl << "You have killed " << dungeon1.enemyList[i].enemyName << "." << endl;

			sleep_for(milliseconds(1500));

			player1.xp += dungeon1.enemyList[i].xpDrop;
			player1.gold += dungeon1.enemyList[i].goldDrop;

			CheckLvl();

			dungeon1.enemyList[i] = emptyEnemySlot;

			dungeon1.amountOfEnemies--;
		}

		i++;
	}

	if (dungeon1.amountOfEnemies <= 0)
	{
		endCombat = false;
	}

	return endCombat; //if all enemies are dead returns false (this will be inversed later)
}

void CheckPlayerAlive() //checks if the player has died 
{
	if (player1.playerStats.currentHealth <= 0)
	{
		player1.playerIsAlive = false;
	}
}

void Combat() //the main comabat function
{
	string playerCommand = "";
	string playerCommandTemp = "";
	int end = 0;
	int indexValue = 0;
	int damageDealt = 0;
	bool enemiesRemain = true;
	
	CinIgnore();

	cout << endl << "Commands are:" << endl << "attack (index) - To use a basic attack\ninventory - To list all items in the inventory\n use (index) - To use an item" << endl; //displays how to attack 

	while (enemiesRemain == true && player1.playerIsAlive == true) //checks if enemies remain and if the player is alive if not then ends comabat
	{

		for (int i = 0; i != 1;)
		{
			i++;

			cout << endl << "> ";

			getline(cin, playerCommandTemp);
			end = playerCommandTemp.find(" ");
			playerCommand = playerCommandTemp.substr(0, end); //seperates the command from the index value

			if (playerCommand == "attack")
			{
				playerCommand = playerCommandTemp.substr(end, (sizeof(playerCommandTemp) / 4)); //gets theindex value

				indexValue = CheckIfValidNumber(playerCommand);

				if (dungeon1.enemyList[indexValue].enemyName != emptyEnemySlot.enemyName) //checks that the player isn't trying to attack an empty space
				{
					if (player1.characterClass == "Wizard") //if playing wizard attacls based on intelligence not strength
					{
						damageDealt = player1.playerStats.intelligence - dungeon1.enemyList[indexValue - 1].enemyStats.fortitude;
					}
					else
					{
						damageDealt = player1.playerStats.strength - dungeon1.enemyList[indexValue - 1].enemyStats.fortitude;
					}

					dungeon1.enemyList[indexValue - 1].enemyStats.currentHealth -= damageDealt; //sets damage dealt

					cout << endl << "You have dealt " << damageDealt << " damage to " << dungeon1.enemyList[indexValue - 1].enemyName << " " << indexValue << endl; //outputs damage that the player did

					sleep_for(milliseconds(2000));
				}
				else
				{
					cout << endl << "Please enter a valid index";
				}
			}
			else if (playerCommand == "inventory") //lists the inventory
			{
				cout << endl << "> inventory:" << endl;

				for (int j = 0; j < 5;)
				{
					cout << "- Slot " << j + 1 << ": " << player1.inventory[j].itemName << endl;

					j++;
				}

				i--;
			}
			else if (playerCommand == "use") //uses an item of the indexed slot
			{
				playerCommand = playerCommandTemp.substr(end, (sizeof(playerCommandTemp) / 4));

				indexValue = CheckIfValidNumber(playerCommand);

				if (player1.inventory[indexValue - 1].itemName == "Health Potion" && player1.playerStats.currentHealth < player1.playerStats.maxHealth) //checks if the item is a health potion and that the player isn't at max Health
				{
					player1.playerStats.currentHealth += 3; //increases Mana by 3 

					if (player1.playerStats.currentHealth > player1.playerStats.maxHealth) //if the player overhealed sets Health to max Health
					{
						player1.playerStats.currentHealth = player1.playerStats.maxHealth;
					}

					cout << endl << "You have consumed a Health potion." << endl << "Your health is at " << player1.playerStats.currentHealth << " / " << player1.playerStats.maxHealth << endl; //displays Health

					player1.inventory[indexValue - 1] = emptySlot;
				}
				else if (player1.inventory[indexValue - 1].itemName == "Mana Potion" && player1.playerStats.currentMana < player1.playerStats.maxMana) //checks if the item is a Mana potion and that the player isn't at max Mana
				{ 
					player1.playerStats.currentMana += 3; //increases Mana by 3 

					if (player1.playerStats.currentMana > player1.playerStats.maxMana) //if the player went over the Mana limit ruduces Mana to max Mana
					{
						player1.playerStats.currentMana = player1.playerStats.maxMana;
					}

					cout << endl << "You have consumed a Mana potion." << endl << "Your mana is at " << player1.playerStats.currentMana << " / " << player1.playerStats.maxMana << endl; //displays Mana

					player1.inventory[indexValue - 1] = emptySlot;
				}
				else //error checks
				{
					if (player1.playerStats.currentHealth == player1.playerStats.maxHealth)
					{
						cout << endl << "You are at full Health";
					}
					else if (player1.playerStats.currentMana == player1.playerStats.maxMana)
					{
						cout << endl << "You are at full mana";
					}
					else
					{
						cout << endl << "Please enter a valid index number";
					}
				}

				i--;
			}
			else //error check
			{
				cout << endl << "please enter a valid command" << endl;

				i--;
			}
		}

		enemiesRemain = CheckIfEnemiesAreDead(); //inveres the return but not the value

		if (enemiesRemain == true) //runs if = to true
		{
			EnemyTurn();

			CheckPlayerAlive();

			if (player1.playerIsAlive == true) //runs if player is alive
			{
				Clear();

				ListEnemies();
			}
		}
	}
}

void FirstFloor() //spawns and sets enemies
{
	Clear();

	int floor = 1;

	string playerCommand = "";

	for (int room = 0; room != 6;) //runs for 5 rooms
	{
		room++;

		if (player1.playerIsAlive == true) //runs if player is alive
		{
			cout << "God - " << player1.name << " has approached room " << floor << " : " << room << endl << endl << "Do you wish to enter?" << endl; //checks if the player wants to continue

			for (int i = 0; i != 1;)
			{
				i++;

				cout << endl << "> ";
				cin >> playerCommand;

				if (playerCommand == "no") //setting room to 6 will end the loop
				{
					room = 6;

					cout << endl << "God - You have returned from the dungeon and rested, your health is full again.";

					CinIgnore();
				}
				else if (playerCommand == "yes") //runs combat after setting enemies
				{
					Clear();

					if (floor == 1)
					{
						if (room == 1)
						{
							dungeon1.enemyList[0] = hornedRat1;

							dungeon1.amountOfEnemies = 1;

							ListEnemies();

							Combat();

							Clear();

							sleep_for(milliseconds(1500));

							Clear();
						}
						else if (room == 2)
						{
							dungeon1.enemyList[0] = hornedRat1;
							dungeon1.enemyList[1] = hornedRat2;

							dungeon1.amountOfEnemies = 2;

							ListEnemies();

							Combat();

							sleep_for(milliseconds(1000));

							Clear();
						}
						else if (room == 3)
						{
							dungeon1.enemyList[0] = hornedRat1;
							dungeon1.enemyList[1] = hornedRat2;
							dungeon1.enemyList[2] = hornedRat3;

							dungeon1.amountOfEnemies = 3;

							ListEnemies();

							Combat();

							sleep_for(milliseconds(1000));

							Clear();
						}
						else if (room == 4)
						{
							dungeon1.enemyList[0] = hornedRat1;
							dungeon1.enemyList[1] = hornedRat2;
							dungeon1.enemyList[2] = hornedRat3;
							dungeon1.enemyList[3] = hornedRat4;


							dungeon1.amountOfEnemies = 4;

							ListEnemies();

							Combat();

							sleep_for(milliseconds(1000));

							Clear();
						}
						else if (room == 5)
						{
							dungeon1.enemyList[0] = hornedRat1;
							dungeon1.enemyList[1] = hornedRat2;
							dungeon1.enemyList[2] = hornedRat3;
							dungeon1.enemyList[3] = hornedRat4;
							dungeon1.enemyList[4] = hornedRat5;


							dungeon1.amountOfEnemies = 5;

							ListEnemies();

							Combat();

							sleep_for(milliseconds(1000));

							Clear();
						}
					}
				}
				else //error check
				{
					cout << endl << "Please enter a valid command." << endl;

					i--;
				}
			}
		}
		else
		{
			Clear();

			cout << "God - You have fallen like many others before you."; //runs if player died

			sleep_for(milliseconds(1500));

			Clear();

			room = 6;
		}
	}
}

void DungeonDive()
{
	Clear();

	cout << "God - You have entered the dungeon." << endl;

	sleep_for(milliseconds(2000));

	FirstFloor();
}