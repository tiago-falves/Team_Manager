
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
    float salary;
    //static int lastId;
public:
    Person(string name, Date birthdayDate);
    Person();

    virtual string type() const ;
    //static int getLastId();

    int getId() const;
    string getName() const;
    Date getBirthday() const;
    float getSalary() const;


    void setId(int id);
    void setName(string name);
    void setBirthday(Date birthdayDate);
    void setSalary(float salary);



    bool addPerson(vector<Person*> &people);
    bool removePerson(vector<Person*> &people);
    bool modifyPerson(vector<Person*> &people, Person *newPerson);
    int personPosition(vector<Person*> &people);

    static void sortByID(vector<Person*> &people);
    static void sortByName(vector<Person*> &people);

    static vector<Person*> searchByName(vector<Person*> people, string name);

    bool operator<(const Person &person) const;
    bool operator<(const Person* &person) const;

    bool operator>(const Person &person) const;
    bool operator==(const Person &rhs) const;
    bool operator!=(const Person &rhs) const;

    virtual void print() const;
    virtual void read(ifstream *file);
};



#endif //AEDA_TEAM_MANAGER_PERSON_H
