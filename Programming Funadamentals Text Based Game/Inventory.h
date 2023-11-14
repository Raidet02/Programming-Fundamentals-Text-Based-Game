#pragma once

#include "Main.h"

/*void InventorySystem(struct Player* player1)
{
    bool exit = false;
    string playerCommand = "";
    string playerCommandTemp = "";
    int indexValue = 0;

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

            for (int i = 0; i <= 5 ;)
            {
                cout << "- Slot " << i << ": " << player1->inventory[i].itemName << endl;

                i++;
            }
        }
        else if (playerCommand == "view") //shows a specific inventory slot
        {
            playerCommand = playerCommandTemp.substr(end, stringSize - end); //gets the index value from the initail command
            
            indexValue = CheckIfValidNumber(playerCommand);

            indexValue = CheckIfInBoundsOfInventory(indexValue);
            
            cout << endl << "> Inventory Slot " << indexValue << " information:" << endl << "Name: " << player1->inventory[indexValue].itemName << endl;
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
}*/

