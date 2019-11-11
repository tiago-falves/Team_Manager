#pragma once
#ifndef AEDA_TEAM_MANAGER_GAME_H
#define AEDA_TEAM_MANAGER_GAME_H

#include <string>
#include <vector>
#include "PlayerGameStatistics.h"

using namespace std;

class Game {
private:
    string city;
    string country;
    string stadium;
    vector<PlayerGameStatistics> playerStatistics;
    vector<FootballPlayer *> nationalPlayers;
    vector<FootballPlayer *> enemyPlayers;
    vector<Person> referees;



    //Para cada jogo da seleção, é necessário guardar a cidade, país e estádio respetivos, os jogadores convocados e
    //participantes no jogo de cada uma das equipas, a equipa de arbitragem, e todos os eventos e estatísticas de jogo
    //para cada jogador nacional (golos, passes, km percorridos, cartões, lesões, etc).
public:
    Game(string city,string country,string stadium,vector<PlayerGameStatistics> playerStatistics,vector<Person> referees);

    string getCity() const;
    string getCountry() const;
    string getStadium() const;
    vector<FootballPlayer *> getNationalPlayers() const;
    vector<FootballPlayer *> getEnemyPlayers() const;
    vector<PlayerGameStatistics> getPlayerStatistics() const;
    vector<Person> getReferees();

    void setCity(string city);
    void setCountry(string country);
    void setStadium(string stadium);
    void setNationalPlayers(vector<FootballPlayer *> vec);
    void setEnemyPlayers(vector<FootballPlayer *> vec);
    void setPlayerStatistics(vector<PlayerGameStatistics> statistics);
    void setReferees(vector<Person> refs);

    void print(ostream &out);

    friend ostream& operator<< (ostream& out, const Game& game);
};


#endif //AEDA_TEAM_MANAGER_GAME_H
