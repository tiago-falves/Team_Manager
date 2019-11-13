//
// Created by tiago on 06/11/2019.
//

#include "NationalTeam.h"
#include "Date.h"
#include "Exceptions.h"
#include <algorithm>
#include <fstream>
using namespace std;


NationalTeam::NationalTeam() {

}

bool NationalTeam::readPeople(string fileName) {
    string text;
    string id;
    ifstream peopleFile;
    Date birthday = Date();
    peopleFile.open("..//Files//" + fileName);
    if(peopleFile.fail()){
        cerr << "Error Opening File";
        return false;
    }
    else{
        while(!peopleFile.eof()){
            getline(peopleFile, text);
            //getline(peopleFile,id);
            if(text == "Football Player"){
                FootballPlayer *player = new FootballPlayer();
                player->read(&peopleFile);
                people.push_back((player));
                players.push_back(player);
                getline(peopleFile, text);
            }
            else if(text == "Technician"){
                Technician *technician = new Technician();
                technician->read(&peopleFile);
                people.push_back((technician));
                technicians.push_back(technician);
                getline(peopleFile, text);
            }
        }
    }
    peopleFile.close();
    return true;
}

void NationalTeam::read(string peopleFile,string callUpFile,string gameFile,string statisticsFile) {
    readPeople(peopleFile);
    readCallUp(callUpFile);
    readGames(gameFile);
    readGameStatiscs(statisticsFile);
}

bool NationalTeam::readNationalTeam(string fileName) {
    string text;
    ifstream teamFile;
    teamFile.open("..//Files//" + fileName);
    if(teamFile.fail()){
        cerr << "Error Opening National Team File";
        return false;
    }
    else{
        getline(teamFile, text);
        callUpFile = text;
        getline(teamFile,text);
        gameFile = text;
        getline(teamFile,text);
        peopleFile = text;
        getline(teamFile,text);
        statisticsFile = text;
    }
    teamFile.close();
    read(peopleFile,callUpFile,gameFile, statisticsFile);
    return true;
}

bool NationalTeam::savePeople(string fileName) {
    ofstream content("..//Files//" + fileName);
    for (int i = 0; i < people.size(); ++i) {
        people[i]->printToFile(content);
        content << "::::::::::" << endl;
    }
    content.close();
    return true;
}


void NationalTeam::sortByID(vector<Person *> &people) {
    sort(people.begin(),people.end());
}

bool NationalTeam::nameComparable(const Person* person1, const Person* person2){
    return (person1->getName() < person2->getName());
}
bool NationalTeam::idComparable(const Person* person1, const int id){
    return (person1->getId() < id);
}
void NationalTeam::sortByName(vector<Person *> &people) {
    sort(people.begin(),people.end(),nameComparable);
}


vector<Person*> NationalTeam::searchByName(vector<Person *> people,string name) { //Devo ordenar duas vezes?? ou mais vale usar a sequencial?

    vector<Person*> peopleName;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i]->getName() == name){
            peopleName.push_back(people[i]);
        }
    }
    return peopleName;

}
Game* NationalTeam::getGameWithID(int id){
    for (auto i = games.begin(); i != games.end(); i++){
        if ((*i)->getID() == id) return *i;
    }
    throw InexistentId(id);
}

CallUp* NationalTeam::getCallUpWithID(int id){
    for (auto i = callUps.begin(); i != callUps.end(); i++){
        if ((*i)->getId() == id) return *i;
    }
    throw InexistentId(id);
}
bool NationalTeam::searchCallUpByID(const int &id){
    bool check = false;
    for (auto i = callUps.begin(); i != callUps.end(); i++){
        if ((*i)->getId() == id) check = true;
    }

    if (!check) throw InexistentId(id);

    return check;
}

//DELETE CALL UP
void NationalTeam::deleteCallUp(int id) {
    for (auto i = callUps.begin(); i != callUps.end(); i++){
        if ((*i)->getId() == id){
            callUps.erase(i);
            return;
        }
    }
}

