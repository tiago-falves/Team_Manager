#pragma once
#ifndef AEDA_TEAM_MANAGER_GAME_H
#define AEDA_TEAM_MANAGER_GAME_H

#include <string>
#include <vector>
#include "People//FootballPlayer.h"
#include "PlayerGameStatistics.h"


using namespace std;


class Game {
private:
    string city;
    string country;
    string stadium;
    vector<PlayerGameStatistics> playerStatistics;
    vector<FootballPlayer> players;
    vector<Person> referees;



    //Para cada jogo da seleção, é necessário guardar a cidade, país e estádio respetivos, os jogadores convocados e
    //participantes no jogo de cada uma das equipas, a equipa de arbitragem, e todos os eventos e estatísticas de jogo
    //para cada jogador nacional (golos, passes, km percorridos, cartões, lesões, etc).
public:
    Game(string city,string country,string stadium,vector<PlayerGameStatistics> playerStatistics,vector<Person> referees);

    string getCity() const;
    string getCountry() const;
    string getStadium() const;
    vector<FootballPlayer> getPlayers() const;

    void setCity(string city);
    void setCountry(string country);
    void setStadium(string stadium);
    void setCalled_players(vector<FootballPlayer> vec);

    friend ostream& operator<< (ostream& out, const Game& game);
};


#endif //AEDA_TEAM_MANAGER_GAME_H
