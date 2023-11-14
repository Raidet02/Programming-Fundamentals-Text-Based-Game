
#include "main.h"

int main()
{
    Player player1;

    item empty;
    item rustySword;
    item shodyBow;
    item basicWand;
    item healthPotion;
    item manaPotion;

    BeginPlay(&player1, &empty, &rustySword, &shodyBow, &basicWand, &manaPotion, &healthPotion);

    string classes[3];
    classes[0] = "Swordsman";
    classes[1] = "Archer";
    classes[2] = "Wizard";

    item items[4];
    items[0] = empty;
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

    sleep_for(milliseconds(3000));

    Clear();*/

    cout << "This is the character selection menu. Please enter a name: ";
    getline(cin, player1.name);

    cout << "Next please enter the number of the class you wish to play: " << endl;

    cout << endl << "1. " << classes[0] << endl << "2. " << classes[1] << endl << "3. " << classes[2] << endl;

    player1.characterClass = classes[CheckIfValidNumber(3) - 1];

    if (player1.characterClass == "Swordsman")
    {
        player1.inventory[0] = items[1];
        player1.playerStats.strength += 1;
        player1.playerStats.fortitude += 2;
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

    PrintStats(&player1);

    sleep_for(milliseconds(3000));

    Clear();

    CinIgnore();

    Awaken(&player1, healthPotion, manaPotion, empty);
}
