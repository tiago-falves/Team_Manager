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

