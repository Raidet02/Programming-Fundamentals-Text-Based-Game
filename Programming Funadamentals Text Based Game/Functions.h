#pragma once

#include "Main.h"

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

int CheckIfValidNumber(int maxNum)
{
    int convertedNumber = 0;
    string numberToBeChecked;

    for (int i = 0; i != 1;)
    {
        i++;

        cout << endl << "> ";
        cin >> numberToBeChecked;

        try
        {
            convertedNumber = stoi(numberToBeChecked);

            if (convertedNumber < 1 || convertedNumber > maxNum)
            {
                cout << endl << "Please enter a valid number " << endl;
                i--;
            }
        }
        catch (...)
        {
            cout << endl << "Please enter a valid number " << endl;
            i--;
        }
    }

    return convertedNumber;
}

void BeginPlay(struct Player* player, struct item* empty, struct item* rustySword, struct item* shodyBow, struct item* basicWand , struct item* manaPotion, struct item* healthPotion)
{
    empty->itemName = "Empty";
    rustySword->damage = 2;
    shodyBow->damage = 2;
    basicWand->damage = 2;

    manaPotion->itemName = "Mana Potion";
    healthPotion->itemName = "Health Potion";

    manaPotion->cost = 10;
    healthPotion->cost = 10;

    manaPotion->durability = 1;
    healthPotion->durability = 1;

    for (int i = 0; i < 5;)
    {
        player->inventory[i] = *empty;
        i++;
    }
}

void PrintStats(struct Player* player1)
{
    cout << endl << "Your current stats are: " << endl;
    cout << "- Health " << player1->playerStats.currentHealth << " / " << player1->playerStats.maxHealth << endl;
    cout << "- Mana " << player1->playerStats.currentMana << " / " << player1->playerStats.maxMana << endl;
    cout << "- Strength " << player1->playerStats.strength << endl;
    cout << "- Intelligence " << player1->playerStats.intelligence << endl;
    cout << "- Charisma " << player1->playerStats.charisma << endl;
    cout << "- Fortitude " << player1->playerStats.fortitude << endl;
}

void shop(struct item* healthPotion, struct item* manaPotion, struct Player* player1)
{
    Clear();

    cout << endl << "Merchant - Come here and browse my wares." << endl;

    cout << "1. " << healthPotion->itemName << " " << healthPotion->cost << "g" << endl;
    cout << "2. " << manaPotion->itemName << " " << manaPotion->cost << "g" << endl;

    cout << endl << "Type balence to see your current gold amount or type buy then the number of the item you wish to purchase." << endl;

    for (int i = 0; i != 1;)
    {
        i++;

        string playerDecisionTemp = "";
        string playerDecision = "";
        int end = 0;

        getline(cin, playerDecisionTemp);
        end = playerDecisionTemp.find(" ");

        playerDecision = playerDecisionTemp.substr(0, end);

        if (playerDecision == "gold")
        {
            //show the players gold
        }
        else if (playerDecision == "buy")
        {
            playerDecision = playerDecisionTemp.substr(end, (sizeof(playerDecisionTemp) / 4));

            if (playerDecision == "1")
            {
                //set the item to an empty slot
            }
            else if (playerDecision == "2")
            {
                //set the item to an empty slot
            }
        }
        else
        {
            cout << "Please enter a valid command" << endl;
            cout << "Type balence to see your current gold amount or type buy then the name of the item you wish to purchase." << endl;
        }

    }
}

void Awaken(struct Player* player1, struct item* healthPotion, struct item* manaPotion)
{
    string playersDecision = "";

    player1->playerStats.currentHealth = player1->playerStats.maxHealth;
    player1->playerStats.currentMana = player1->playerStats.maxMana;

    cout << "God - " << player1->name << " awakens inside their tent.\nYou walk outside and the sun is shinig.\nWhat do you wish to do?" << endl;

    for (int i = 0; i != 1;)
    {
        i++;

        cout << endl << "> ";
        getline(cin, playersDecision);

        if (playersDecision == "dungeon")
        {

        }
        else if (playersDecision == "shop")
        {
            shop(healthPotion, manaPotion, player1);
            i--;
        }
        else if (playersDecision == "commands")
        {
            cout << endl << "dungeon - This will start a dungeon crawl.\nshop - This will open the shop menu." << endl;
            i--;
        }
        else
        {
            cout << endl << "please enter a valid command \nFor a list of valid commands type commands" << endl;
            i--;
        }
    }
}


