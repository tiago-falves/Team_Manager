#ifndef AEDA_TEAM_MANAGER_TEAM_H
#define AEDA_TEAM_MANAGER_TEAM_H
#pragma once
#include <vector>
#include "Person.h"




class Team {
private:
public:
    vector<Person> people;

    Team(vector<Person> &people);

    bool addPerson(const Person &person);
    bool removePerson(const Person &person);
    int personPosition(const Person &person);


};


#endif //AEDA_TEAM_MANAGER_TEAM_H
