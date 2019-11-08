//
// Created by tiago on 09/10/2019.
//

#include "Game.h"

Game::Game(string city, string country, string stadium, vector<PlayerGameStatistics> playerStatistics, vector<Person> referees) {
    this->city =city;
    this->country = country;
    this->stadium=stadium;
    this->playerStatistics=playerStatistics;
    this->referees=referees;

}

ostream& operator<<(ostream &out, const Game& game) {
    out << "Location: " << game.stadium << ", " << game.city << ", " << game.country << endl << endl;
}

/*****************************************************
 *******************GET FUNCTIONS*********************
 *****************************************************/
string Game::getCountry() const {
    return country;
}
string Game::getCity() const {
    return city;
}
string Game::getStadium() const {
    return stadium;
}

vector<FootballPlayer> Game::getPlayers() const {
    return vector<FootballPlayer>();
}

vector<PlayerGameStatistics> Game::getPlayerStatistics() const {
    return vector<PlayerGameStatistics>();
}

vector<Person> Game::getReferees() {
    return vector<Person>();
}

/*****************************************************
 *******************SET FUNCTIONS*********************
 *****************************************************/
void Game::setPlayerStatistics(vector<PlayerGameStatistics> statistics){
    this->playerStatistics = statistics;
}

void Game::setReferees(vector<Person> refs) {
    this->referees = refs;
}

void Game::setCity(string city) {
    this->city = city;
}
void Game::setStadium(string stadium) {
    this->stadium = stadium;
}
void Game::setCountry(string country) {
    this->country = country;
}

<<<<<<< HEAD
void Game::setCalled_players(vector<FootballPlayer> vec) {
    this->players = vec;
}
=======
ostream& operator<<(ostream &out, const Game& game) {
    out << "Location: " << game.stadium << ", " << game.city << ", " << game.country << endl << endl;
    return out;
}
>>>>>>> b9a5f9f822bf4b9677bddf6fa6abfae3875a475e
