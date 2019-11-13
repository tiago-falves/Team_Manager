#include "../NationalTeam.h"
#include "../Exceptions.h"


//Main Menu with operations to all kinds of people
void NationalTeam::runPeopleMenu() {

    int option;

    while(true){
        menuSeparator();

        cout << "Welcome to the People Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back                                                            [0]" << endl;
        cout << "See information from everyone                                      [1]" << endl;
        cout << "See information from a specific person                             [2]" << endl;
        cout << "Search Person by name                                              [3]" << endl;
        cout << "Football Players                                                   [4]" << endl;
        cout << "Technicians                                                        [5]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 5);

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { showEveryone(cout); }
        if (option == 2) { showSpecificPersonOption(); }
        if (option == 3) { showPersonByName(); }
        if (option == 4) { runPlayersMenu(); }
        if (option == 5) { runTechnicianMenu(); }


    }
}

//Asks for the id of a person and shows the person in the screen
void NationalTeam::showSpecificPersonOption() {
    int i = askForValidId(people);
    menuSeparator();
    showSpecificPerson(cout,i);
}

//asks for the name of a person and shows everyone with that name
void NationalTeam::showPersonByName() {
    string text;
    cout << "Please Insert Name of the Person: " << endl;
    getline(cin,text);
    vector<Person*> peepz = searchByName(people,text);
    menuSeparator();

    tableHeaderPlayer(cout);
    for (int i = 0; i < peepz.size(); ++i) {
        cout << peepz[i];
    }
    tableFooterPlayer(cout);
}

//Prints to to out a person with a certain id
void NationalTeam::showSpecificPerson(ostream &out,int i){

    tableHeaderPlayer(out);
    cout << people[searchByID(people,i)];
    tableFooterPlayer(out);
}

//Shows everyone in the Database
void NationalTeam::showEveryone(ostream &out) {

    tableHeaderPlayer(out);

    for (int i = 0; i < people.size(); ++i) {
        out << people[i];
    }
    tableFooterPlayer(out);
}

//Header of the People table
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

//Footer of the people table
void NationalTeam::tableFooterPlayer(ostream &out){
    out << setw(117) << setfill('-') << "-" << endl;
}

//Asks for all the information about a person
void NationalTeam::askPersonInformation(string &name, float &salary, Date &birthday){
    string text;

    name = askForString("Name");
    birthday = askForDate("Birthday",text);
    salary = askForFloat(text,"Salary");
}

//Asks the user to insert a string of type what
string NationalTeam::askForString(const string &what){
    string name;
    cout << what << ": ";
    getline(cin,name);
    return name;
}



/*****************************************
 ***********PLAYERS MENU******************
 *****************************************/

//Runs Player's menu with all specific players operations
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

//Asks the user for information of new player and adds it to the databas
void NationalTeam::createPlayerOption(){
    FootballPlayer *player = new FootballPlayer();
    askPlayerInformation(player);
    addPerson(people,player);
    addPerson(players,player);

    menuSeparator();
    cout << "Player Added Successfully!";
}

//Asks for an id of a player and removes it from the database
void NationalTeam::removePlayerOption(){
    int id = askForValidId(players);
    removePerson(people,id);
    removePerson(players,id);
    menuSeparator();
    cout << "Player Removed Successfully!" << endl;
}


//Asks the user wich player it wats to modify and the new information of the palyer
//then it modifies it
void NationalTeam::modifyPlayerOption(){
    int id = askForValidId(players);
    FootballPlayer *player = new FootballPlayer();
    cin.clear();
    cin.ignore(10000, '\n');
    askPlayerInformation(player);
    int index = searchByID(people,id);
    people[index]->modify(player);
    menuSeparator();
    cout << "Player Modified Successfully!";

}

//Function to ask the user all the informations it wants to attribute to the player
void NationalTeam::askPlayerInformation(FootballPlayer *player){
    string name,position,club,input;
    float salary,weight,height,pass_value;
    Date birthday = Date();
    bool injury;

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


}


//Runs Menu with all operations specifc to technicians
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

//Aks the user for information about a technician and adds it to the database
void NationalTeam::createTechOption(){
    Technician *technician = new Technician();
    askTechInformation(technician);
    addPerson(people,technician);
    addPerson(technicians,technician);
    menuSeparator();
    cout << "Technician Added Successfully!";
}

//Asks the id of the technician it wants to remove and removes it from the database
void NationalTeam::removeTechOption(){
    int id = askForValidId(technicians);
    removePerson(people,id);
    removePerson(technicians,id);
    menuSeparator();
    cout << "Technician Removed Successfully!";
}

//Asks the user for information about a Technician and the id of the technician it wants to change
//Then it setts all the information of the technician
void NationalTeam::modifyTechOption(){
    int id = askForValidId(technicians);
    Technician *technician = new Technician();
    cin.clear();
    cin.ignore(10000, '\n');
    askTechInformation(technician);
    int index = searchByID(people,id);
    people[index]->modify(technician);
    menuSeparator();
    cout << "Technician Modified Successfully!";
}

//Asks the user for all the nformation of a technician
void NationalTeam::askTechInformation(Technician *technician){
    string name,role;
    float salary;
    Date birthday = Date();

    askPersonInformation(name,salary,birthday);
    technician->setName(name);
    technician->setSalary(salary);
    technician->setBirthday(birthday);

    technician->setRole(askForString("Role"));
}

//Gets People File name
const string &NationalTeam::getPeopleFile() const {
    return peopleFile;
}

//Sets People file name
void NationalTeam::setPeopleFile(const string &peopleFile) {
    NationalTeam::peopleFile = peopleFile;
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

