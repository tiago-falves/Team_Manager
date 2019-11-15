//
// Created by tiago on 19/10/2019.
//

#include "PlayerGameStatistics.h"

PlayerGameStatistics::PlayerGameStatistics(int playerID, int numberOfGoals, int minutesPlayed, int kilometers, int numberOfPasses, int numberOfYellowCards, int numberOfRedCards)/*:id(lastId++)*/ {
    this->numberOfGoals=numberOfGoals;
    this->minutesPlayed=minutesPlayed;
    this->kilometers=kilometers;
    this->playerID = playerID;
    this->numberOfRedCards = numberOfRedCards;
    this->numberOfYellowCards = numberOfYellowCards;
    this->numberOfPasses = numberOfPasses;
}

PlayerGameStatistics::PlayerGameStatistics(int playerID):id(lastId++) {

    this->playerID = playerID;
    this->numberOfGoals = 0;
    this->minutesPlayed = 0;
    this->kilometers = 0;
    this->numberOfPasses = 0;
    this->numberOfYellowCards = 0;
    this->numberOfRedCards = 0;
}
PlayerGameStatistics::PlayerGameStatistics() {
    this->playerID = 0;
    this->numberOfGoals = 0;
    this->minutesPlayed = 0;
    this->kilometers = 0;
    this->numberOfPasses = 0;
    this->numberOfYellowCards = 0;
    this->numberOfRedCards = 0;
}

int PlayerGameStatistics::getPlayerID() const {
    return playerID;
}

int PlayerGameStatistics::getId() const {
    return id;
}
void PlayerGameStatistics::setPlayerID(int player) {
    this->playerID = player;
}

int PlayerGameStatistics::getNumberOfGoals() const {
    return numberOfGoals;
}

void PlayerGameStatistics::setNumberOfGoals(int numberOfGoals) {
    PlayerGameStatistics::numberOfGoals = numberOfGoals;
}

int PlayerGameStatistics::getMinutesPlayed() const {
    return minutesPlayed;
}

void PlayerGameStatistics::setMinutesPlayed(int minutesPlayed) {
    PlayerGameStatistics::minutesPlayed = minutesPlayed;
}

int PlayerGameStatistics::getKilometers() const {
    return kilometers;
}

void PlayerGameStatistics::setKilometers(int kilometers) {
    PlayerGameStatistics::kilometers = kilometers;
}

int PlayerGameStatistics::getNumberOfPasses() const {
    return numberOfPasses;
}

void PlayerGameStatistics::setNumberOfPasses(int numberOfPasses) {
    PlayerGameStatistics::numberOfPasses = numberOfPasses;
}

int PlayerGameStatistics::getNumberOfYellowCards() const {
    return numberOfYellowCards;
}

void PlayerGameStatistics::setNumberOfYellowCards(int numberOfYellowCards) {
    PlayerGameStatistics::numberOfYellowCards = numberOfYellowCards;
}

int PlayerGameStatistics::getNumberOfRedCards() const {
    return numberOfRedCards;
}

void PlayerGameStatistics::setNumberOfRedCards(int numberOfRedCards) {
    PlayerGameStatistics::numberOfRedCards = numberOfRedCards;
}

void PlayerGameStatistics::print(ostream &os) {
    os <<  left << setw(11)  << setfill(' ') << playerID << "│ ";
    os <<  left << setw(15) << setfill(' ') << numberOfGoals << "│ ";
    os <<  left << setw(16) << setfill(' ') <<  minutesPlayed << "│ ";
    os <<  left << setw(12) << setfill(' ') << kilometers << "│ "  ;
    os <<  left << setw(18) << setfill(' ') << numberOfPasses << "│ "  ;
    os <<  left << setw(14) << setfill(' ') << numberOfYellowCards << "│ "  ;
    os <<  left << setw(11) << setfill(' ') << numberOfRedCards << "│ "  ;
    os << endl;
}

int PlayerGameStatistics::lastId = 1;