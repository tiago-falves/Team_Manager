//
// Created by tiago on 06/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_NATIONALTEAM_H
#define AEDA_TEAM_MANAGER_NATIONALTEAM_H


#include <vector>
#include "Date.h"
#include "People//Person.h"
#include "People//FootballPlayer.h"
#include "People//Technician.h"
#include "CallUp.h"




class NationalTeam {
private:
public:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;
    vector<CallUp*> callUps;
    NationalTeam();
    bool readPeople(string fileName);
    bool savePeople(string filename);

    //Handle people vector
    //Alguem sabe por isto no cpp?
    template <class T>
    bool addPerson(vector<T> &people, T person){
        people.push_back(person);
        return true;
    }

    template <class T>
    bool removePerson(vector<T> &people, T person){
        int index;
        try {index = personPosition(people,person);}
        catch (out_of_range){
            cerr << "Tried to remove Person that doesn't exist: " << person->getName() << endl;
            return false;
        }
        people.erase(people.begin()+index);
        return true;
    }

    template <class T>
    bool modifyPerson(vector<T> &people, T person, T newPerson){
        int index;
        try {index = personPosition(people,person);}
        catch (out_of_range){
            cerr << "Tried to modify Person that doesn't exist: " << person->getName() << endl;
            return false;
        }
        person->modify(newPerson);
        return true;
    }

    template <class T>
    int personPosition(vector<T> &people, T person){
        int index = BinarySearch(people,person);
        if(index==-1) throw out_of_range("Person not in vector");
        return index;
    }

    void showEveryone(ostream& out);


    //Handle costs (sallaries + insurance)
    //player costs
    float playerCostCalculator(Date d1, Date d2, int playerID);
    float playerCostCalculatorMonth(int monthNumber, int playerID);
    //team costs
    float teamCostCalculator(Date d1, Date d2);
    float teamCostCalculatorMonth(int monthNumber);
    //team+staff costs
    float allCostCalculator(Date d1, Date d2);
    float allCostCalculatorMonth(int monthNumber);

    //Read CallUps
    void read(ifstream *file);

    //FIND PLAYER IN CALLUPS AND CALCULATE NUMBER OF DAYS HE WAS IN
};



#endif //AEDA_TEAM_MANAGER_NATIONALTEAM_H
