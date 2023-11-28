#pragma once

#include "Main.h"

struct stats //all the stats that are needed for enemies and the player
{
public:
	int maxHealth = 5;
	int currentHealth = 5;

	int maxMana = 5;
	int currentMana = 5;

	int strength = 1;
	int intelligence = 1;
	int charisma = 1;
	int fortitude = 1;
};

struct item
{
public:
	string itemName = "";

	int damage = 0;
	int durability = 100;
	int cost = 0;
};

struct Enemy
{
public:
	string enemyName = "";

	int xpDrop = 0;
	int goldDrop = 0;

	stats enemyStats;
};

struct Dungeon
{
public:
	int amountOfEnemies = 0;

	Enemy enemyList[5];
};

struct Player
{
public:
	bool playerIsAlive = true;

	string name = "";
	string characterClass = "";

	int playerLevel = 1;
	int xp = 0;

	stats playerStats;
	item inventory[5]; //creates and array of items for the player to use as an inventory

	int gold = 10;
};

Player player1;

Enemy emptyEnemySlot;

Enemy hornedRat1;
Enemy hornedRat2;
Enemy hornedRat3;
Enemy hornedRat4;
Enemy hornedRat5;



Dungeon dungeon1;

item emptySlot;
item rustySword;
item shodyBow;
item basicWand;
item healthPotion;
item manaPotion;
