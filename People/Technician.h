#pragma once
#ifndef AEDA_TEAM_MANAGER_TECHINICALTEAM_H
#define AEDA_TEAM_MANAGER_TECHINICALTEAM_H

#include "Person.h"


class Technician: public Person{

    string role;
public:

    const string getRole() const;
    void setRole(const string &role);

    Technician();
    Technician(string name, Date birthday, float salary, string role);
    virtual string type() const ;
    virtual void print(ostream& out) const;
    virtual void printToFile(ostream &out) const;
    virtual void read(ifstream *file);

};


#endif //AEDA_TEAM_MANAGER_TECHINICALTEAM_H
