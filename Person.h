
#ifndef AEDA_TEAM_MANAGER_PERSON_H
#define AEDA_TEAM_MANAGER_PERSON_H
#pragma once
#include "Date.h"
#include <string>


class Person {
protected:
    string name;
    Date birthdayDate;
public:
    Person(string name, Date birthdayDate);
};


#endif //AEDA_TEAM_MANAGER_PERSON_H
