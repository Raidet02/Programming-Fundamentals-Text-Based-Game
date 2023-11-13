#pragma once

#include "Main.h"

void inventorySystem()
{
    while (exit == false) //the game loop
    {
        cout << endl << "> ";
        getline(cin, playerCommandTemp); //gets the players command

        int end = playerCommandTemp.find(" "); //seperates the string into the intial command and index values
        int stringSize = sizeof(playerCommandTemp) / 4;

        playerCommand = playerCommandTemp.substr(0, end);

        
        if (playerCommand == "show_all") //lists theplayers inventory
        {
            cout << endl << "> inventory:" << endl;
            for (int i = 0; i < inventorySize; i++)
            {
                cout << "- Slot " << i << ": " << inventory[i] << endl;
            }
        }
        else if (playerCommand == "view") //shows a specific inventory slot
        {
            indexValueS1 = playerCommandTemp.substr(end, stringSize - end); //gets the index value from the initail command
            validCheck = 0;

            try //checks if the index value is valid
            {
                indexValue1 = stoi(indexValueS1);
            }
            catch (...)
            {
                cout << endl << "Not a proper index" << endl;
                validCheck = 1;
            }

            if (validCheck != 1) //if the index value is valid runs the code
            {
                indexValue1 = stoi(indexValueS1);

                if (indexValue1 > inventorySize - 1 || indexValue1 < 0)
                {
                    cout << "The index value does not exist" << endl;
                }
                else
                {
                    cout << endl << "> Inventory Slot " << indexValue1 << " information:" << endl << "Name: " << inventory[indexValue1] << endl;
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

