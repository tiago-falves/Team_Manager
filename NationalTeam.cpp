//
// Created by tiago on 06/11/2019.
//

#include "NationalTeam.h"
#include "Date.h"
#include <algorithm>
#include <fstream>
using namespace std;


NationalTeam::NationalTeam() {

}


bool NationalTeam::readPeople(string fileName) {
    string text;
    ifstream peopleFile;
    Date birthday = Date();
    peopleFile.open("..//Files//" + fileName);
    if(peopleFile.fail()){
        cout << "Error Opening File";
        return false;
    }
    else{
        getline(peopleFile, text);
        if(text == "People File"){
            while(!peopleFile.eof()){
                Person *person = new Person();
                person->read(&peopleFile);
                people.push_back(person);
                getline(peopleFile,text);
            }
        }
        else if(text == "Football Players File"){
            while(!peopleFile.eof()) {
                FootballPlayer *player = new FootballPlayer();
                player->read(&peopleFile);
                people.push_back((player));
                players.push_back(player);
                getline(peopleFile, text);
            }
        }
        else if(text == "Technicians File"){
            while(!peopleFile.eof()) {
                Technician *technician = new Technician();
                technician->read(&peopleFile);
                people.push_back((technician));
                technicians.push_back(technician);
                getline(peopleFile, text);
            }
        }

    }
    peopleFile.close();
    return true;
}

//HANDLE PLAYERS VECTOR
bool NationalTeam::addFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer) {
    insert_sorted(players, newFootballPlayer);
    return true;
}


bool NationalTeam::removeFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *playerToRemove) {
    int index = playerPosition(players, playerToRemove);
    if(index != -1){
        players.erase(players.begin()+index);
        return true;
    }
    else return false;
}


bool NationalTeam::modifyFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer) {
    int index = playerPosition(players, newFootballPlayer);
    if(index !=-1){
        players[index]->setSalary(newFootballPlayer->getSalary());
        players[index]->setBirthday(newFootballPlayer->getBirthday());
        players[index]->setName(newFootballPlayer->getName());
        players[index]->setClub(newFootballPlayer->getClub());
        players[index]->setHeight(newFootballPlayer->getHeight());
        players[index]->setInjury(newFootballPlayer->isInjury());
        players[index]->setPassValue(newFootballPlayer->getPassValue());
        players[index]->setPosition(newFootballPlayer->getPosition());
        players[index]->setWeight(newFootballPlayer->getWeight());
        return true;
    }
    return false;
}

int NationalTeam::playerPosition(vector<FootballPlayer*> &people, FootballPlayer *player){
    int index = BinarySearch(people, player);
    return index;
}

//HANDLE COSTS
//player costs
float NationalTeam::playerCostCalculator(Date d1, Date d2, int playerID){

    //guardar valor do pass
    //pesquisar no vetor de convocatorias
    //pesquisar no vetor de playerCallUp
    return 0.0;
}