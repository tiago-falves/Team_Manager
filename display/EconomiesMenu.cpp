//
// Created by digas on 09/11/2019.
//


#include <iomanip>
#include "EconomiesMenu.h"


void runEconomiesMenu(){

    //OPTION TO GO BACK IS MISSING
    cout << "Exit                                                               [0]" << endl;
    cout << "Costs associated with one player in a determined month.            [1]" << endl;
    cout << "Costs associated with one player between two dates.                [2]" << endl;
    cout << "Costs associated with full team in a determined month.             [3]" << endl;
    cout << "Costs associated with full team between two dates.                 [4]" << endl;
    cout << "Costs associated with team and staff in a determined month.        [5]" << endl;
    cout << "Costs associated with team and staff between two dates.            [6]" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 6)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    menuSeparator();

    if (option == 0) { exit(0);}
    else if (option == 1) {playerMonthMenu();}
    else if (option == 2) {playerTimeMenu();}
    else if (option == 3) {teamMonthMenu();}
    else if (option == 4) {teamTimeMenu();}
    else if (option == 5) {staffMonthMenu();}
    else if (option == 6) {staffTimeMenu();}
}

void playerMonthMenu(){
    //verify that the given ID is valid
    if (players.size() < playerID) {
        //throw exception that player does not exist - need to implement
    }
    //shows player so that user can confirm that it is checking the right player
    players[playerID-1]->print(cout);

    int option;
    cout << "Exit.                                                               [0]" << endl;
    cout << "Go back.                                                            [1]" << endl;
    cout << "Confirm operation.                                                  [2]" << endl;
    cin >> option;

    while (cin.fail() || option < 0 || option > 2)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    menuSeparator();

    if (option == 0) exit(0);
    else if (option == 1) {//go back}
    else if (option == 2) {//call month function}
}

void playerTimeMenu(){
    //verify that the given ID is valid
    if (players.size() < playerID) {
        //throw exception that player does not exist - need to implement
    }
    //shows player so that user can confirm that it is checking the right player
    players[playerID-1]->print(cout);

    int option;
    cout << "Exit.                                                               [0]" << endl;
    cout << "Go back.                                                            [1]" << endl;
    cout << "Confirm operation.                                                  [2]" << endl;
    cin >> option;

    while (cin.fail() || option < 0 || option > 2)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
    cin.clear();
    cin.ignore(10000, '\n');
    menuSeparator();

    if (option == 0) exit(0);
    else if (option == 1) {}//go back
    else if (option == 2) {}/*call between two dates function*/
}
