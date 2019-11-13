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

    PlayerGameStatistics(int playerID, int numberOfGoals, int minutesPlayed, int kilometers, int numberOfPasses, int numberOfYellowCards, int numberOfRedCards);

    PlayerGameStatistics(int playerID);

    PlayerGameStatistics();

    int getPlayerID() const;

    void setPlayerID(int playerID);

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

    int getID() const;

private:
    int id;
    int playerID;
    int numberOfGoals;
    int minutesPlayed;
    int kilometers;
    int numberOfPasses;
    int numberOfYellowCards;
    int numberOfRedCards;
    static int lastId;

public:

};


#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
