
#include "main.h"

int main()
{
    BeginPlay(); 

    bool exitGame = false; //bool that controls the basic game loop

    string classes[3]; //an array for the three basic classes
    classes[0] = "Swordsman";
    classes[1] = "Archer";
    classes[2] = "Wizard";

    item items[4]; //an array of struct item for the items in the game
    items[0] = emptySlot;
    items[1] = rustySword;
    items[2] = shodyBow;
    items[3] = basicWand;

    cout << " _______   ______   _    _   _______         ___     _______   _______     ___       ______    _   _\n";           //outputs the ASCII art to the console periodically 
    sleep_for(milliseconds(1000));
    cout << "|__   __| |  ____| \\ \\  / / |__   __|       / _ \\   |__   __| |__   __|   / _ \\     /  ____|  | | / /\n";
    sleep_for(milliseconds(1000));
    cout << "   | |    | |____   \\ \\/ /     | |         / / \\ \\     | |       | |     / / \\ \\    | |       | |/ /\n";
    sleep_for(milliseconds(1000));
    cout << "   | |    |  ____|  |    |     | |        / /___\\ \\    | |       | |    / /___\\ \\   | |       | | |\n";
    sleep_for(milliseconds(1000));
    cout << "   | |    | |____   / /\\ \\     | |       /  _____  \\   | |       | |   /  _____  \\  | |____   | |\\ \\\n";
    sleep_for(milliseconds(1000));
    cout << "   |_|    |______| /_/  \\_\\    |_|      /_/       \\_\\  |_|       |_|  /_/       \\_\\ \\______|  |_| \\_\\\n";

    sleep_for(milliseconds(3000));

    Clear();

    cout << "This is the character selection menu.\n" << endl << "Please enter a name: "; //asks the player for their name and sets it to the player1 struct
    getline(cin, player1.name);

    cout << endl << "Next please enter the number of the class you wish to play: " << endl; //asks the player for the class they wish to play

    cout << endl << "1. " << classes[0] << endl << "2. " << classes[1] << endl << "3. " << classes[2] << endl; //lists the classes

    player1.characterClass = classes[CheckIfValidNumber(3) - 1];

    if (player1.characterClass == "Swordsman") //adds the stats and items for the class that was chosen
    {
        player1.inventory[0] = items[1];
        player1.playerStats.strength += 2;
        player1.playerStats.fortitude += 1;
    }
    else if (player1.characterClass == "Archer")
    {
        player1.inventory[0] = items[2];
        player1.playerStats.strength += 2;
        player1.playerStats.charisma += 1;
    }
    else if (player1.characterClass == "Wizard")
    {
        player1.inventory[0] = items[3];
        player1.playerStats.intelligence += 3;
    }

    PrintStats();

    sleep_for(milliseconds(3000));

    CinIgnore();

    while (exitGame == false) //starts the game loop
    {
        if (player1.playerIsAlive == false) //checks if the player is dead and if so revives them 
        {
            player1.playerIsAlive = true;

            cout << "God - You have been revived, forward unto dawn.";

            sleep_for(milliseconds(1500));
        }

        player1.playerStats.currentHealth = player1.playerStats.maxHealth; //resets health and mana
        player1.playerStats.currentMana = player1.playerStats.maxMana;

        Clear();

        string playersDecision = "";

        player1.playerStats.currentHealth = player1.playerStats.maxHealth;
        player1.playerStats.currentMana = player1.playerStats.maxMana;

        cout << "God - " << player1.name << " awakens inside their tent.\nYou walk outside and the sun is shinig.\nWhat do you wish to do?" << endl; //asks the player what they want to do

        for (int i = 0; i != 1;)
        {
            i++;

            cout << endl << "> ";
            getline(cin, playersDecision);

            if (playersDecision == "dungeon") //starts the dungeon crawl
            {
                DungeonDive();
            }
            else if (playersDecision == "shop") //opens the shop
            {
                shop();

                Clear();

                cout << "You have arrived back at your camp where do you want to go now." << endl;

                i--;
            }
            else if (playersDecision == "inventory") //opens the inventory
            {
                InventorySystem();

                cout << endl << "You have exited your inventory, where do you wish to go now." << endl;

                i--;
            }
            else if (playersDecision == "quit") //exits the game
            {
                exitGame = true;
            }
            else if (playersDecision == "commands") //lists the commands
            {
                cout << endl << "dungeon - This will start a dungeon crawl.\nshop - This will open the shop menu.\ninventory - This will open the inventory menu.\nquit - This will exit the whole game" << endl;
                i--;
            }
            else //asks for a valid command to be input
            {
                cout << endl << "please enter a valid command \nFor a list of valid commands type commands" << endl;
                i--;
            }
        }
    }
}
