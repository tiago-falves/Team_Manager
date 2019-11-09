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
    vector<Game*> games;
    Date begginingDate;
    Date endDate;
    vector<CallUpPlayerStatistics*> playerStatistics;

public:
    CallUp(vector<Game*> games,vector<CallUpPlayerStatistics*> playerStatistics,Date begginingDate,Date endDate);

    //GET METHODS
    vector<Game*> getGames() const;
    Date getBegDate() const;
    Date getEndDate() const;
    vector<CallUpPlayerStatistics*> getPlayerStatistics() const;

    //SET METHODS
    void setGames(const vector<Game*> &games);
    void setBegDate(const Date &begginingDate);
    void setEndDate(const Date &endDate);
    void setPlayerStatistics(const vector<CallUpPlayerStatistics*> playerStatistics);


};

#endif //AEDA_TEAM_MANAGER_CALLUP_H