//READ FROM TEXT FILE
bool NationalTeam::readCallUp(string file) {

    ifstream callUpFile;
    callUpFile.open("..//Files//" + file);

    if(callUpFile.fail()){
        cerr << "Error Opening File";
        return false;
    }

    //READ FROM FILE VARIABLES
    string text;
    vector<int> game_indexes;

    //VARIABLES TO CONSTRUCT CALLUP
    int callUpId = 0;
    Date begginingDate, endingDate;
    float dailyCost;
    vector<Game*> callUpGames;
    vector<CallUpPlayerStatistics*> playerStatistics;

    //VARIABLES TO CONSTRUCT CALLUPPLAYERSTATISTICS
    int playerID;
    Date begDate, endDate;

    unsigned int counter = 0;

    while(getline(callUpFile, text)) {

        //ID
        if(counter == 0){
            callUpId = stoi(text);
        }

        //BEGINNING DATE
        if (counter == 1) {
            begginingDate = begginingDate.dateTextConverter(text);
        }

        //END DATE
        if (counter == 2) {
            endingDate = endingDate.dateTextConverter(text);
        }

        //DAILY COST
        if (counter == 3) {
            dailyCost = stof(text);
        }

        //VECTOR OF GAMES
        if (counter == 4) {
            game_indexes = separateCharacterInt(text, ',');

            //verify that game exists

            for (auto i = games.begin(); i < games.end(); i++) {
                for (auto j = game_indexes.begin(); j < game_indexes.end(); j++){
                    if ((*i)->getID() == *j){
                        insert_sorted(callUpGames, *i);
                    }
                }
            }

        }
        //CALLUP PLAYER STATISTICS VECTOR
        if (counter == 5) {

            while (getline(callUpFile, text)) {
                if (text == "::::::::::") break;
                playerID = stoi(text);

                getline(callUpFile, text);
                begDate.dateTextConverter(text);

                getline(callUpFile, text);
                endDate.dateTextConverter(text);

                insert_sorted(playerStatistics, new CallUpPlayerStatistics(playerID, begDate, endDate));

            }
            counter = -1;
            insert_sorted(callUps, new CallUp(callUpId ,dailyCost, callUpGames, playerStatistics, begginingDate, endingDate));
        }
        counter++;
    }
    callUpFile.close();
    return true;
}


//HANDLE COSTS
//player costs
float NationalTeam::playerCostCalculator(Date d1, Date d2, int playerID){

    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass = players[playerID-1]->getPassValue() * 0.01;

    //variable that sums the costs associated with this player
    float val = 0;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++){

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){

            if ((*j)->getPlayerID() == playerID){
                //found player in this call up
                //checking number of days player was in call up between the given days
                if (d1 <= (*j)->getBegDate() && d2 >= (*j)->getEndDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()) {
                        val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * (*i)->getDailyCost();
                }
                else if (d1 <= (*j)->getBegDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else  val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays())  * (*i)->getDailyCost();
                }
                else if (d2 >= (*j)->getEndDate()) {
                    if (players[(*j)->getPlayerID()]->isInjury()) {
                        val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays())  * (*i)->getDailyCost();
                }
                else if (d1 >= (*j)->getBegDate() && d2 <= (*j)->getEndDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (d2.dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * (d2.dateToDays() - d1.dateToDays()) * (*i)->getDailyCost();
                }
            }
        }
    }
    return val;
}

float NationalTeam::teamCostCalculator(Date d1, Date d2) {
    float val = 0;
    float pass;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++){

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){

            pass = players[(*j)->getPlayerID()]->getPassValue() * 0.01;

            //checking number of days player was in call up between the given days
            if (d1 <= (*j)->getBegDate() && d2 >= (*j)->getEndDate()){
                if (players[(*j)->getPlayerID()]->isInjury()) {
                    val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * (*i)->getDailyCost();
            }
            else if (d1 <= (*j)->getBegDate()){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else  val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays())  * (*i)->getDailyCost();
            }
            else if (d2 >= (*j)->getEndDate()) {
                if (players[(*j)->getPlayerID()]->isInjury()) {
                    val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays())  * (*i)->getDailyCost();
            }
            else if (d1 >= (*j)->getBegDate() && d2 <= (*j)->getEndDate()){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (d2.dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * (d2.dateToDays() - d1.dateToDays()) * (*i)->getDailyCost();
            }
        }
    }
    return val;
}

float NationalTeam::staffCostCalculator(Date d1, Date d2) {
    float costs = 0;
    float date_difference;
    float no_months;
    //iterate over technicians menu
    for (auto i = technicians.begin(); i != technicians.end(); i++){
        //GET DATE DIFERENCE IN DAYS - setting an average of 30.44 days per month
        no_months = (d2.dateToDays() - d1.dateToDays()) / 30.44;
        costs += no_months * (*i)->getSalary();
    }

    return costs;
}

float NationalTeam::playerCostCalculatorMonth(int monthNumber, int yearNumber, int playerID) {
    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass = players[playerID-1]->getPassValue() * 0.01;

    //variable that sums the costs associated with this player
    float val = 0;

    //Date variables used in loops
    Date beg, end;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++) {

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++) {

            if ((*j)->getPlayerID() == playerID) {
                //found player in this call up
                beg = (*j)->getBegDate();
                end = (*j)->getEndDate();

                if (beg.getMonth() == monthNumber && end.getMonth() == monthNumber && beg.getYear() == yearNumber && end.getYear() == yearNumber){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost();
                }
                else if (beg.getMonth() == monthNumber && end.getYear() == yearNumber){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost();
                }
                else if (end.getMonth() == monthNumber && end.getYear() == yearNumber){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (end.getDay()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (end.getDay()) * (*i)->getDailyCost();
                }
                else if (((beg.getMonth() <= monthNumber && beg.getYear() == yearNumber) || (beg.getYear() == yearNumber)) && ((end.getMonth() >= monthNumber && end.getYear() == yearNumber) || (end.getYear() == yearNumber))){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost();
                }
                else{
                    //lançar exceção de jogador não estar em nenhuma convocatória na data fornecida
                }
            }
        }
    }
    return pass;
}

