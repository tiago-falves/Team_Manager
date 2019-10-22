//
// Created by tiago on 19/10/2019.
//

#include "CallUp.h"

CallUp::CallUp(vector<Game> games,vector<CallUpPlayerStatistics> playerStatistics, Date begginingDate, Date endDate) {
    this->games=games;
    this->playerStatistics = playerStatistics;
    this->begginingDate=begginingDate;
    this->endDate=endDate;

}
