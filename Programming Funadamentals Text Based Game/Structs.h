#pragma once

#include "Main.h"

struct stats
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
	string name = "";
	string characterClass = "";

	int playerLevel = 1;
	int xp = 0;

	stats playerStats;
	item inventory[5];

	int gold = 10;
};
