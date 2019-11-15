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

    void print(ostream &os);

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

//PLAYER STATISTCS EXCEPTIONS
class NegativeParameter{
public:
    int num;
    NegativeParameter(int num){
        this->num = num;
        cout << endl << endl << "Statistics cannot have negative value!" << endl;
    }
};

class InvalidMinutes{
public:
    int minutes;
    InvalidMinutes(int minutes){
        this->minutes = minutes;
        cout << endl << endl << "Minutes value has to be between 1 and 90!" << endl;
    }
};

class InvalidYellowCard{
public:
    int yellows;
    InvalidYellowCard(int yellows){
        this->yellows = yellows;
        cout << endl << endl << "Number of yellows has a max value of 2!" << endl;
    }
};

class InvalidRedCard{
public:
    int reds;
    InvalidRedCard(int reds){
        this->reds = reds;
        cout << endl << endl << "Number of reds cannot be higher than 1 and depends on the number of yellows!" << endl;
    }
};

#endif //AEDA_TEAM_MANAGER_CALLUPPLAYER_H
