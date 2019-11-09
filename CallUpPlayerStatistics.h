//
// Created by tiago on 22/10/2019.
//

#ifndef AEDA_TEAM_MANAGER_CALLUPGAMESTATISTICS_H
#define AEDA_TEAM_MANAGER_CALLUPGAMESTATISTICS_H
#include "Date.h"

class CallUpPlayerStatistics {
private:
    int playerID;
    Date begginingDate;
    Date endDate;
public:
    CallUpPlayerStatistics(int playerID, Date begginingDate, Date endDate);

    //GET METHODS
    int getPlayerID() const;
    Date getBegDate() const;
    Date getEndDate() const;

    //SET METHODS
    void setPlayerID(const int &playerID);
    void setBegDate(const Date &begginingDate);
    void setEndDate(const Date &endDate);

};


#endif //AEDA_TEAM_MANAGER_CALLUPGAMESTATISTICS_H
