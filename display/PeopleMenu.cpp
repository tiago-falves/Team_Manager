//
// Created by tiago on 08/11/2019.
//

#include "PeopleMenu.h"

//Prints all information and asks the user what option to choose


void runPeopleMenu() {
    int option;

    cout << "Welcome to the People Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. See information from everyone. " << endl;
    cout << "2. See information from a specific person. " << endl;
    cout << "3. Football Players." << endl;
    cout << "4. Technicians." << endl;
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
    if (option == 1) { /*showEveryone(cout) ;*/ }
    if (option == 2) { runMenu(); }
    if (option == 3) { runPlayersMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }





    //runMenu(clientsVector, travelPacksVector, agency);
}

void runPlayersMenu() {
    int option;

    cout << "Welcome to the players Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. Create a new Football Player." << endl;
    cout << "2. Change a player's information." << endl;
    cout << "3. Remove a player" << endl;
    cout << "6. See all games played by a specific player. " << endl;
    cout << "7. See all call-ups that a player participated. " << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 8)
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
    if (option == 1) { runMenu(); }
    if (option == 2) { runMenu(); }
    if (option == 3) { runMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }
    if (option == 6) { runMenu(); }
    if (option == 7) { runMenu(); }
    if (option == 8) { runMenu(); }

    //runMenu(clientsVector, travelPacksVector, agency);
}
void runTechnicianMenu() {
    int option;

    cout << "Welcome to the players Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. Create a new Technician." << endl;
    cout << "2. Change a technician information." << endl;
    cout << "3. Remove a technician" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 8)
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
    if (option == 1) { runMenu(); }
    if (option == 2) { runMenu(); }
    if (option == 3) { runMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }
    if (option == 6) { runMenu(); }
    if (option == 7) { runMenu(); }
    if (option == 8) { runMenu(); }

    //runMenu(clientsVector, travelPacksVector, agency);
}

void showSpecificClient(){
    int id = askForId();
}