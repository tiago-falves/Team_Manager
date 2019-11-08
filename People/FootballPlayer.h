#ifndef AEDA_TEAM_MANAGER_FootballPlayer_H
#define AEDA_TEAM_MANAGER_FootballPlayer_H
#pragma once

#include "Person.h"
#include <vector>
using namespace std;

class FootballPlayer: public Person {
private:
    string position;
    string club;
    float weight;
    float height;
    float pass_value;
    bool injury;

public:

    FootballPlayer(string name, Date birthDay,float salary,string position, string club, const float weight, const float height,  float pass_value,bool injury);

    FootballPlayer();

    bool addFootballPlayer(vector<FootballPlayer*> &players);

    bool removeFootballPlayer(vector<FootballPlayer*> &players);

    bool modifyFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer);

    int playerPosition(vector<FootballPlayer*> &players);

    virtual void print(ostream& out) const;

    virtual void read(ifstream *file);

    virtual string type() const;

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



};


#endif //AEDA_TEAM_MANAGER_FootballPlayer_H
