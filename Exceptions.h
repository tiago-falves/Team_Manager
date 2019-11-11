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

#endif //AEDA_TEAM_MANAGER_EXCEPTIONS_H
