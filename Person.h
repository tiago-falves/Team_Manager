
#ifndef AEDA_TEAM_MANAGER_PERSON_H
#define AEDA_TEAM_MANAGER_PERSON_H
#pragma once
#include "Date.h"
#include <string>


class Person {


protected:
    int id;
    string name;
    Date birthdayDate;
public:
    Person(int id,string name, Date birthdayDate);
    int getId() const;
    string getName() const;
    Date getBirthday() const;
    void setId(int id);
    void setName(string name);
    void setBirthday(Date birthdayDate);
    bool operator<(const Person &person) const;
    bool operator>(const Person &person) const;
    bool operator==(const Person &rhs) const;
    bool operator!=(const Person &rhs) const;
};


#endif //AEDA_TEAM_MANAGER_PERSON_H
