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

bool AssignItemToSlot(struct item itemObtained, struct Player* player1)
{
    bool fail = true;

    for (int i = 0; i < 5;)
    {
        if (player1->inventory[i].itemName == "Empty")
        {
            player1->inventory[i] = itemObtained;

            cout << endl << itemObtained.itemName << " was stored in slot " << i + 1<< endl;

            fail = false;
            i = 5;
        }

        i++;
    }

    if (fail == true)
    {
        string playerDecision = "";
        int slot = 0;

        cout << endl << "There is no room left in your inventory, do you wish to drop an item to free up space? yes or no";

        for (int i = 0; i != 1;)
        {
            i++;

            cin >> playerDecision;

            if (playerDecision == "yes")
            {
                cout << endl << "Which slot do you wish to empty";

                for (int i = 0; i < 5;)
                {
                    cout << endl << "Slot " << i << ": " << player1->inventory[i].itemName;

                    i++;
                }

                cin >> slot;

                player1->inventory[slot] = itemObtained;

                cout << endl << itemObtained.itemName << " was stored in slot " << slot + 1 << endl;

                fail = false;
            }
            else if (playerDecision == "no")
            {
                cout << endl << "You left the " << itemObtained.itemName << " where it was" << endl;
            }
            else
            {
                cout << endl << "Please enter a valid response";

                i--;
            }
        }
    }

    return fail;
}

void shop(struct item healthPotion, struct item manaPotion, struct Player* player1)
{
    Clear();

    cout << endl << "Merchant - Come here and browse my wares." << endl;

    cout << endl << "1. " << healthPotion.itemName << " " << healthPotion.cost << "g" << endl;
    cout << "2. " << manaPotion.itemName << " " << manaPotion.cost << "g" << endl;

    cout << endl << "Type balence to see your current gold amount or type buy then the number of the item you wish to purchase and when\nyou are finished type exit to leave." << endl;

    for (int i = 0; i != 1;)
    {
        i++;

        string playerDecisionTemp = "";
        string playerDecision = "";
        int end = 0;

        cout << endl << "> ";

        getline(cin, playerDecisionTemp);
        end = playerDecisionTemp.find(" ");

        playerDecision = playerDecisionTemp.substr(0, end);

        if (playerDecision == "balence")
        {
            cout << endl << "You currently have " << player1->gold << " gold." << endl;
            i--;
        }
        else if (playerDecision == "buy")
        {
            playerDecision = playerDecisionTemp.substr(end, (sizeof(playerDecisionTemp) / 4));

            bool purchase = true;

            if (playerDecision == " 1")
            {
                if (player1->gold >= healthPotion.cost)
                {
                    purchase = AssignItemToSlot(healthPotion, player1);

                    if (purchase != false)
                    {
                        player1->gold -= 10;
                    }

                    i--;
                }
                else
                {
                    cout << endl << "You do not have enough gold for this.";

                    i--;
                }
            }
            else if (playerDecision == " 2")
            {
                if (player1->gold >= manaPotion.cost)
                {
                    purchase = AssignItemToSlot(healthPotion, player1);

                    if (purchase != false)
                    {
                        player1->gold -= 10;
                    }

                    i--;
                }
                else
                {
                    cout << endl << "You do not have enough gold for this.";

                    i--;
                }
            }
            else
            {
                cout << endl << "Please enter a valid command." << endl;

                i--;
            }
        }
        else if (playerDecision == "exit")
        {
            cout << endl << "You have left the shop." << endl;
        }
        else
        {
            cout << endl << "Please enter a valid command" << endl;
            cout << "Type balence to see your current gold amount or type buy then the number of the item you wish to purchase." << endl;
            i--;
        }

    }
}

void Awaken(struct Player* player1, struct item healthPotion, struct item manaPotion)
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

            Clear();

            cout << "You have arrived back at your camp where do you want to go now." << endl;

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


