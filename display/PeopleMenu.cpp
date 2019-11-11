#include "../NationalTeam.h"
#include "../Exceptions.h"

void NationalTeam::runPeopleMenu() {


    int option;

    while(true){
        menuSeparator();

        cout << "Welcome to the People Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back                                                            [0]" << endl;
        cout << "See information from everyone                                      [1]" << endl;
        cout << "See information from a specific person                             [2]" << endl;
        cout << "Football Players                                                   [3]" << endl;
        cout << "Technicians                                                        [4]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 4);

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { showEveryone(cout); }
        if (option == 2) { showSpecificPerson(cout); }
        if (option == 3) { runPlayersMenu(); }
        if (option == 4) { runTechnicianMenu(); }

    }
}

void NationalTeam::showSpecificPerson(ostream &out){
    int i = askForValidId(people);
    menuSeparator();
    tableHeader(out);
    cout << people[searchByID(people,i)];
    tableFooter(out);
}

void NationalTeam::showEveryone(ostream &out) {

    tableHeader(out);

    for (int i = 0; i < people.size(); ++i) {
        out << people[i];
    }
    tableFooter(out);
}

void NationalTeam::tableHeader(ostream &out){
    out << endl << endl << endl;
    out << setw(117) << setfill('_') << "_" << endl;
    out <<  left << setw(4)  << setfill(' ') << "id" << "|  ";
    out <<  left << setw(20) << setfill(' ') << "Name"  << "| ";
    out <<  left << setw(11) << setfill(' ') <<  "Birthday"<< "| ";
    out <<  left << setw(9) << setfill(' ') << "Salary"<< "|  "  ;
    out <<  left << setw(20)  << setfill(' ') << "Position" << "| ";
    out <<  left << setw(9) << setfill(' ') << "Club"  << " |";
    out <<  left << setw(4) << setfill(' ')<<   "Weight"<< " |";
    out <<  left << setw(5) << setfill(' ') << "Height"<< " |";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) << "Pass"<< " |";
    out <<  left << setw(5) << setfill(' ') << "Health"<< "|" << endl;
    out << setw(117) << setfill('-') << "-" << endl;
}

void NationalTeam::tableFooter(ostream &out){
    out << setw(117) << setfill('_') << "_" << endl;
}


void NationalTeam::askPersonInformation(string &name, float &salary, Date &birthday){
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

    if (option == 0) { runPeopleMenu(); }
    if (option == 1) { createPlayerOption(); }
    if (option == 2) { modifyPlayerOption(); }
    if (option == 3) { removePlayerOption(); }
    if (option == 4) { runMenu(); }
    if (option == 5) { runMenu(); }
    if (option == 6) { runMenu(); }
    if (option == 7) { runMenu(); }


    runPeopleMenu();
}

void NationalTeam::createPlayerOption(){
    FootballPlayer *player = new FootballPlayer();
    player = askPlayerInformation();
    addPerson(people,player);
    addPerson(players,player);

    menuSeparator();
    cout << "Player Added Successfully!";
}

void NationalTeam::removePlayerOption(){
    int id = askForValidId(players);
    removePerson(people,id);
    removePerson(players,id);
    menuSeparator();
    cout << "Player Removed Successfully!";
}


void NationalTeam::modifyPlayerOption(){
    int id = askForValidId(players);
    FootballPlayer *player = new FootballPlayer();
    cin.clear();
    cin.ignore(10000, '\n');
    player = askPlayerInformation();
    int index = searchByID(people,id);
    people[index]->modify(player);
    menuSeparator();
    cout << "Player Modified Successfully!";

}

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
    player->setName(name);
    player->setSalary(salary);
    player->setBirthday(birthday);
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

    if (option == 0) { runPeopleMenu(); }
    if (option == 1) { createTechOption(); }
    if (option == 2) { modifyTechOption(); }
    if (option == 3) { removeTechOption(); }


    runTechnicianMenu();
}

void NationalTeam::createTechOption(){
    Technician *technician = new Technician();
    technician = askTechInformation();
    addPerson(people,technician);
    addPerson(technicians,technician);
    menuSeparator();
    cout << "Technician Added Successfully!";
}

void NationalTeam::removeTechOption(){
    int id = askForValidId(technicians);
    removePerson(people,id);
    removePerson(technicians,id);
    menuSeparator();
    cout << "Technician Removed Successfully!";
}


void NationalTeam::modifyTechOption(){
    int id = askForValidId(technicians);
    Technician *technician = new Technician();
    technician = askTechInformation();
    int index = searchByID(people,id);
    people[index]->modify(technician);
    menuSeparator();
    cout << "Technician Modified Successfully!";
}


Technician* NationalTeam::askTechInformation(){
    string name;
    float salary;
    Date birthday = Date();
    string role;

    Technician *technician = new Technician();

    askPersonInformation(name,salary,birthday);
    technician->setName(name);
    technician->setSalary(salary);
    technician->setBirthday(birthday);

    technician->setRole(askForString("Role"));


    return technician;

}

