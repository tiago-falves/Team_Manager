//
// Created by tiago on 08/11/2019.
//

#include "CallUpMenu.h"

void runCallUpMenu(NationalTeam &team) {
    int option;

    cout << "Welcome to the Call Up menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. See information from all Call Ups. " << endl;
    cout << "2. See information from a specific call up. " << endl;
    cout << "3. Create new Call up." << endl;
    cout << "4. Remove Call Up" << endl;
    cout << "5. Modify Call Up" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 5)
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