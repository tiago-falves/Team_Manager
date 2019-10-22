//
// Created by tiago on 19/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#define AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#pragma once



using namespace std;


class PlayerGameStatistics {
private:
    int numberOfGoals;
    int minutesPlayed;
    int kilometers;

public:
    PlayerGameStatistics(int numberOfGoals, int minutesPlayed, int kilometers);
};


#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
