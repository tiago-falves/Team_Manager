
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
    /**
     * @brief Construct a new Person object
     * 
     * @param name 
     * @param birthdayDate 
     * @param salary 
     */
    Person(string name, Date birthdayDate, float salary);


    Person();

    static int getLastId();


    /*****************************
     **********GETTERS************
     *****************************/

    int getId() const;
    string getName() const;
    Date getBirthday() const;
    float getSalary() const;

    /*****************************
     **********SETTERS************
     *****************************/

    void setName(string name);
    void setBirthday(Date birthdayDate);
    void setSalary(float salary);

    /***************************************
     **********VIRTUAL FUNCTIONS************
     ***************************************/

    virtual void modify(Person *newPerson);
    virtual void print(ostream& out) const;
    virtual void printToFile(ostream &os) const;
    virtual void read(ifstream *file);
    virtual string type() const ;

    /***************************************
     **************OPERATORS****************
     ***************************************/

    bool operator<(const Person &person) const;
    bool operator<(const Person* &person) const;
    bool operator>(const Person &person) const;
    bool operator==(const Person &rhs) const;
    bool operator!=(const Person &rhs) const;

    friend ostream &operator<<(ostream &os, const Person *person);



};



#endif //AEDA_TEAM_MANAGER_PERSON_H
