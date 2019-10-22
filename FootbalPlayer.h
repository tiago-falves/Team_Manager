#ifndef AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#define AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
#pragma once
#include "Date.h"
#include "Person.h"




#include <vector>
using namespace std;

class FootbalPlayer: public Person {
private:
    string position;
    string club;
    float weight;
    float height;
    float pass_value;
    bool injury;
    //Para os jogadores,suponha que estes não recebem salários diretamente, mas que a seleção tem de pagar seguros que dependem
    //do número de dias do jogador na seleção e do respetivo valor do passe.
public:
    FootbalPlayer(string position, string club, const float weight, const float height,  float pass_value,bool injury);
};


#endif //AEDA_TEAM_MANAGER_FOOTBALPLAYER_H
