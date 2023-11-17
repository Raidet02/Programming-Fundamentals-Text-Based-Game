#pragma once

#include "Main.h"

void ListEnemies()
{
	cout << "The enemies that lay before you are: " << endl << endl;

	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyName != emptyEnemySlot.enemyName)
		{
			cout << i + 1 << ". " << dungeon1.enemyList[i].enemyName << dungeon1.enemyList[i].enemyStats.currentHealth << " / " << dungeon1.enemyList[i].enemyStats.maxHealth << "health" << endl;
		}

		i++;
	}

	cout << endl << "Your current health is: " << player1.playerStats.currentHealth << " / " << player1.playerStats.maxHealth << endl;
}

void EnemyTurn()
{
	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyName != emptyEnemySlot.enemyName)
		{
			cout << endl << dungeon1.enemyList[i].enemyName << " has dealt " << dungeon1.enemyList[i].enemyStats.strength - player1.playerStats.fortitude << " to you" << endl;

			player1.playerStats.currentHealth -= (dungeon1.enemyList[i].enemyStats.strength - player1.playerStats.fortitude);
		}

		i++;
	}
}

int CheckIfEnemiesAreDead()
{
	int endCombat = 0;

	for (int i = 0; i < 5;)
	{
		if (dungeon1.enemyList[i].enemyStats.currentHealth <= 0)
		{
			player1.xp += dungeon1.enemyList[i].xpDrop;
			player1.gold += dungeon1.enemyList[i].goldDrop;

			dungeon1.enemyList[i] = emptyEnemySlot;

			dungeon1.amountOfEnemies--;

			i++;
		}
	}

	if (dungeon1.amountOfEnemies <= 0)
	{
		endCombat++;
	}

	return endCombat;
}

void Combat()
{
	string playerCommand = "";
	string playerCommandTemp = "";
	int end = 0;
	int enemyIndex = 0;
	int damageDealt = 0;
	

	cout << endl << "Commands are:" << endl << "attack (index) - To use a basic attack" << endl;

	for (int i = 0; i != 1;)
	{
		i++;

		cout << endl << "> ";

		getline(cin, playerCommandTemp);
		end = playerCommandTemp.find(" ");
		playerCommand = playerCommandTemp.substr(0, end);

		if (playerCommand == "attack")
		{
			playerCommand = playerCommandTemp.substr(end, (sizeof(playerCommandTemp) / 4));

			enemyIndex = CheckIfValidNumber(playerCommand);

			if (player1.characterClass == "Wizard")
			{
				damageDealt = player1.playerStats.intelligence - dungeon1.enemyList[enemyIndex - 1].enemyStats.fortitude;
			}
			else
			{
				damageDealt = player1.playerStats.strength - dungeon1.enemyList[enemyIndex - 1].enemyStats.fortitude;
			}

			dungeon1.enemyList[enemyIndex - 1].enemyStats.currentHealth -= damageDealt;

			cout << endl << "You have dealt " << damageDealt << " damage to " << dungeon1.enemyList[enemyIndex - 1].enemyName << " " << enemyIndex << endl;

			sleep_for(milliseconds(2000));
		}
		else
		{
			cout << endl << "please enter a valid command" << endl;
		}

		EnemyTurn();

		Clear();

		i = CheckIfEnemiesAreDead();

		ListEnemies();
	}
}

void FirstFloor()
{
	Clear();

	int floor = 1;

	for (int room = 1; room != 6; room++)
	{
		cout << "God - " << player1.name << " has entered room " << floor << " : " << room << endl << endl;

		sleep_for(milliseconds(2000));

		Clear();

		if (floor == 1)
		{
			if (room == 1)
			{
				dungeon1.enemyList[0] = hornedRat1;

				dungeon1.amountOfEnemies = 1;

				ListEnemies();

				Combat();
			}
			else if (room == 2)
			{
				dungeon1.enemyList[0] = hornedRat1;
				dungeon1.enemyList[1] = hornedRat2;

				dungeon1.amountOfEnemies = 2;

				ListEnemies();
				Combat();
			}
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