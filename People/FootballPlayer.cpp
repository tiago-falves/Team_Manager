//
// Created by tiago on 09/10/2019.
//


#include "FootballPlayer.h"

FootballPlayer::FootballPlayer(string name, Date birthdayDate,float salary, string position, string club, const float weight, const float height, float pass_value,bool injury):Person(name,birthdayDate, salary) {

    this->club = club;
    this->position = position;
    this->weight= weight;
    this->height = height;
    this->pass_value = pass_value;
    this->injury= injury;
}

FootballPlayer::FootballPlayer():Person() {
    this->club = "";
    this->weight= 0;
    this->height = 0;
    this->pass_value = 0.0;
    this->injury= false;

}

string FootballPlayer::type() const {
    return "Football Player";
}
void FootballPlayer::print(ostream& out) const{
    Person::print(cout);
    out << "\tPosition: " << position << endl;
    out << "\tClub: " << club << endl;
    out << "\tWeight: " << to_string(weight) << endl;
    out << "\tHeight: " << to_string(height) << endl;
    out << "\tPass Value: " << to_string(pass_value) << endl;
    out << "\tHealth: ";
    if(injury) out << "Is Injured";
    else out << "Perfectly Healthy";
    out << endl;

}


const string &FootballPlayer::getPosition() const {
    return position;
}

void FootballPlayer::setPosition(const string &position) {
    FootballPlayer::position = position;
}

const string &FootballPlayer::getClub() const {
    return club;
}

void FootballPlayer::setClub(const string &club) {
    FootballPlayer::club = club;
}

float FootballPlayer::getWeight() const {
    return weight;
}

void FootballPlayer::setWeight(float weight) {
    FootballPlayer::weight = weight;
}

float FootballPlayer::getHeight() const {
    return height;
}

void FootballPlayer::setHeight(float height) {
    FootballPlayer::height = height;
}

float FootballPlayer::getPassValue() const {
    return pass_value;
}

void FootballPlayer::setPassValue(float passValue) {
    pass_value = passValue;
}

bool FootballPlayer::isInjury() const {
    return injury;
}

void FootballPlayer::setInjury(bool injury) {
    FootballPlayer::injury = injury;
}

float FootballPlayer::getSalary() const {
    return salary;
}

void FootballPlayer::setSalary(float salary) {
    FootballPlayer::salary = salary;
}

bool FootballPlayer::addFootballPlayer(vector<FootballPlayer*> &players) {
    insert_sorted(players,this);
    return true;
}


bool FootballPlayer::removeFootballPlayer(vector<FootballPlayer*> &players) {
    int index = playerPosition(players);
    if(index != -1){
        players.erase(players.begin()+index);
        return true;
    }
    else return false;
}


bool FootballPlayer::modifyFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer) {
    int index = this->playerPosition(players);
    if(index !=-1){
        players[index]->setSalary(newFootballPlayer->getSalary());
        players[index]->setBirthday(newFootballPlayer->getBirthday());
        players[index]->setName(newFootballPlayer->getName());
        players[index]->setClub(newFootballPlayer->getClub());
        players[index]->setHeight(newFootballPlayer->getHeight());
        players[index]->setInjury(newFootballPlayer->isInjury());
        players[index]->setPassValue(newFootballPlayer->getPassValue());
        players[index]->setPosition(newFootballPlayer->getPosition());
        players[index]->setWeight(newFootballPlayer->getWeight());
        return true;
    }
    return false;
}

int FootballPlayer::playerPosition(vector<FootballPlayer*> &people){
    int index = BinarySearch(people,this);
    return index;
}

void FootballPlayer::read(ifstream *file) {
    Person::read(file);
    string text;
    getline(*file,text);
    position = text;
    getline(*file,text);
    club = text;
    getline(*file,text);
    weight = stof(text);
    getline(*file,text);
    height = stof(text);
    getline(*file,text);
    pass_value = stof(text);
    getline(*file,text);
    bool isInjured;
    if(text == "Healthy") isInjured= false;
    if(text == "Injured") isInjured= true;
}