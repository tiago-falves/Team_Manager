//
// Created by tiago on 19/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#define AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#pragma once

#include "CallUp.h"
//#include "FootbalPlayer.h"
#include "Date.h"
using namespace std;


class CallUpPlayer {
private:
    //FootbalPlayer player;
    //CallUp callUp;
    Date beginDate;
    Date endDate;
    int numberOfGoals;
    int minutesPlayed;
    int kilometers;

public:
    CallUpPlayer(/*CallUp callUp, FootbalPlayer player,*/ Date beginDate, Date endDate, int numberOfGoals, int minutesPlayed, int kilometers);
};


#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
