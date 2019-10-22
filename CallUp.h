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
    vector<Game> games;
    Date begginingDate;
    Date endDate;
    vector<CallUpPlayerStatistics> playerStatistics;

public:
    CallUp(vector<Game> games,vector<CallUpPlayerStatistics> playerStatistics,Date begginingDate,Date endDate);
};

#endif //AEDA_TEAM_MANAGER_CALLUP_H
