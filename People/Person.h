
#ifndef AEDA_TEAM_MANAGER_PERSON_H
#define AEDA_TEAM_MANAGER_PERSON_H
#pragma once
#include "..//Date.h"
#include <string>
#include <fstream>
#include <ostream>
#include <iomanip>
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


    static void sortByID(vector<Person*> &people);
    static void sortByName(vector<Person*> &people);

    static vector<Person*> searchByName(vector<Person*> people, string name);

    virtual void modify(Person *newPerson);


    bool operator<(const Person &person) const;
    bool operator<(const Person* &person) const;
    bool operator>(const Person &person) const;
    bool operator==(const Person &rhs) const;
    bool operator!=(const Person &rhs) const;

    friend ostream &operator<<(ostream &os, const Person *person);

    virtual void printNicely(ostream& out) const;
    virtual void print(ostream &os) const;
    virtual void read(ifstream *file);
    virtual string type() const ;

};



#endif //AEDA_TEAM_MANAGER_PERSON_H
