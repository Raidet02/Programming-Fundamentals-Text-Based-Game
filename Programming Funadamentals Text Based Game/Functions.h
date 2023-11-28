#pragma once

#include "Main.h"

void CinIgnore() 
{
    cin.clear();
    cin.ignore();
}

void Clear() //clears the console (moves it up so the player can scroll up if they missed somthing)
{
    cout << "\x1B[2J\x1B[H";
}

int CheckIfValidNumber(int maxNum) //checks for a valid number input and takes an int as a parameter
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

int CheckIfValidNumber(string ToBeChecked) //checks for a valid number input and takes a atring as a parameter (overloaded)
{
    int returnValue = 0;
    bool firstLoop = true;

    for (int i = 0; i != 1;)
    {
        i++;

        if (firstLoop == false)
        {
            cout << endl << "> ";
            cin >> ToBeChecked;
        }

        try
        {
            returnValue = stoi(ToBeChecked);
        }
        catch (...)
        {
            cout << endl << "Please enter a valid number " << endl;
            i--;
        }

        firstLoop = false;
    }

    returnValue = stoi(ToBeChecked);

    return returnValue;
}

int CheckIfInBoundsOfInventory(int toBeChecked) //checks if the index is of the inventory size
{
    for (int i = 0; i != 1;)
    {
        i++;

        if (toBeChecked > 5 || toBeChecked < 1)
        {
            string temp = "";

            cout << endl << "Please enter a numeber between 1 and " << 5 << "." << endl;
            cout << endl << "> ";

            cin >> temp;

            toBeChecked = CheckIfValidNumber(temp);

            i--;

            CinIgnore();
        }
    }

    return toBeChecked;
}

void InventorySystem() //allows the player to interact with their inventory
{
    bool exit = false;
    string playerCommand = "";
    string playerCommandTemp = "";
    int indexValue = 0;

    cout << endl << "You are inside your inventory type: " << endl << "Show_all - To show the whole inventory" << endl << "view (index) - To show whats in that specific spot" << endl << "exit - To leave your inevtory" << endl; //lists inventory commands

    while (exit == false) //the inventory loop
    {
        cout << endl << "> ";
        getline(cin, playerCommandTemp); //gets the players command

        int end = playerCommandTemp.find(" "); //seperates the string into the intial command and index values
        int stringSize = sizeof(playerCommandTemp) / 4;

        playerCommand = playerCommandTemp.substr(0, end);


        if (playerCommand == "show_all") //lists theplayers inventory
        {
            cout << endl << "> inventory:" << endl;

            for (int i = 0; i < 5;)
            {
                cout << "- Slot " << i + 1 << ": " << player1.inventory[i].itemName << endl;

                i++;
            }
        }
        else if (playerCommand == "view") //shows a specific inventory slot
        {
            playerCommand = playerCommandTemp.substr(end, stringSize - end); //gets the index value from the initail command

            indexValue = CheckIfValidNumber(playerCommand);

            indexValue = CheckIfInBoundsOfInventory(indexValue);

            cout << endl << "> Inventory Slot " << indexValue << " information:" << endl << "Name: " << player1.inventory[indexValue - 1].itemName << endl;
        }
        else if (playerCommand == "destroy") //destroys the item of that index
        {
            cout << endl << "Destroyed items cannot be regained, are you sure you want to destroy this item?" << endl; //asks the player if they want to destroy the item

            for (int i = 0; i != 1;)
            {
                i++;

                cout << endl << "> ";
                cin >> playerCommand;

                if (playerCommand == "yes")
                {
                    playerCommand = playerCommandTemp.substr(end, stringSize - end);

                    indexValue = CheckIfValidNumber(playerCommand);

                    indexValue = CheckIfInBoundsOfInventory(indexValue);

                    if (player1.inventory[indexValue - 1].itemName == "Empty") //checks if there is an item to drop if so drops it
                    {
                        cout << endl << "There was nothing to drop" << endl;

                        CinIgnore();
                    }
                    else
                    {
                        cout << endl << "You have dropped " << player1.inventory[indexValue - 1].itemName << " on the floor." << endl;

                        player1.inventory[indexValue - 1] = emptySlot;

                        CinIgnore();
                    }
                }
                else if (playerCommand == "no")
                {
                    cout << endl << "You have chosen to spare this item." << endl;
                }
                else
                {
                    cout << endl << "Please enter a valid command" << endl;

                    i--;
                }
            }
        }
        else if (playerCommand == "exit") //exists the inventory tool
        {
            exit = true;
        }
        else //if anything other than a correct comand is inputed it will tell the player
        {
            cout << endl << "Please enter a valid command" << endl;
        }
    }
}

