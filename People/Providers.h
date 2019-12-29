//
// Created by digas on 29/12/2019.
//

#ifndef AEDA_TEAM_MANAGER_PROVIDERS_H
#define AEDA_TEAM_MANAGER_PROVIDERS_H

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "..//Exceptions.h"
using namespace std;


class Providers {
    string name;
    float reputation;
    vector<string> equipement;
public:
    //CONSTRUCTORS
    Providers(string name, float reputation, vector<string> equipement);

    //GET METHODS
    string getName() const;
    float getReputation() const;
    vector<string> getEquipement() const;

    //SET METHODS
    void setName(string name);
    void setReputation(float reputation);
    void setEquipement(vector<string> equipement);

    bool operator< (Providers p1) const;
};


#endif //AEDA_TEAM_MANAGER_PROVIDERS_H
