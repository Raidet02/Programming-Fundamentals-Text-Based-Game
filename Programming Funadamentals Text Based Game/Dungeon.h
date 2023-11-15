#pragma once

#include "Main.h"

void FirstFloor()
{
	int floor = 1;

	for (int room = 0; room != 6; room++)
	{
		cout << endl << "God - " << player1->name << " has entered room " << floor << " : " << room << endl;

		if (floor == 1)
		{
			if (room == 1)
			{
				dungeon1->enemyList[0] = hornedRat(1);
			}
			else if (room == 2)
			{

			}
		}
	}
}

void spawn(int floor, int room)
{
	if (floor == 1)
	{
		if (room == 1)
		{

		}
		else if (room == 2)
		{

		}
	}
}