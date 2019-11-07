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


bool Person::addPerson(vector<Person*> &people) {
    insert_sorted(people,this);
    return true;
}

bool Person::removePerson(vector<Person*> &people) {
    int index;
    try {index = personPosition(people);}
    catch (out_of_range){
        cerr << "Tried to remove Person that doesn't exist: " << name << endl;
        return false;
    }
    people.erase(people.begin()+index);
    return true;

}

bool Person::modifyPerson(vector<Person*> &people, Person *newPerson) {
    int index;
    try {index = personPosition(people);}
    catch (out_of_range){
        cerr << "Tried to modify Person that doesn't exist: " << name << endl;
        return false;
    }
    people[index]->setName(newPerson->getName());
    people[index]->setBirthday(newPerson->getBirthday());
    people[index]->setSalary(newPerson->getSalary());
    return true;
}


int Person::personPosition(vector<Person*> &people){
    int index = BinarySearch(people,this);
    if(index==-1) throw out_of_range("Person not in vector");
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
void Person::print(ostream& out) const{
    out << type() << endl; //Porque que nao esta a imprimir quando é Pessoa?
    out << "\tId: " << to_string(id) << endl;
    out << "\tName:" << name << endl;
    out << "\tBirthday:" << birthdayDate.toString() << endl;
    out << "\tSalary: " << to_string(salary) << endl;
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
    salary = stof(text);
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


int Person::lastId = 0;

ostream &operator<<(ostream &os, const Person *person){
    person->print(os);
    return os;
}





