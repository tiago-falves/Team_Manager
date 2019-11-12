#ifndef AEDA_TEAM_MANAGER_CALLUP_H
#define AEDA_TEAM_MANAGER_CALLUP_H
#pragma once
#include <vector>
#include "Date.h"
#include "Game.h"
#include "CallUpPlayerStatistics.h"
#include "Exceptions.h"
using namespace std;

class CallUp {
private:
    int id;
    float dailyCost;
    vector<Game*> games;
    Date begginingDate;
    Date endDate;
    vector<CallUpPlayerStatistics*> playerStatistics;

public:
    CallUp(int id, float dailyCost, vector<Game*> games,vector<CallUpPlayerStatistics*> playerStatistics,Date begginingDate,Date endDate);

    //GET METHODS
    int getId() const;
    float getDailyCost() const;
    vector<Game*> getGames() const;
    Date getBegDate() const;
    Date getEndDate() const;
    vector<CallUpPlayerStatistics*> getPlayerStatistics() const;

    //SET METHODS
    void setId(const int &id);
    void setDailyCost(const float &dailyCost);
    void setGames(const vector<Game*> &games);
    void setBegDate(const Date &begginingDate);
    void setEndDate(const Date &endDate);
    void setPlayerStatistics(const vector<CallUpPlayerStatistics*> playerStatistics);


    //CHANGE CALLUP
    void addGame(Game *game);
    void removeGame(Game *game);

    void addPlayer(int playerID, Date begDate, Date endDate);
    void removePlayer(int playerID);

    void changeBeginDate(Date beg);
    void changeEndDate(Date end);

    void changeDailyCost(float dailyCost);

    //UTILITIES
    bool gameExists(Game *game);
    bool playerExists(int playerID);

    //SHOW CALLUP
    void showCallUp();

    //COMPARISON OPERATOR
    friend bool operator< (const CallUp& callUp1, const CallUp& callUp2);
};

#endif //AEDA_TEAM_MANAGER_CALLUP_H
