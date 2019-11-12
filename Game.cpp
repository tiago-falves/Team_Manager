//
// Created by tiago on 09/10/2019.
//

#include "Game.h"

Game::Game(string city, string country, string stadium, vector<PlayerGameStatistics> playerStatistics, vector<string> referees, vector<string> ePlayer):id(lastId++) {
    this->city =city;
    this->country = country;
    this->stadium=stadium;
    this->playerStatistics=playerStatistics;
    this->referees=referees;
    this->enemyPlayers = ePlayer;

}

ostream& operator<<(ostream &out, const Game& game) {
    out << "Location: " << game.stadium << ", " << game.city << ", " << game.country << endl << endl;
    return out;
}

/*****************************************************
 *******************GET FUNCTIONS*********************
 *****************************************************/

int Game::getID() const {
    return id;
}

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

vector<string> Game::getEnemyPlayers() const {
    return this->enemyPlayers;
}

vector<PlayerGameStatistics> Game::getPlayerStatistics() const {
    return this->playerStatistics;
}

vector<string> Game::getReferees() {
    return referees;
}

/*****************************************************
 *******************SET FUNCTIONS*********************
 *****************************************************/
void Game::setPlayerStatistics(vector<PlayerGameStatistics> statistics){
    this->playerStatistics = statistics;
}

void Game::setReferees(vector<string> refs) {
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
void Game::setEnemyPlayers(vector<string> vec){
    this->enemyPlayers = vec;
}

/*****************************************************
 *****************PRINT FUNCTIONS*********************
 *****************************************************/

void Game::print(ostream &out) {

}

/*****************************************************
 ******************AUX FUNCTIONS*********************
 *****************************************************/

void Game::addEnemyPlayer(string player) {
    this->enemyPlayers.push_back(player);
}

void Game::addNationalPlayer(FootballPlayer *player) {
    this->nationalPlayers.push_back(player);
    this->playerStatistics.push_back(PlayerGameStatistics(player));
}

void Game::removeNationalPlayer(FootballPlayer *player) {

    vector<FootballPlayer *>::iterator it;

    for(it = nationalPlayers.begin(); it < nationalPlayers.end(); it++){
        if((*it)->getId() == (*player).getId()){ nationalPlayers.erase(it); }
        return;
    }
}

void Game::removeEnemyPlayer(string player){

    vector<string>::iterator it;

    for(it = enemyPlayers.begin(); it < enemyPlayers.end(); it++){
        if((*it) == (player)){ enemyPlayers.erase(it); }
        return;
    }
}

PlayerGameStatistics Game::getSpecificPlayerStatistics(FootballPlayer *player) {

    for(PlayerGameStatistics p : playerStatistics){
        if(p.getPlayer() == player){
            return p;
        }
    }
    return playerStatistics[0];
}

void Game::read(ifstream *file) {
    string text;
}