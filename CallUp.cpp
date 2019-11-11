//
// Created by tiago on 19/10/2019.
//

#include "CallUp.h"

CallUp::CallUp (float dailyCost, vector<Game*> games,vector<CallUpPlayerStatistics*> playerStatistics, Date begginingDate, Date endDate) {
    this->dailyCost = dailyCost;
    this->games=games;
    this->playerStatistics = playerStatistics;
    this->begginingDate=begginingDate;
    this->endDate=endDate;

}

//GET METHODS
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
    //if (gameExists(game)) //throw exception game already exists
    insert_sorted(games, game);
}
void CallUp::removeGame(Game *game){
    //if (!gameExists(game)) //throw exception game does not exist
    games.erase(games.begin() + BinarySearch(games, game));
}

//ADD / REMOVE PLAYER
void CallUp::addPlayer(int playerID, Date begDate, Date endDate) {
    //if(playerExists(playerID)) //throw exception player already exists
    CallUpPlayerStatistics player(playerID, begDate, endDate);
    insert_sorted(playerStatistics, &player);
}
void CallUp::removePlayer(int playerID) {
    //FIND PLAYER POSITION
    vector<CallUpPlayerStatistics*>::const_iterator it;
    for (auto i = playerStatistics.begin(); i != playerStatistics.end(); i++){
        if ((*i)->getPlayerID() == playerID) {
            it = i;
            break;
        }
    }
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
