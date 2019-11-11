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
    return out;
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

vector<FootballPlayer *> Game::getNationalPlayers() const {
    return this->nationalPlayers;
}

vector<FootballPlayer *> Game::getEnemyPlayers() const {
    return this->enemyPlayers;
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

void Game::setNationalPlayers(vector<FootballPlayer *> vec) {
    this->nationalPlayers = vec;
}
void Game::setEnemyPlayers(vector<FootballPlayer *> vec){
    this->enemyPlayers = vec;
}

/*****************************************************
 *****************PRINT FUNCTIONS*********************
 *****************************************************/

void Game::print(ostream &out) {
    
}

