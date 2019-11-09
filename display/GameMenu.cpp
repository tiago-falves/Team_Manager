//
// Created by tiago on 08/11/2019.
//

#include "GameMenu.h"

void runGameMenu(NationalTeam &team) {
    int option;

    cout << "Welcome to the Game Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. See information from all games. " << endl;
    cout << "2. See information from a specific game. " << endl;
    cout << "2. See information from a specific game for a specific player. " << endl;
    cout << "3. Create new game." << endl;
    cout << "4. Remove Game" << endl;
    cout << "5. Modify Game" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 3)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }

    cin.clear();
    cin.ignore(10000, '\n');

    menuSeparator();

    if (option == 0) { runMenu(team); }
    if (option == 1) { runMenu(team); }
    if (option == 2) { runMenu(team); }
    if (option == 3) { runMenu(team); }
    if (option == 4) { runMenu(team); }
    if (option == 5) { runMenu(team); }





    //runMenu(clientsVector, travelPacksVector, agency);
}