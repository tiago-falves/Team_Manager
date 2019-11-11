//
// Created by digas on 09/11/2019.
//


#include <iomanip>
#include "../NationalTeam.h"


void NationalTeam::runEconomiesMenu() {
    int option;

    while (true){

        menuSeparator();

        cout << "Welcome to the Economies Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "Costs associated with one player in a determined month.            [1]" << endl;
        cout << "Costs associated with one player between two dates.                [2]" << endl;
        cout << "Costs associated with full team in a determined month.             [3]" << endl;
        cout << "Costs associated with full team between two dates.                 [4]" << endl;
        cout << "Costs associated with team and staff in a determined month.        [5]" << endl;
        cout << "Costs associated with team and staff between two dates.            [6]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 6);
        menuSeparator();

        if (option == 0) { break; }
        else if (option == 1) {playerMonthMenu(); }
        else if (option == 2) {/*playerTimeMenu();*/ }
        else if (option == 3) {/*teamMonthMenu();*/}
        else if (option == 4) {/*teamTimeMenu();*/}
        else if (option == 5) {/*staffMonthMenu();*/}
        else if (option == 6) {/*staffTimeMenu();*/}

    }
}

void NationalTeam::playerMonthMenu(){

    int playerID, option, month, year;
    menuSeparator();

    while (true){

        //GET ID OF PLAYER
        cout << "Insert the ID of the player information will be taken from: ";
        cin >> playerID;

        try{
            searchByID(players, playerID);
        }
        catch(InexistentId){
            cout << "There is no player with the given ID!";
            break;
        }

        if (cin.fail()){
            cout << "Invalid operation, ID is an integer number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');

        //GET MONTH NUMBER
        cout << "Insert the number of the month: ";
        cin >> month;

        try{
            if(month < 0 || month > 12) throw InvalidMonth(month);
        }
        catch(InvalidMonth) {
            cout << "Month number has to be between 1 and 12!" << endl;
            break;
        }

        if(cin.fail()){
            cout << "Invalid operation, MONTH is an integer number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');

        //GET YEAR NUMBER
        cout << "Insert the number of the year: ";
        cin >> year;

        if(cin.fail()){
            cout << "Invalid operation, MONTH is an integer number!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        cin.clear();
        cin.ignore(10000, '\n');

        menuSeparator();

        //shows player so that user can confirm that it is checking the right player

        showSpecificPerson(cout,playerID);
        //players[playerID]->print(cout);
        cout << endl << endl;
        cout << "Go back.                                                               [0]" << endl;
        cout << "Confirm operation.                                                     [1]" << endl;
        cin >> option;

        validOption(option, 1);
        menuSeparator();

        if (option == 0) break;
        else if (option == 1) {

            cout << "The costs associated with the player with ID: " << playerID << " in " << month << "/";
            cout << year << "were of " << playerCostCalculatorMonth(month, year, playerID) << " euros." << endl;
            break;
        }

    }

}
/*
void NationalTeam::playerTimeMenu(){
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
    else if (option == 2) {}/*call between two dates function
}
*/