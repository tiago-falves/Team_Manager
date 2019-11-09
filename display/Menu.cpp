//
// Created by tiago on 07/11/2019.
//

#include "Menu.h"
#include "PeopleMenu.h"
#include "GameMenu.h"
#include "CallUpMenu.h"
#include "EconomiesMenu.h"

using namespace std;


//Runs the main Menu
void runMenu(/*NationalTeam &team*/) {
    int option;

    menuSeparator();

    cout << "Welcome to the National Football Team Manager! What do you want to do?" << endl << endl;
    cout << "Please choose what your option:" << endl << endl;

    cout << "Exit                                                               [0]" << endl;
    cout << "People                                                             [1]" << endl;
    cout << "Games                                                              [2]" << endl;
    cout << "Call Ups                                                           [3]" << endl;
    cout << "Economies                                                          [4]" << endl;
    cout << "Save information and Exit                                          [5]" << endl << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    while (cin.fail() || option < 0 || option > 4)
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
    else if (option == 1) {runPeopleMenu(); }
    else if (option == 2) {runGameMenu(); }
    else if (option == 3) {runCallUpMenu(); }
    else if (option == 4) {runEconomiesMenu(); }
    //else if (option == 5) {saveAndExit(clientsVector, travelPacksVector, agency); }
}

//Outputs a separator made of *
void menuSeparator() {
    cout << endl << endl;
    for (int i = 0; i < 70; i++) { cout << "="; }
    cout << endl;
}

//Asks for a valid int until the user inputs it
void validCin(int &option) {

    while (cin.fail())
    {
        cout << "Invalid input, please insert your answer again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
}