#pragma once
#ifndef AEDA_TEAM_MANAGER_GAME_H
#define AEDA_TEAM_MANAGER_GAME_H

#include <string>
#include <vector>
#include "Person.h"


using namespace std;


class Game {
private:
    string city;
    string country;
    string stadium;
    //vector<CallUpPlayer> called_players;
    vector<Person> referees; //Devia implementar um vetor Pessoa em vez destes dois? ele devia ser um Technician?


    //Para cada jogo da seleção, é necessário guardar a cidade, país e estádio respetivos, os jogadores convocados e
    //participantes no jogo de cada uma das equipas, a equipa de arbitragem, e todos os eventos e estatísticas de jogo
    //para cada jogador nacional (golos, passes, km percorridos, cartões, lesões, etc).
public:
    Game(string city,string country,string stadium,/*vector<CallUpPlayer> called_players,*/vector<Person> referees);

};


#endif //AEDA_TEAM_MANAGER_GAME_H
