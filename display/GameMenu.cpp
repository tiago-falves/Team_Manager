//
// Created by tiago on 08/11/2019.
//


#include "../NationalTeam.h"

void NationalTeam::runGameMenu() {
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

    if (option == 0) { runMenu(); }
    if (option == 1) { showAllGames(cout); }
    if (option == 2) { runMenu(); }
    if (option == 3) { runMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }





    runMenu();
}

void NationalTeam::tableHeaderAllGames(ostream &out) {
    out << endl << endl << endl;
    out << setw(83) << setfill('-') << "-" <<  endl;
    out <<  left << setw(4)  << setfill(' ') << "id" << "│  ";
    out <<  left << setw(20) << setfill(' ') << "City"  << "│ ";
    out <<  left << setw(11) << setfill(' ') <<  "Country"<< "│ ";
    out <<  left << setw(18)  << setfill(' ') << "Stadium" << "│ ";
    out <<  left << setw(20)  << setfill(' ') << "Game Title" << "│ ";
    out << endl;

}

void NationalTeam::tableFooterAllGames(ostream &out) {
    out << setw(83) << setfill('-') << "-" << endl;
}

void NationalTeam::tableHeaderStatistics(ostream &out) {
    out << endl << endl << endl;
    out << setw(117) << setfill('-') << "-" <<  endl;
    out <<  left << setw(11)  << setfill(' ') << "Player ID" << "│  ";
    out <<  left << setw(15) << setfill(' ') << "Number of Goals"  << "│ ";
    out <<  left << setw(16) << setfill(' ') <<  "Minutes Played"<< "│ ";
    out <<  left << setw(12)  << setfill(' ') << "Kilometers" << "│ ";
    out <<  left << setw(18)  << setfill(' ') << "Number of Passes" << "│ ";
    out <<  left << setw(24)  << setfill(' ') << "Number of Yellow Cards" << "│ ";
    out <<  left << setw(21)  << setfill(' ') << "Number of Red Cards" << "│ ";
    out << setw(117) << setfill('-') << "-" << "│" <<  endl;
}

void NationalTeam::tableFooterStatistics(ostream &out){
    out << setw(117) << setfill('-') << "-" << endl;
}

void NationalTeam::showAllGames(ostream &out) {

    tableHeaderAllGames(out);
    for(Game* g : games){
        g->print(out);
    }

    tableFooterAllGames(out);

}