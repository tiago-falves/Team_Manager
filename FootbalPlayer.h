//
// Created by tiago on 09/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#define AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#include "Date.h"
#include "Convocatoria.h"
#include "Game.h"

class FootbalPlayer {
    string name;
    Date bdate; //data de nascimento
    string pos; //posição
    string club;
    float weight;
    float height;
    float pass_value;
    bool injury;
    vector<Convocatoria> convocatoria;
    vector<Game> games;
public:
};


#endif //AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
