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
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 7);

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { cout << "GOT IN" << endl; allCallUpMenu(); break;}
        if (option == 2) { /*callUpMenu();*/ }
        if (option == 3) { /*createCallUpMenu();*/ }
        if (option == 4) { /*removeCallUpMenu();*/ }
        if (option == 5) { /*modifyCallMenu();*/ }
        if (option == 6) { /*addGameCallUpMenu();*/ }
        if (option == 7) { /*removeGameCallUpMenu();*/ }

    }
}

void NationalTeam::headerCallUp(ostream &out) {
    out << endl << endl << endl;
    out << setw(55) << setfill('-') << "-" <<  endl;
    out <<  left << setw(5)  << setfill(' ') << "ID" << "│  ";
    out <<  left << setw(8)  << setfill(' ') << "Begin date" << "│  ";
    out <<  left << setw(10) << setfill(' ') << "End date"  << "│ ";
    out <<  left << setw(20) << setfill(' ') <<  "List of games"<< "│ ";
    out << endl;
}

void NationalTeam::allCallUpMenu() {
    headerCallUp(cout);
    for (auto i = callUps.begin(); i != callUps.end(); i++){
        (*i)->showCallUp(cout);
    }
}