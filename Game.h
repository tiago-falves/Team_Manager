#pragma once
#ifndef AEDA_TEAM_MANAGER_GAME_H
#define AEDA_TEAM_MANAGER_GAME_H

#include <string>
#include <vector>
#include "PlayerGameStatistics.h"

using namespace std;

class Game {
private:
    int id;
    string city;
    string country;
    string stadium;
    vector<PlayerGameStatistics> playerStatistics;
    vector<FootballPlayer *> nationalPlayers;
    vector<string> enemyPlayers;
    vector<string> referees;
    static int lastID;



    //Para cada jogo da seleção, é necessário guardar a cidade, país e estádio respetivos, os jogadores convocados e
    //participantes no jogo de cada uma das equipas, a equipa de arbitragem, e todos os eventos e estatísticas de jogo
    //para cada jogador nacional (golos, passes, km percorridos, cartões, lesões, etc).
public:
    Game(string city,string country,string stadium,vector<PlayerGameStatistics> playerStatistics,vector<string> referees, vector<FootballPlayer *> nationalP, vector<string> enemyP);

    Game();
    int getID() const;
    string getCity() const;
    string getCountry() const;
    string getStadium() const;
    vector<FootballPlayer *> getNationalPlayers() const;
    vector<string> getEnemyPlayers() const;
    vector<PlayerGameStatistics> getPlayerStatistics() const;
    vector<string> getReferees();

    void setCity(string city);
    void setCountry(string country);
    void setStadium(string stadium);
    void setNationalPlayers(vector<FootballPlayer *> vec);
    void setEnemyPlayers(vector<string> vec);
    void setPlayerStatistics(vector<PlayerGameStatistics> statistics);
    void setReferees(vector<string> refs);


    void addNationalPlayer(FootballPlayer * player);
    void removeNationalPlayer(FootballPlayer * player);
    PlayerGameStatistics getSpecificPlayerStatistics(FootballPlayer * player);
    void printIntoFile(ostream &os) const;
    void printStatistics(ostream &os, PlayerGameStatistics statistics);

    friend ostream& operator<< (ostream& out, const Game& game);
};


#endif //AEDA_TEAM_MANAGER_GAME_H
