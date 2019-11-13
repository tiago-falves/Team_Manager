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
        if (option == 1) { showEveryone(cout); break;}
        if (option == 2) { showSpecificPersonOption(); break;}
        if (option == 3) { runPlayersMenu(); break;}
        if (option == 4) { runTechnicianMenu(); break;}

    }
}
void NationalTeam::showSpecificPersonOption() {
    int i = askForValidId(people);
    menuSeparator();
    showSpecificPerson(cout,i);
}

void NationalTeam::showSpecificPerson(ostream &out,int i){

    tableHeaderPlayer(out);
    cout << people[searchByID(people,i)];
    tableFooterPlayer(out);
}

void NationalTeam::showEveryone(ostream &out) {

    tableHeaderPlayer(out);

    for (int i = 0; i < people.size(); ++i) {
        out << people[i];
    }
    tableFooterPlayer(out);
}

void NationalTeam::tableHeaderPlayer(ostream &out){
    out << endl << endl << endl;
    out << setw(117) << setfill('-') << "-" <<  endl;
    out <<  left << setw(4)  << setfill(' ') << "id" << "│  ";
    out <<  left << setw(20) << setfill(' ') << "Name"  << "│ ";
    out <<  left << setw(11) << setfill(' ') <<  "Birthday"<< "│ ";
    out <<  left << setw(9) << setfill(' ') << "Salary"<< "│  "  ;
    out <<  left << setw(20)  << setfill(' ') << "Position" << "│ ";
    out <<  left << setw(9) << setfill(' ') << "Club"  << " │";
    out <<  left << setw(4) << setfill(' ')<<   "Weight"<< " │";
    out <<  left << setw(5) << setfill(' ') << "Height"<< " │";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) << "Pass"<< " │";
    out <<  left << setw(5) << setfill(' ') << "Health"<< " │" << endl;
    out << setw(117) << setfill('-') << "-" << "│" <<  endl;
}

void NationalTeam::tableFooterPlayer(ostream &out){
    out << setw(117) << setfill('-') << "-" << endl;
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

    while(true) {
        cout << "Welcome to the players Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "Create a new Football Player.                                      [1]" << endl;
        cout << "Change a player's information.                                     [2]" << endl;
        cout << "Remove a player.                                                   [3]" << endl;
        cout << "See a specific player statistics.                                  [4]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 4);

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { createPlayerOption(); }
        if (option == 2) { modifyPlayerOption(); }
        if (option == 3) { removePlayerOption(); }
        if (option == 4) { playerMenuTransition();}

        break;
    }
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

const string &NationalTeam::getPeopleFile() const {
    return peopleFile;
}

void NationalTeam::setPeopleFile(const string &peopleFile) {
    NationalTeam::peopleFile = peopleFile;
}

const string &NationalTeam::getCallUpFile() const {
    return callUpFile;
}

void NationalTeam::setCallUpFile(const string &callUpFile) {
    NationalTeam::callUpFile = callUpFile;
}

const string &NationalTeam::getGameFile() const {
    return gameFile;
}

void NationalTeam::setGameFile(const string &gameFile) {
    NationalTeam::gameFile = gameFile;
}

void NationalTeam::showPlayerGames(int id) {
    tableHeaderAllGames(cout);
    for (auto i = games.begin(); i != games.end(); i++){
        for (auto j = (*i)->getPlayerStatistics().begin(); j != (*i)->getPlayerStatistics().end(); j++){
            cout << id << " = " << (*j).getID() << endl;
            if (id == (*j).getID()){
                cout << "GOT IN" << endl;
                (*i)->print(cout);
            }
        }
    }
    tableFooterAllGames(cout);
}

void NationalTeam::playerMenuTransition() {
    int id, option;

    while (true) {
        cout << "Insert the ID of the player you want to see information from: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Invalid option, ID must be an integer!";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try {
            searchByID(players, id);
        }
        catch (InexistentId) {
            cout << "There are no players with such id (" << id << ") !" << endl;
            menuSeparator();
            break;
        }
        menuSeparator();

        cout << endl << endl;

        cout << "Go back.                                                           [0]" << endl;
        cout << "See all games played by a specific player.                         [1]" << endl;
        cout << "See all call-ups that a player participated.                       [2]" << endl;
        cout << "See player statistics from a game.                                 [3]" << endl;
        cout << "See player statistics from call up.                                [4]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 4);

        menuSeparator();

        if (option == 0) break;
        if (option == 1) { showPlayerGames(id); }
        if (option == 2) { /*showPlayerCallUps(id);*/ }
        if (option == 3) { /*showGameStats(id);*/}
        if (option == 4) { /*showCallUpStats(id);*/}

        break;
    }
}

