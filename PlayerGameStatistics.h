//
// Created by tiago on 19/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#define AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#pragma once


#include "Date.h"
using namespace std;


class PlayerGameStatistics {
private:

    Date beginDate;
    Date endDate;
    int numberOfGoals;
    int minutesPlayed;
    int kilometers;

public:
    PlayerGameStatistics(/*CallUp callUp, FootbalPlayer player,*/ Date beginDate, Date endDate, int numberOfGoals, int minutesPlayed, int kilometers);
};


#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
