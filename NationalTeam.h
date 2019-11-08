//
// Created by tiago on 06/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_NATIONALTEAM_H
#define AEDA_TEAM_MANAGER_NATIONALTEAM_H


#include <vector>
#include "Date.h"
#include "People//Person.h"
#include "People//FootballPlayer.h"
#include "People//Technician.h"
#include "CallUp.h"




class NationalTeam {
private:
public:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;
    vector<CallUp*> callUps;
    NationalTeam();
    bool readPeople(string fileName);

    //Handle players vector
    bool addFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer);
    bool removeFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *playerToRemove);
    bool modifyFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer);
    int playerPosition(vector<FootballPlayer*> &players, FootballPlayer *player);

    //Handle costs (sallaries + insurance)
    //player costs
    float playerCostCalculator(Date d1, Date d2, int playerID);
    float playerCostCalculatorMonth(int monthNumber, int playerID);
    //team costs
    float teamCostCalculator(Date d1, Date d2);
    float teamCostCalculatorMonth(int monthNumber);
    //team+staff costs
    float allCostCalculator(Date d1, Date d2);
    float allCostCalculatorMonth(int monthNumber);
};



#endif //AEDA_TEAM_MANAGER_NATIONALTEAM_H
