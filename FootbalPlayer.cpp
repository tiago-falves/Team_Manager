//
// Created by tiago on 09/10/2019.
//

#include "FootbalPlayer.h"

FootbalPlayer::FootbalPlayer(int id, string name, Date birthdayDate,string position, string club, const float weight, const float height, float pass_value,bool injury):Person(id,name,birthdayDate) {

    this->id = id;
    this->name = name;
    this->birthdayDate = birthdayDate;
    this->position=position;
    this->club = club;
    this->weight= weight;
    this->height = height;
    this->pass_value = pass_value;
    this->injury= injury;

}
FootbalPlayer::FootbalPlayer():Person(id,name,birthdayDate) {
    this->id = 0;
    this->name = "Joao";
    this->birthdayDate = Date(1,1,2000);
    this->position="zas";
    this->club = "";
    this->weight= 0;
    this->height = 0;
    this->pass_value = 0.0;
    this->injury= false;

}

const string &FootbalPlayer::getPosition() const {
    return position;
}

void FootbalPlayer::setPosition(const string &position) {
    FootbalPlayer::position = position;
}

const string &FootbalPlayer::getClub() const {
    return club;
}

void FootbalPlayer::setClub(const string &club) {
    FootbalPlayer::club = club;
}

float FootbalPlayer::getWeight() const {
    return weight;
}

void FootbalPlayer::setWeight(float weight) {
    FootbalPlayer::weight = weight;
}

float FootbalPlayer::getHeight() const {
    return height;
}

void FootbalPlayer::setHeight(float height) {
    FootbalPlayer::height = height;
}

float FootbalPlayer::getPassValue() const {
    return pass_value;
}

void FootbalPlayer::setPassValue(float passValue) {
    pass_value = passValue;
}

bool FootbalPlayer::isInjury() const {
    return injury;
}

void FootbalPlayer::setInjury(bool injury) {
    FootbalPlayer::injury = injury;
}

float FootbalPlayer::getSalary() const {
    return salary;
}

void FootbalPlayer::setSalary(float salary) {
    FootbalPlayer::salary = salary;
}
