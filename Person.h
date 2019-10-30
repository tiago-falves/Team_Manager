
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
    Person(string peopleFile, vector<Person> people);
    int getId() const;
    string getName() const;
    Date getBirthday() const;


    void setId(int id);
    void setName(string name);
    void setBirthday(Date birthdayDate);


    bool addPerson(vector<Person> &people);
    bool removePerson(vector<Person> &people);
    bool modifyPerson(vector<Person> &people, Person newPerson);
    int personPosition(vector<Person> &people);


    bool operator<(const Person &person) const;
    bool operator>(const Person &person) const;
    bool operator==(const Person &rhs) const;
    bool operator!=(const Person &rhs) const;
};


#endif //AEDA_TEAM_MANAGER_PERSON_H
