
#ifndef AEDA_TEAM_MANAGER_PERSON_H
#define AEDA_TEAM_MANAGER_PERSON_H
#pragma once
#include "..//Date.h"
#include <string>
#include <fstream>
#include <ostream>
#include "..//Utilities.h"



class Person {

protected:
    int id;
    string name;
    Date birthdayDate;
    float salary;
    static int lastId;
public:
    Person(string name, Date birthdayDate, float salary);
    Person();

    static int getLastId();
    int getId() const;
    string getName() const;
    Date getBirthday() const;
    float getSalary() const;


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

    friend ostream &operator<<(ostream &os, const Person *person);

    virtual void print(ostream& out) const;
    virtual void read(ifstream *file);
    virtual string type() const ;

};



#endif //AEDA_TEAM_MANAGER_PERSON_H
