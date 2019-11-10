#include "../NationalTeam.h"

void NationalTeam::runPeopleMenu() {
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

    validOption(option,4);

    cin.clear();
    cin.ignore(10000, '\n');

    menuSeparator();

    if (option == 0) { runMenu(); }
    if (option == 1) { showEveryone(cout) ; }
    if (option == 2) { showSpecificClient(); }
    if (option == 3) { runPlayersMenu(); }
    if (option == 4) { runTechnicianMenu(); }



    runPeopleMenu();
}

void NationalTeam::showSpecificClient(){
    int i = askForId();
    cout << searchByID(people,i);
}

void NationalTeam::askPersonInformation(){
    string name;
    Date birthdayDate;
    string text;
    float salary;
    bool zas;

    cout << "Name: ";
    getline(cin,name);
    askForDate("Birthday",text);

    cout << "Salary: ";
    cin >> text;
    while(true) {
        try {
            validFloat(text);

        }
        catch (std::invalid_argument ia) {
            cout << "Invalid number, please insert your answer again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> text;
        }
        if(1){break;}

    }




}

/*****************************************
 ***********PLAYERS MENU******************
 *****************************************/

void NationalTeam::runPlayersMenu() {
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

    validOption(option,7);

    menuSeparator();

    if (option == 0) { runMenu(); }
    if (option == 1) { runMenu(); }
    if (option == 2) { runMenu(); }
    if (option == 3) { runMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }
    if (option == 6) { runMenu(); }
    if (option == 7) { runMenu(); }


    runPeopleMenu();
}



void NationalTeam::askPlayerInformation(){


}









void NationalTeam::runTechnicianMenu() {
    int option;

    cout << "Welcome to the players Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "0. Go back" << endl;
    cout << "1. Create a new Technician." << endl;
    cout << "2. Change a technician information." << endl;
    cout << "3. Remove a technician" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    validOption(option,3);


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

    runPeopleMenu();
}



