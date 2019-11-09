//
// Created by tiago on 09/10/2019.
//

#include "Technician.h"



Technician::Technician(): Person(){
    this->name = "";
    this->birthdayDate = Date();

}
Technician::Technician(string name, Date birthday, float salary, string role):Person(name,birthday,salary){
    this->role = role;
}

const string Technician::getRole() const {
    return role;
}

void Technician::setRole(const string &role) {
    Technician::role = role;
}

void Technician::printNicely(ostream &out) const {
    Person::printNicely(cout);
    out << "\tRole: " << role << endl;
}

void Technician::print(ostream &out) const {
    Person::print(out);
    out << role << endl;
}

string Technician::type() const {
    return "Technician";
}
void Technician::read(ifstream *file) {
    Person::read(file);
    string text;
    getline(*file,text);
    role = text;

}