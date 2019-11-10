//
// Created by tiago on 07/11/2019.
//


#include "../NationalTeam.h"

using namespace std;


//Runs the main Menu
void NationalTeam::runMenu() {
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
    validOption(option,5);

    menuSeparator();

    if (option == 0) { exit(0);}
    else if (option == 1) {runPeopleMenu(); }
    else if (option == 2) {runGameMenu(); }
    else if (option == 3) {runCallUpMenu(); }
    else if (option == 4) {runEconomiesMenu(); }
    //else if (option == 5) {saveAndExit(clientsVector, travelPacksVector, agency); }
}

void NationalTeam::validOption(int &option,int optionsNumber){
    while (cin.fail() || option < 0 || option > optionsNumber)
    {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

//Outputs a separator made of *
void NationalTeam::menuSeparator() {
    cout << endl << endl;
    for (int i = 0; i < 70; i++) { cout << "="; }
    cout << endl;
}

//Asks for a valid int until the user inputs it
void NationalTeam::validCin(int &option) {

    while (cin.fail())
    {
        cout << "Invalid input, please insert your answer again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> option;
    }
}

int NationalTeam::askForId(){
    int id;
    cout << "Please Insert an ID: ";
    cin >> id;
    validCin(id);
    return id;
}

string NationalTeam::askForDate(string dateName,string &text){
    cout << dateName << "(DD/MM/YYYY): ";
    cin.clear();
    getline(cin, text);

    while (!Date::validDateText(text))
    {
        cout << "Invalid date, please insert again: ";
        getline(cin, text);
    }
    return text;
}