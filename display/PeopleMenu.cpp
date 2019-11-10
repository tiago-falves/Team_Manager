#include "../NationalTeam.h"
#include "../Exceptions.h"

void NationalTeam::runPeopleMenu() {
    int option;


    cout << "Welcome to the People Menu! Please choose what you want to do: ";
    cout << endl << endl;
    cout << "Go back                                                            [0]" << endl;
    cout << "See information from everyone                                      [1]" << endl;
    cout << "See information from a specific person                             [2]" << endl;
    cout << "Football Players                                                   [3]" << endl;
    cout << "Technicians                                                        [4]" << endl;
    cout << "Insert the number correspondent to your option: ";
    cin >> option;

    validOption(option,4);

    menuSeparator();

    if (option == 0) { runMenu(); }
    if (option == 1) { showEveryone(cout) ; }
    if (option == 2) { showSpecificPerson(); }
    if (option == 3) { runPlayersMenu(); }
    if (option == 4) { runTechnicianMenu(); }



    runPeopleMenu();
}

void NationalTeam::showSpecificPerson(){
    int i = askForId();
    while (true)
    {
        try {
            searchByID(people, i);
            break;
        }
        catch (InexistentId(i)) {
            i = askForId();
        }
    }
    cout << searchByID(people,i);
}

void NationalTeam::askPersonInformation(string &name,float &salary,Date &birthday){
    string text;

    name = askForString("Name");
    birthday = askForDate("Birthday",text);
    salary = askForFloat(text,"Salary");
}


string NationalTeam::askForString(const string &what){
    string name;
    cout << what << ": ";
    getline(cin,name);
    return name;
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
    if (option == 1) { createPlayer(); }
    if (option == 2) { runMenu(); }
    if (option == 3) { runMenu(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }
    if (option == 6) { runMenu(); }
    if (option == 7) { runMenu(); }


    runPeopleMenu();
}

void NationalTeam::createPlayer(){
    players.push_back(askPlayerInformation());
}

/*void NationalTeam::modifyPlayer(){
    FootballPlayer *player = new FootballPlayer();
    int id = askForId();
    try {player = searchByID(people,id)}
    catch (out_of_range){
        cerr << "Tried to modify Person that doesn't exist: " << person->getName() << endl;
        return false;
    }
}*/

FootballPlayer* NationalTeam::askPlayerInformation(){
    string name;
    float salary;
    Date birthday = Date();
    string position;
    string club;
    float weight;
    float height;
    float pass_value;
    bool injury;
    string input;

    FootballPlayer *player = new FootballPlayer();

    askPersonInformation(name,salary,birthday);

    player->setPosition(askForString("Position"));
    player->setClub(askForString("Club"));
    player->setWeight(askForFloat(input,"Weight"));
    player->setHeight(askForFloat(input, "Height"));
    player->setPassValue(askForFloat(input,"Pass Value"));

    cout << "Is the player Injured? : ";
    player->setInjury(askYesNoQuestion());

    return player;

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



