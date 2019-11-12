//
// Created by tiago on 09/10/2019.
//

#include "Game.h"

Game::Game(string city, string country, string stadium, vector<PlayerGameStatistics> playerStatistics, vector<string> referees, vector<FootballPlayer *> nationalP, vector<string> enemyP):id(lastID++) {
    this->city =city;
    this->country = country;
    this->stadium=stadium;
    this->playerStatistics=playerStatistics;
    this->referees=referees;
    this->nationalPlayers = nationalP;
    this->enemyPlayers = enemyP;

}

Game::Game():id(lastID++){}


ostream& operator<<(ostream &out, const Game& game) {
    out << "Location: " << game.stadium << ", " << game.city << ", " << game.country << endl << endl;
    return out;
}

/*****************************************************
 *******************GET FUNCTIONS*********************
 *****************************************************/

int Game::getID() const {
    return this->id;
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
    return this->referees;
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


/*****************************************************
 ******************AUX FUNCTIONS*********************
 *****************************************************/

void Game::addNationalPlayer(FootballPlayer *player) {
    this->nationalPlayers.push_back(player);
    this->playerStatistics.push_back(PlayerGameStatistics(player->getId()));
}

void Game::removeNationalPlayer(FootballPlayer *player) {

    vector<FootballPlayer *>::iterator it;

    for(it = nationalPlayers.begin(); it < nationalPlayers.end(); it++){
        if((*it)->getId() == (*player).getId()){ nationalPlayers.erase(it); }
        return;
    }
}

PlayerGameStatistics Game::getSpecificPlayerStatistics(FootballPlayer *player) {

    for(PlayerGameStatistics p : playerStatistics){
        if(p.getPlayerID() == player->getId()){
            return p;
        }
    }
    return playerStatistics[0];
}

void Game::printIntoFile(ostream &os) const{
    os << id << endl;
    os << city << endl;
    os << country << endl;
    os << stadium << endl;

    for(int i = 0; i < playerStatistics.size(); i++){
        if(i == playerStatistics.size() - 1){
            os << playerStatistics[i].getID() << endl;
        }
        else {
            os << playerStatistics[i].getID() << ",";
        }
    }

    for(int i = 0; i < nationalPlayers.size(); i++){
        if(i == nationalPlayers.size() - 1){
            os << nationalPlayers[i]->getId() << endl;
        }
        else {
            os << nationalPlayers[i]->getId() << ",";
        }
    }

    for(int i = 0; i < enemyPlayers.size(); i++){
        if(i == enemyPlayers.size() - 1){
            os << enemyPlayers[i] << endl;
        }
        else {
            os << enemyPlayers[i] << ",";
        }
    }

    for(int i = 0; i < referees.size(); i++){
        if(i == referees.size() - 1){
            os << referees[i] << endl;
        }
        else {
            os << referees[i] << ",";
        }
    }

}

int Game::lastID = 1;