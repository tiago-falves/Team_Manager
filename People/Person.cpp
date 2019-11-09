//
// Created by tiago on 19/10/2019.
//


#include "Person.h"

using namespace std;

Person::Person(string name, Date birthdayDate, float salary):id(lastId++){
    this->birthdayDate = birthdayDate;
    this->name = name;
    this->salary = salary;
}
Person::Person(): id(lastId++){
    this->name = "";
    this->birthdayDate = Date();
    this->salary = 0;

}


int Person::getId() const{ return id;}
string Person::getName() const{ return name;}
Date Person::getBirthday() const { return birthdayDate;}
float Person::getSalary() const { return salary;}
//int Person::getLastId() {return lastId;}


void Person::setName(string name) { this->name = name;}
void Person::setBirthday(Date birthday){ this->birthdayDate = birthday;}
void Person::setSalary(float salary) { Person::salary = salary;
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
void Person::printNicely(ostream& out) const{

    out <<  left << setw(4)  << setfill(' ') << id << "|  ";
    out <<  left << setw(30) << setfill(' ') << name  << "| ";
    out <<  left << setw(9) << setfill(' ') <<  birthdayDate.toString()<< "| ";
    out <<  left << setw(6) << setfill(' ') << salary<< "|  "  ;

}


void Person::print(ostream &os) const {
    os << type() << endl;
    os << id << endl;
    os << name << endl;
    os << birthdayDate <<endl;
    os  << salary << endl;
}

void Person::read(ifstream *file) {
    string text;
    Date birthday = Date();
    getline(*file,text);
    name = text;

    getline(*file,text);
    try {birthdayDate = birthday.dateTextConverter(text);}
    catch (InvalidDate) {cerr << "Invalid date " << text << " for: " << name;}


    getline(*file,text);
    try {salary = stof(text);}
    catch (std::invalid_argument ia){ cerr << "Invalid salary " << text << " for: " << name; throw;}


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

void Person::modify(Person *newPerson){
    name = newPerson->getName();
    salary = newPerson->getSalary();
    birthdayDate= newPerson->getBirthday();
}

vector<Person*> Person::searchByName(vector<Person *> people,string name) { //Devo ordenar duas vezes?? ou mais vale usar a sequencial?

    vector<Person*> peopleName;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i]->getName() == name){
            peopleName.push_back(people[i]);
        }
    }
    return peopleName;

}


int Person::lastId = 1;



ostream &operator<<(ostream &os, const Person *person){
    person->print(os);
    return os;
}





