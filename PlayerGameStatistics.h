//
// Created by tiago on 19/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#define AEDA_TEAM_MANAGER_CALLUPPLAYER_H
#pragma once

#include "People//FootballPlayer.h"


using namespace std;


class PlayerGameStatistics {
private:
public:
    FootballPlayer *getPlayer() const;

    void setPlayer(FootballPlayer *player);

    int getNumberOfGoals() const;

    void setNumberOfGoals(int numberOfGoals);

    int getMinutesPlayed() const;

    void setMinutesPlayed(int minutesPlayed);

    int getKilometers() const;

    void setKilometers(int kilometers);

    int getNumberOfPasses() const;

    void setNumberOfPasses(int numberOfPasses);

    int getNumberOfYellowCards() const;

    void setNumberOfYellowCards(int numberOfYellowCards);

    int getNumberOfRedCards() const;

    void setNumberOfRedCards(int numberOfRedCards);

private:
    FootballPlayer * player;
    int numberOfGoals;
    int minutesPlayed;
    int kilometers;
    int numberOfPasses;
    int numberOfYellowCards;
    int numberOfRedCards;

public:
    PlayerGameStatistics(int numberOfGoals, int minutesPlayed, int kilometers);
};


#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
