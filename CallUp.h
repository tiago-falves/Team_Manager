#ifndef AEDA_TEAM_MANAGER_CALLUP_H
#define AEDA_TEAM_MANAGER_CALLUP_H
#pragma once
#include <vector>
#include "Date.h"
#include "Game.h"
#include "CallUpPlayerStatistics.h"
using namespace std;

class CallUp {
private:
    float dailyCost;
    vector<Game*> games;
    Date begginingDate;
    Date endDate;
    vector<CallUpPlayerStatistics*> playerStatistics;

public:
    CallUp(float dailyCost, vector<Game*> games,vector<CallUpPlayerStatistics*> playerStatistics,Date begginingDate,Date endDate);

    //GET METHODS
    float getDailyCost() const;
    vector<Game*> getGames() const;
    Date getBegDate() const;
    Date getEndDate() const;
    vector<CallUpPlayerStatistics*> getPlayerStatistics() const;

    //SET METHODS
    void setDailyCost(const float &dailyCost);
    void setGames(const vector<Game*> &games);
    void setBegDate(const Date &begginingDate);
    void setEndDate(const Date &endDate);
    void setPlayerStatistics(const vector<CallUpPlayerStatistics*> playerStatistics);


};

#endif //AEDA_TEAM_MANAGER_CALLUP_H
