//
// Created by tiago on 19/10/2019.
//

#include "CallUp.h"


CallUp::CallUp (int id, float dailyCost, vector<Game*> games,vector<CallUpPlayerStatistics*> playerStatistics, Date begginingDate, Date endDate) {
    this->id = id;
    this->dailyCost = dailyCost;
    this->games=games;
    this->playerStatistics = playerStatistics;
    this->begginingDate=begginingDate;
    this->endDate=endDate;

}

//GET METHODS
int CallUp::getId() const{
    return id;
}
float CallUp::getDailyCost() const {
    return dailyCost;
}
Date CallUp::getBegDate() const {
    return begginingDate;
}
Date CallUp::getEndDate() const {
    return endDate;
}
vector<Game*> CallUp::getGames() const {
    return games;
}
vector<CallUpPlayerStatistics*> CallUp::getPlayerStatistics() const {
    return playerStatistics;
}

//SET METHODS
void CallUp::setId(const int &id) {
    this->id = id;
}
void CallUp::setDailyCost(const float &dailyCost) {
    this->dailyCost = dailyCost;
}
void CallUp::setBegDate(const Date &begginingDate) {
    this->begginingDate = begginingDate;
}
void CallUp::setEndDate(const Date &endDate) {
    this->endDate = endDate;
}
void CallUp::setGames(const vector<Game *> &games) {
    this->games = games;
}
void CallUp::setPlayerStatistics(const vector<CallUpPlayerStatistics *> playerStatistics) {
    this->playerStatistics = playerStatistics;
}

//CHANGE CALLUP
void CallUp::changeDailyCost(float dailyCost) {
    this->dailyCost = dailyCost;
}

void CallUp::changeBeginDate(Date beg) {
    this->begginingDate = beg;
}

void CallUp::changeEndDate(Date end) {
    this->endDate = end;
}

//ADD / REMOVE GAME
void CallUp::addGame(Game *game) {
    if (gameExists(game)) throw GameExistsCallUp(game);
    games.push_back(game);
}
void CallUp::removeGame(Game *game){
    if (!gameExists(game)) throw GameDontExistsCallUp(game);
    games.erase(games.begin() + BinarySearch(games, game));
}

//ADD / REMOVE PLAYER
void CallUp::addPlayer(int playerID, Date begDate, Date endDate) {
    if(playerExists(playerID)) throw PlayerExistsCallUp(playerID);
    CallUpPlayerStatistics player(playerID, begDate, endDate);
    insert_sorted(playerStatistics, &player);
}

void CallUp::removePlayer(int playerID) {
    bool check = false;
    //FIND PLAYER POSITION
    vector<CallUpPlayerStatistics*>::const_iterator it;
    for (auto i = playerStatistics.begin(); i != playerStatistics.end(); i++){
        if ((*i)->getPlayerID() == playerID) {
            it = i;
            check = true;
            break;
        }
    }
    if (!check) throw PlayerDontExistsCallUp(playerID);

    playerStatistics.erase(it);
}



//UTILITIES
bool CallUp::gameExists(Game *game) {
    if (BinarySearch(games, game) == -1) return false;
    return true;
}
bool CallUp::playerExists(int playerID) {
    for (auto i = playerStatistics.begin(); i != playerStatistics.end(); i++){
        if ((*i)->getPlayerID() == playerID) return true;
    }

    return false;
}

//SHOW CALL UP
void CallUp::showCallUp(ostream &out){
    for (auto i = games.begin(); i != games.end(); i++){
        if (i == games.begin()) {
            out << left << setw(5) << setfill(' ') << id << "│  ";
            out << left << setw(8) << setfill(' ') << begginingDate.toString() << "│  ";
            out << left << setw(8) << setfill(' ') << endDate.toString() << "│ ";
            out << left << setw(20) << setfill(' ') << (*i)->getGameTitle() << "│ ";
            out << endl;
        }
        else{
            out << left << setw(5) << setfill(' ') << "----" << "│  ";
            out << left << setw(8) << setfill(' ') << "----------" << "│  ";
            out << left << setw(8) << setfill(' ') << "----------" << "│ ";
            out << left << setw(20) << setfill(' ') << (*i)->getGameTitle() << "│ ";
            out << endl;
        }
    }
    out << setw(55) << setfill('-') << "-" <<  endl;
}

//CALL UP COMPARISON
bool operator< (const CallUp& callUp1, const CallUp& callUp2) {
    if (callUp1.getId() < callUp2.getId()) return true;
    else return false;
}
//SEND INFORMATION TO FILE
void CallUp::printIntoFile(ostream &os) const{
    os << id << endl;
    os << begginingDate << endl;
    os << endDate << endl;
    os << dailyCost << endl;

    //LIST OF GAME IDS
    for (auto i = 0; i < games.size(); i++){
        if (i = games.size() - 1) os << games[i]->getID() << endl;
        else os << games[i]->getID() << ", ";
    }

    os << "----------" << endl;

    for (auto i = playerStatistics.begin(); i != playerStatistics.end(); i++){
        os << (*i)->getPlayerID() << endl;
        os << (*i)->getBegDate() << endl;
        os << (*i)->getEndDate() << endl;
    }

    os << "::::::::::" << endl;
}

