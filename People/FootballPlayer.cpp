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
    this->position = "";
    this->club = "";
    this->weight= 0;
    this->height = 0;
    this->pass_value = 0.0;
    this->injury= false;

}

string FootballPlayer::type() const {
    return "Football Player";
}
void FootballPlayer::print(ostream &out) const {

    Person::print(cout);
    out <<  left << setw(20)  << setfill(' ') << position << "│ ";
    out <<  left << setw(9) << setfill(' ') << club  << " │";
    out <<  left << setw(5) << setfill(' ')<< fixed  << setprecision(2)  <<  weight<< " │";
    out <<  left << setw(6) << setfill(' ') << fixed  << setprecision(2) <<  height<< " │";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) << pass_value<< " │";
    if(injury) out <<  left << setw(5) << setfill(' ') << "Injured"<< " │" << endl;
    else out <<  left << setw(5) << setfill(' ') << "Healthy"<< " │" << endl;


}

void FootballPlayer::printToFile(ostream &os) const {
    Person::printToFile(os);
    os << position << endl;
    os << club << endl;
    os << fixed << setprecision(2) <<  weight << endl;
    os << fixed << setprecision(2) << height << endl;
    os << fixed << setprecision(2) << pass_value << endl;
    if (injury) os << "Injured";
    else os << "Healthy";
    os << endl << "::::::::::";
    os << endl;
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




void FootballPlayer::modify(Person *newPerson){
    FootballPlayer *player = (FootballPlayer*) newPerson;
    Person::modify(newPerson);
    position = player->getPosition();
    club = player->getClub();
    weight= player->getWeight();
    height = player->getHeight();
    pass_value = player->getPassValue();
    injury  = player->isInjury();


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