//
// Created by tiago on 22/12/2019.
//

#ifndef AEDA_TEAM_MANAGER_COACH_H
#define AEDA_TEAM_MANAGER_COACH_H

#include "Person.h"
#include <vector>


class Coach : public Person {
private:
    int titlesWon;
    vector<string> coachedTeams;
    bool isCurrentCoach;
public:


    Coach(const string &name, const Date &birthdayDate, float salary, int titlesWon,
          const vector<string> &coachedTeams, const bool &isCurrentCoach);

    Coach();

    int getTitlesWon() const;

    void setTitlesWon(int titlesWon);

    int isActualCoach() const;

    void setIfCurrentCoach(const bool &isCurrentCoach);

    const vector<string> &getCoachedTeams() const;

    void setCoachedTeams(const vector<string> &coachedTeams);

    virtual void modify(Person *newPerson);

    virtual string type() const;

    virtual void read(ifstream *file);

    virtual void print(ostream &out) const;

    bool operator<(const Coach* &coach) const;
    bool operator<(const Coach &coach) const;














};

#endif //AEDA_TEAM_MANAGER_COACH_H
