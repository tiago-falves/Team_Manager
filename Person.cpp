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

Person::Person(string peopleFile, vector<Person*> people) {

}



int Person::getId() const{ return id;}
string Person::getName() const{ return name;}
Date Person::getBirthday() const { return birthdayDate;}

void Person::setId(int id) {this->id = id;}
void Person::setName(string name) { this->name = name;}
void Person::setBirthday(Date birthday){ this->birthdayDate = birthday;}


bool Person::addPerson(vector<Person*> &people) {
    insert_sorted(people,this);
    return true;
}

bool Person::removePerson(vector<Person*> &people) {
    int index = personPosition(people);
    if(index != -1){
        people.erase(people.begin()+index);
        return true;
    }
    else return false;
}


bool Person::modifyPerson(vector<Person*> &people, Person *newPerson) {
    int index = this->personPosition(people);
    if(index !=-1){
        people[index] = newPerson;
        return true;
    }
    return false;
}
int Person::personPosition(vector<Person*> &people){
    int index = BinarySearch(people,this);
    return index;
}





bool Person::operator<(const Person &person) const {
    return id < person.id;
}

bool Person::operator<(const Person* &person) const {
    return id < person->id;
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

string Person::type() const{
    return "Person";
}


//Prints person to the screen
void Person::print() const{
    cout << type() << endl;
    cout << "\tName:" << name << endl;
    cout << "\tBirthday:" << birthdayDate.toString() << endl;
    cout << "\tId: " << to_string(id) << endl;

}