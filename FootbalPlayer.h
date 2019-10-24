#ifndef AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#define AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#pragma once
#include "Date.h"
#include "Person.h"




#include <vector>
using namespace std;

class FootbalPlayer: public Person {
private:
    string position;
    string club;
    float weight;
    float height;
    float pass_value;
    bool injury;
    float salary;

public:
    const string &getClub() const;
    void setClub(const string &club);

    float getWeight() const;

    void setWeight(float weight);

    float getHeight() const;

    void setHeight(float height);

    float getPassValue() const;

    void setPassValue(float passValue);

    bool isInjury() const;

    void setInjury(bool injury);

    float getSalary() const;

    void setSalary(float salary);

    const string &getPosition() const;

    void setPosition(const string &position);



public:
    FootbalPlayer(string position, string club, const float weight, const float height,  float pass_value,bool injury);

};


#endif //AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