void BeginPlay() //sets the variables of different instances and sets inventory to empty
{
    emptySlot.itemName = "Empty";
    rustySword.damage = 2;
    shodyBow.damage = 2;
    basicWand.damage = 2;

    manaPotion.itemName = "Mana Potion";
    healthPotion.itemName = "Health Potion";
    rustySword.itemName = "Rusty Sword";
    shodyBow.itemName = "Shody Bow";
    basicWand.itemName = "Basic Wand";

    manaPotion.cost = 10;
    healthPotion.cost = 10;

    manaPotion.durability = 1;
    healthPotion.durability = 1;

    hornedRat1.enemyStats.strength = 3;
    hornedRat1.goldDrop = 5;
    hornedRat1.xpDrop = 50;
    hornedRat1.enemyName = "Horned Rat";

    hornedRat2.enemyStats.strength = 3;
    hornedRat2.goldDrop = 5;
    hornedRat2.xpDrop = 50;
    hornedRat2.enemyName = "Horned Rat";

    hornedRat3.enemyStats.strength = 3;
    hornedRat3.goldDrop = 5;
    hornedRat3.xpDrop = 50;
    hornedRat3.enemyName = "Horned Rat";

    hornedRat4.enemyStats.strength = 3;
    hornedRat4.goldDrop = 5;
    hornedRat4.xpDrop = 50;
    hornedRat4.enemyName = "Horned Rat";

    hornedRat5.enemyStats.strength = 3;
    hornedRat5.goldDrop = 5;
    hornedRat5.xpDrop = 50;
    hornedRat5.enemyName = "Horned Rat";

    emptyEnemySlot.enemyName = "Empty";

    for (int i = 0; i < 5;)
    {
        dungeon1.enemyList[i] = emptyEnemySlot;

        i++;
    }

    
    for (int i = 0; i < 5;)
    {
        player1.inventory[i] = emptySlot;
        i++;
    }
}

void PrintStats() //prints the players stats
{
    cout << endl << "Your current stats are: " << endl;
    cout << "- Health " << player1.playerStats.currentHealth << " / " << player1.playerStats.maxHealth << endl;
    cout << "- Mana " << player1.playerStats.currentMana << " / " << player1.playerStats.maxMana << endl;
    cout << "- Strength " << player1.playerStats.strength << endl;
    cout << "- Intelligence " << player1.playerStats.intelligence << endl;
    cout << "- Charisma " << player1.playerStats.charisma << endl;
    cout << "- Fortitude " << player1.playerStats.fortitude << endl;
}

