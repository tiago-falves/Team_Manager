//
// Created by tiago on 19/10/2019.
//

#include "PlayerGameStatistics.h"

PlayerGameStatistics::PlayerGameStatistics(int numberOfGoals,int minutesPlayed, int kilometers) {
    this->numberOfGoals=numberOfGoals;
    this->minutesPlayed=minutesPlayed;
    this->kilometers=kilometers;
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
