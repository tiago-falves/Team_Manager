//
// Created by tiago on 07/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_EXCEPTIONS_H
#define AEDA_TEAM_MANAGER_EXCEPTIONS_H

#include <string>

using namespace std;

class InexistentId {
public:
    int id;
    InexistentId(int i) {id = i;}
};

class InvalidMonth {
public:
    int month;
    InvalidMonth(int month) {this->month = month;}
};

class PlayerExistsCallUp{
public:
    int id;
    PlayerExistsCallUp(int id) {this->id = id;}
};

class PlayerDontExistsCallUp{
public:
    int id;
    PlayerDontExistsCallUp(int id) {this->id = id;}
};

class GameExistsCallUp{
public:
    Game *game;
    GameExistsCallUp(Game *game) {this->game = game;}
};

class GameDontExistsCallUp{
public:
    Game *game;
    GameDontExistsCallUp(Game *game) {this->game = game;}
};

class ExceptionDate{
public:
    ExceptionDate(){};
};
#endif //AEDA_TEAM_MANAGER_EXCEPTIONS_H
