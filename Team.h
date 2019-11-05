#ifndef AEDA_TEAM_MANAGER_TEAM_H
#define AEDA_TEAM_MANAGER_TEAM_H
#pragma once
#include <vector>
#include "Person.h"
#include "FootballPlayer.h"
#include "Technician.h"




class Team {
private:
public:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;

    Team(string fileName);
    static bool readFile(string fileName);




};


#endif //AEDA_TEAM_MANAGER_TEAM_H
