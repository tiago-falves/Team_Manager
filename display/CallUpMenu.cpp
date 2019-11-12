//
// Created by tiago on 08/11/2019.
//


#include "../NationalTeam.h"

void NationalTeam::runCallUpMenu() {
    int option;

    while(true) {
        cout << "Welcome to the Call Up menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "See information from all Call Ups.                                 [1]" << endl;
        cout << "See information from a specific call up.                           [2]" << endl;
        cout << "Create new Call up.                                                [3]" << endl;
        cout << "Remove Call Up.                                                    [4]" << endl;
        cout << "Modify Call Up.                                                    [5]" << endl;
        cout << "Add Game to Call Up.                                               [6]" << endl;
        cout << "Remove Game from Call Up.                                          [7]" << endl;
        cout << "Modify Call Up.                                                    [8]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 8);

        cin.clear();
        cin.ignore(10000, '\n');

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { runMenu(); }
        if (option == 2) { runMenu(); }
        if (option == 3) { runMenu(); }
        if (option == 4) { runMenu(); }
        if (option == 5) { runMenu(); }
    }
}