float NationalTeam::teamCostCalculatorMonth(int monthNumber, int yearNumber) {
    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass;

    //variable that sums the costs associated with this player
    float val = 0;

    //Date variables used in loops
    Date beg, end;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++) {

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++) {

            //found player in this call up
            beg = (*j)->getBegDate();
            end = (*j)->getEndDate();
            pass = players[(*j)->getPlayerID()]->getPassValue() * 0.01;

            if (beg.getMonth() == monthNumber && end.getMonth() == monthNumber && beg.getYear() == yearNumber && end.getYear() == yearNumber){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost();
            }
            else if (beg.getMonth() == monthNumber && end.getYear() == yearNumber){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost();
            }
            else if (end.getMonth() == monthNumber && end.getYear() == yearNumber){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (end.getDay()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (end.getDay()) * (*i)->getDailyCost();
            }
            else if (((beg.getMonth() <= monthNumber && beg.getYear() == yearNumber) || (beg.getYear() == yearNumber)) && ((end.getMonth() >= monthNumber && end.getYear() == yearNumber) || (end.getYear() == yearNumber))){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost() *3;
                }
                else val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost();
            }
            else{
                //lançar exceção de jogador não estar em nenhuma convocatória na data fornecida
            }
        }
    }
    return val;
}

float NationalTeam::staffCostCalculatorMonth(int monthNumber) {
    float costs;
    for (auto i = technicians.begin(); i != technicians.end(); i++){
        costs += (*i)->getSalary();
    }
    return costs;
}

bool NationalTeam::readGames(string filename) {
    string text;
    ifstream gamesFile;
    vector<int> splited_int_string;
    vector<string> splited_str_string;
    vector<FootballPlayer *> players;
    gamesFile.open("..//Files//" + filename);


    if(gamesFile.fail()){
        cerr << "Error Opening File";
        return false;
    }
    else {
        while (!gamesFile.eof()) {
            Game *game = new Game();

            getline(gamesFile, text);
            game->setCity(text);

            getline(gamesFile, text);
            game->setCountry(text);

            getline(gamesFile, text);
            game->setStadium(text);

            getline(gamesFile, text);
            game->setGameTitle(text);

            getline(gamesFile, text);
            splited_int_string = separateCharacterInt(text, ',');

            //Falta implementar guardar os PlayerGameStatistics

            getline(gamesFile, text);
            splited_int_string = separateCharacterInt(text, ',');

            for (int i = 0; i < splited_int_string.size(); i++) {
                players.push_back(this->players[splited_int_string[i]-1]);
            }

            game->setNationalPlayers(players);

            getline(gamesFile, text);
            splited_str_string = separateCharacterStr(text, ',');
            game->setEnemyPlayers(splited_str_string);

            getline(gamesFile, text);
            splited_str_string = separateCharacterStr(text, ',');
            game->setReferees(splited_str_string);

            getline(gamesFile, text);

            games.push_back(game);
        }

        gamesFile.close();

        return true;
    }
}
bool NationalTeam::readGameStatiscs(string filename) {
    //VARIABLES TO READ FILE
    ifstream statsFile;
    statsFile.open("..//Files//" + filename);
    string text;

    if(statsFile.fail()){
        cerr << "Error Opening File";
        return false;
    }


    int gameID;

    while(!statsFile.eof()){

        getline(statsFile, text);
        gameID = stoi(text);
        vector<PlayerGameStatistics> stats = {};

        while(text != "::::::::::"){
            PlayerGameStatistics statistics;

            getline(statsFile, text);
            statistics.setPlayerID(stoi(text));

            getline(statsFile, text);
            statistics.setNumberOfGoals( stoi(text) );

            getline(statsFile, text);
            statistics.setMinutesPlayed( stoi(text) );

            getline(statsFile, text);
            statistics.setKilometers( stoi(text) );

            getline(statsFile, text);
            statistics.setNumberOfPasses( stoi(text) );

            getline(statsFile, text);
            statistics.setNumberOfYellowCards( stoi(text) );

            getline(statsFile, text);
            statistics.setNumberOfRedCards( stoi(text) );

            getline(statsFile, text);

            stats.push_back(statistics);
        }

        games[gameID - 1]->setPlayerStatistics(stats);
    }



    statsFile.close();
    return true;
}

vector<Game *> NationalTeam::getAllGamesForPlayer(FootballPlayer *player) {
    vector<Game*> gamesPlayed;

    for(Game *g : this->games){
        if(g->getID() == player->getId()){
            gamesPlayed.push_back(g);
        }
    }

    return gamesPlayed;
}


//Exists the program and saves the information to new files: "clients.txt" and "packs.txt"
void NationalTeam::saveAndExit(string peepzFile,string callupFileName, string gamesFileName, string etc) {
    string content;
    ofstream peopleFile("../Files/" +peepzFile);

    for (int i = 0; i < people.size(); i++){
        people[i]->printToFile(peopleFile);
    }
    peopleFile.close();

    exit(0);
}





