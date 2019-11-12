//
// Created by tiago on 19/10/2019.
//

#include "PlayerGameStatistics.h"

PlayerGameStatistics::PlayerGameStatistics(FootballPlayer * player, int numberOfGoals,int minutesPlayed, int kilometers,int numberOfPasses, int numberOfYellowCards, int numberOfRedCards):id(lastId++) {

    this->player = player;
    this->numberOfGoals=numberOfGoals;
    this->minutesPlayed=minutesPlayed;
    this->kilometers=kilometers;
    this->numberOfPasses = numberOfPasses;
    this->numberOfYellowCards = numberOfYellowCards;
    this->numberOfRedCards = numberOfRedCards;

}

PlayerGameStatistics::PlayerGameStatistics(FootballPlayer *player):id(lastId++) {

    this->player = player;
    this->numberOfGoals = 0;
    this->minutesPlayed = 0;
    this->kilometers = 0;
    this->numberOfPasses = 0;
    this->numberOfYellowCards = 0;
    this->numberOfRedCards = 0;
}

FootballPlayer *PlayerGameStatistics::getPlayer() const {
    return player;
}

void PlayerGameStatistics::setPlayer(FootballPlayer *player) {
    PlayerGameStatistics::player = player;
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

void PlayerGameStatistics::print(ostream &out) {
    out <<  left << setw(20)  << setfill(' ') << player->getName() << "│ ";
    out <<  left << setw(20)  << setfill(' ') << numberOfGoals << "│ ";
    out <<  left << setw(9) << setfill(' ') << minutesPlayed  << " │";
    out <<  left << setw(4) << setfill(' ')<< fixed  << setprecision(2)  <<  kilometers<< " │";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) <<  numberOfPasses << " │";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) << numberOfYellowCards << " │";
    out <<  left << setw(5) << setfill(' ') << fixed  << setprecision(2) << numberOfRedCards << " │";
}