bool AssignItemToSlot(struct item itemObtained) //assigns item to a spot in the players inventory 
{
    bool fail = true;

    for (int i = 0; i < 5;) //if the slot is empty assigns the item and doesn't fail
    {
        if (player1.inventory[i].itemName == "Empty")
        {
            player1.inventory[i] = itemObtained;

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

        cout << endl << "There is no room left in your inventory, do you wish to drop an item to free up space? yes or no"; //asks the player if they want to dropm an item

        for (int i = 0; i != 1;)
        {
            i++;

            cin >> playerDecision;

            if (playerDecision == "yes") //drops an item of the indexed slot
            {
                cout << endl << "Which slot do you wish to empty";

                for (int i = 0; i < 5;)
                {
                    cout << endl << "Slot " << i << ": " << player1.inventory[i].itemName;

                    i++;
                }

                cin >> slot;

                player1.inventory[slot] = itemObtained;

                cout << endl << itemObtained.itemName << " was stored in slot " << slot + 1 << endl; //sets the item to the indexed slot

                fail = false;
            }
            else if (playerDecision == "no")
            {
                cout << endl << "You left the " << itemObtained.itemName << " where it was" << endl;
            }
            else //error check
            {
                cout << endl << "Please enter a valid response";

                i--;
            }
        }
    }

    return fail;
}

void shop()
{
    Clear();

    cout << "Merchant - Come here and browse my wares." << endl; //lists the items and their costs

    cout << endl << "1. " << healthPotion.itemName << " " << healthPotion.cost << "g" << endl;
    cout << "2. " << manaPotion.itemName << " " << manaPotion.cost << "g" << endl;

    cout << endl << "Type:" << endl << "balence - To see how much gold you have." << endl << "buy (index) - to buy that item" << endl << "exit - To leave the shop" << endl; //lists the commands

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

        if (playerDecision == "balence") //shows the players gold amount
        {
            cout << endl << "You currently have " << player1.gold << " gold." << endl;
            i--;
        }
        else if (playerDecision == "buy") //buy an item of the index value
        {
            playerDecision = playerDecisionTemp.substr(end, (sizeof(playerDecisionTemp) / 4));

            bool purchase = true;

            if (playerDecision == " 1")
            {
                if (player1.gold >= healthPotion.cost)
                {
                    purchase = AssignItemToSlot(healthPotion);

                    if (purchase == false)
                    {
                        player1.gold -= healthPotion.cost;
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
                if (player1.gold >= manaPotion.cost)
                {
                    purchase = AssignItemToSlot(healthPotion);

                    if (purchase == false)
                    {
                        player1.gold -= manaPotion.cost;
                    }

                    i--;
                }
                else
                {
                    cout << endl << "You do not have enough gold for this." << endl;

                    i--;
                }
            }
            else //error check
            {
                cout << endl << "Please enter a valid command." << endl;

                i--;
            }
        }
        else if (playerDecision == "exit") //exits shop
        {
            cout << endl << "You have left the shop." << endl;
        }
        else //error check
        {
            cout << endl << "Please enter a valid command" << endl;
            cout << endl << "Type:" << endl << "balence - To see how much gold you have." << endl << "buy (index) - to buy that item" << endl << "exit - To leave the shop" << endl; //lists the commands
            i--;
        }

    }
}

bool Awaken(bool exitGame) //the spawn
{
    Clear();

    string playersDecision = "";

    player1.playerStats.currentHealth = player1.playerStats.maxHealth; //sets Health and Mana to max
    player1.playerStats.currentMana = player1.playerStats.maxMana;

    cout << "God - " << player1.name << " awakens inside their tent.\nYou walk outside and the sun is shinig.\nWhat do you wish to do?" << endl; //asks the player what they wish to do

    for (int i = 0; i != 1;)
    {
        i++;

        cout << endl << "> ";
        getline(cin, playersDecision);

        if (playersDecision == "dungeon") //if dungeon is selected it ends awaken
        {
            
        }
        else if (playersDecision == "shop") //runs the shop function
        {
            shop();

            Clear();

            cout << "You have arrived back at your camp where do you want to go now." << endl;

            i--;
        }
        else if (playersDecision == "inventory") //runs the inventory function
        {
            InventorySystem();

            cout << endl << "You have exited your inventory, where do you wish to go now." << endl;

            i--;
        }
        else if (playersDecision == "quit") //quits the game
        {
            exitGame = true;
        }
        else if (playersDecision == "commands") //lists commands
        {
            cout << endl << "dungeon - This will start a dungeon crawl.\nshop - This will open the shop menu.\ninventory - This will open the inventory menu.\nquit - This will exit the whole game" << endl;
            i--;
        }
        else //error check
        {
            cout << endl << "please enter a valid command \nFor a list of valid commands type commands" << endl;
            i--;
        }
    }

    return exitGame;
}
