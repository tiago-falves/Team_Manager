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

void Technician::print(ostream &out) const {
    Person::print(cout);

    out <<  left << setw(20) << role << "│  ";
    out <<  left << setw(9) << setfill(' ') << "-------"  << "│ ";
    out <<  left << setw(5) << setfill(' ')<<  "---" << "│ ";
    out <<  left << setw(5) << setfill(' ') << "-----" << " │ ";
    out <<  left << setw(5) << setfill(' ') << "----"<< "│ ";
    out <<  left << setw(5) << setfill(' ') << "----"<< "  │" << endl;
}

void Technician::printToFile(ostream &out) const {
    Person::printToFile(out);
    out << role << endl;
    out <<  "::::::::::" << endl;
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