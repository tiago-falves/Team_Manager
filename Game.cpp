//
// Created by tiago on 09/10/2019.
//

#include "Game.h"

Game::Game(string city, string country, string stadium,/* vector<CallUpPlayer> called_players*/ vector<Person> referees) {
    this->city =city;
    this->country = country;
    this->stadium=stadium;
    //this->called_players=called_players;
    this->referees=referees;

}
