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
void Person::print(ostream& out) const{

    /*out << type() << endl; //Porque que nao esta a imprimir quando é Pessoa?
    out << "\tId: " << to_string(id) << endl;
    out << "\tName:" << name << endl;
    out << "\tBirthday:" << birthdayDate.toString() << endl;
    out << "\tSalary: " << fixed <<setprecision(2) << salary << endl;*/

    out <<  left << setw(4)  << setfill(' ') << id << "│  ";
    out <<  left << setw(20) << setfill(' ') << name  << "│ ";
    out <<  left << setw(11) << setfill(' ') <<  birthdayDate.toString()<< "│ ";
    out <<  left << setw(9) << setfill(' ') << salary<< "│  "  ;
}


void Person::printToFile(ostream &os) const {
    os << type() << endl;
    os << id << endl;
    os << name << endl;
    os << birthdayDate <<endl;
    os  << fixed << setprecision(2) << salary << endl;
}

void Person::read(ifstream *file) {
    string text;
    Date birthday = Date();

    getline(*file,text);
    try {id = stoi(text);}
    catch (std::invalid_argument ia){ cerr << "Invalid ID " << text << " for: " << name; throw;}

    getline(*file,text);
    name = text;

    getline(*file,text);
    try {birthdayDate = birthday.dateTextConverter(text);}
    catch (InvalidDate) {cerr << "Invalid date " << text << " for: " << name;}


    getline(*file,text);
    try {salary = stof(text);}
    catch (std::invalid_argument ia){ cerr << "Invalid salary " << text << " for: " << name; throw;}


}




void Person::modify(Person *newPerson){
    name = newPerson->getName();
    salary = newPerson->getSalary();
    birthdayDate= newPerson->getBirthday();
}



int Person::lastId = 1;



ostream &operator<<(ostream &os, const Person *person){
    person->print(os);
    return os;
}






