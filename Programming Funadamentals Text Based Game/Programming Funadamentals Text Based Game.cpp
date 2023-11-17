
#include "main.h"

int main()
{
    BeginPlay();

    bool exitGame = false;

    string classes[3];
    classes[0] = "Swordsman";
    classes[1] = "Archer";
    classes[2] = "Wizard";

    item items[4];
    items[0] = emptySlot;
    items[1] = rustySword;
    items[2] = shodyBow;
    items[3] = basicWand;

    /*cout << " _______   ______   _    _   _______         ___     _______   _______     ___       ______    _   _\n";           //outputs the ASCII art to the console
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

    sleep_for(milliseconds(3000));*/

    Clear();

    cout << "This is the character selection menu.\n" << endl << "Please enter a name: ";
    getline(cin, player1.name);

    cout << endl << "Next please enter the number of the class you wish to play: " << endl;

    cout << endl << "1. " << classes[0] << endl << "2. " << classes[1] << endl << "3. " << classes[2] << endl;

    player1.characterClass = classes[CheckIfValidNumber(3) - 1];

    if (player1.characterClass == "Swordsman")
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

    while (exitGame == false)
    {
        if (player1.playerIsAlive == false)
        {
            player1.playerIsAlive = true;

            cout << "God - You have been revived, forward unto dawn.";

            sleep_for(milliseconds(1500));
        }

        player1.playerStats.currentHealth = player1.playerStats.maxHealth;
        player1.playerStats.currentMana = player1.playerStats.maxMana;

        Clear();

        string playersDecision = "";

        player1.playerStats.currentHealth = player1.playerStats.maxHealth;
        player1.playerStats.currentMana = player1.playerStats.maxMana;

        cout << "God - " << player1.name << " awakens inside their tent.\nYou walk outside and the sun is shinig.\nWhat do you wish to do?" << endl;

        for (int i = 0; i != 1;)
        {
            i++;

            cout << endl << "> ";
            getline(cin, playersDecision);

            if (playersDecision == "dungeon")
            {
                DungeonDive();
            }
            else if (playersDecision == "shop")
            {
                shop();

                Clear();

                cout << "You have arrived back at your camp where do you want to go now." << endl;

                i--;
            }
            else if (playersDecision == "inventory")
            {
                InventorySystem();

                cout << endl << "You have exited your inventory, where do you wish to go now." << endl;

                i--;
            }
            else if (playersDecision == "quit")
            {
                exitGame = true;
            }
            else if (playersDecision == "commands")
            {
                cout << endl << "dungeon - This will start a dungeon crawl.\nshop - This will open the shop menu.\ninventory - This will open the inventory menu.\nquit - This will exit the whole game" << endl;
                i--;
            }
            else
            {
                cout << endl << "please enter a valid command \nFor a list of valid commands type commands" << endl;
                i--;
            }
        }
    }
}
