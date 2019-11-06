//
// Created by tiago on 06/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_NATIONALTEAM_H
#define AEDA_TEAM_MANAGER_NATIONALTEAM_H


#include <vector>
#include "Person.h"
#include "FootballPlayer.h"
#include "Technician.h"




class NationalTeam {
private:
public:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;
    NationalTeam(string fileName);
    bool readTeam(string fileName);




};



#endif //AEDA_TEAM_MANAGER_NATIONALTEAM_H
