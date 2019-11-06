//
// Created by tiago on 19/10/2019.
//

#include "Person.h"
using namespace std;

Person::Person(string name, Date birthdayDate){
    this->birthdayDate = birthdayDate;
    this->name = name;
}
Person::Person() {
    this->name = "";
    this->birthdayDate = Date(1,1,2000);
    this->salary = 0;

}


int Person::getId() const{ return id;}
string Person::getName() const{ return name;}
Date Person::getBirthday() const { return birthdayDate;}
float Person::getSalary() const { return salary;}
//int Person::getLastId() {return lastId;}


void Person::setId(int id) {this->id = id;}
void Person::setName(string name) { this->name = name;}
void Person::setBirthday(Date birthday){ this->birthdayDate = birthday;}
void Person::setSalary(float salary) { Person::salary = salary;
}


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
        people[index]->setName(newPerson->getName());
        people[index]->setBirthday(newPerson->getBirthday());
        people[index]->setSalary(newPerson->getSalary());
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
    cout << type() << endl; //Porque que nao esta a imprimir quando é Pessoa?
    cout << "\tName:" << name << endl;
    cout << "\tBirthday:" << birthdayDate.toString() << endl;
    cout << "\tId: " << to_string(id) << endl;

}

bool nameComparable(const Person* person1, const Person* person2){
    return (person1->getName() < person2->getName());
}

void Person::sortByID(vector<Person *> &people) {
    sort(people.begin(),people.end());
}

void Person::sortByName(vector<Person *> &people) {
    sort(people.begin(),people.end(),nameComparable);
}


vector<Person*> Person::searchByName(vector<Person *> people,string name) { //Devo ordenar duas vezes?? ou mais vale usar a sequencial?

    vector<Person*> peopleName;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i]->getName() == name){
            peopleName.push_back(people[i]);
        }
    }
    return peopleName;


    /*Person::sortByName(people);

    bool found = false;

    int middle = -1;
    int left = 0, right = people.size() - 1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (people[middle]->getName() < name)
            left = middle + 1;
        else if (name < people[middle]->getName())
            right= middle - 1;
        else{
            found = true;
            break; // encontrou
        }
    }
    if (found){
        return people[middle];
    }
    sortByID(people);*/

}


//int Person::lastId = 0;





