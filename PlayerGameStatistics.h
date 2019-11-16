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

    /**
     * ID of the Statistic
     * Every statistic has an ID so it easy to identify each statistics
    */
    int id;

    /**
     * ID of the Player that the statistic belongs to
     * Every player has an ID so it easy to identify each player
    */
    int playerID;

    /**
     * Number of Goals Score by the Player
    */
    int numberOfGoals;

    /**
     * Minutes Played but the Player
     */
    int minutesPlayed;

    /**
     * Kilometers the Player ran
     */
    int kilometers;

    /**
     * Number of Passes the Player made
     */
    int numberOfPasses;

    /**
     * Number of Yellow Cards the Player received
     */
    int numberOfYellowCards;

    /**
     * Number of Red Cards the Player received
     */
    int numberOfRedCards;

    /**
     * Static variable to keep ID always updated and orderd
     */
    static int lastId;

public:

    /**
     * @brief Constructor of the Statistics of a player given all its atributes
     * @param playerID
     * @param numberOfGoals
     * @param minutesPlayed
     * @param kilometers
     * @param numberOfPasses
     * @param numberOfYellowCards
     * @param numberOfRedCards
     */
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

    int getId() const;

    void print(ostream &os);

    /**
     * Prints Statistics information to correspondent file
     * @param os
     */
    void printIntoFile(ostream &os) const;
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
