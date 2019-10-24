//
// Created by tiago on 19/10/2019.
//

#include "Person.h"
using namespace std;

Person::Person(int id,string name, Date birthdayDate){
    this->id = id;
    this->birthdayDate = birthdayDate;
    this->name = name;
}

int Person::getId() const{ return id;}
string Person::getName() const{ return name;}
Date Person::getBirthday() const { return birthdayDate;}

void Person::setId(int id) {this->id = id;}
void Person::setName(string name) { this->name = name;}
void Person::setBirthday(Date birthday){ this->birthdayDate = birthday;}

bool Person::operator<(const Person &person) const {
    return id < person.id;
}
bool Person::operator>(const Person &person) const {
    return id > person.id;
}

bool Person::operator==(const Person &person) const {
    return id == person.id;
}

bool Person::operator!=(const Person &person) const {
    return !(person == *this);
}
