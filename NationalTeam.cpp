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


//HANDLE COSTS
//player costs
float NationalTeam::playerCostCalculator(Date d1, Date d2, int playerID){

    //guardar valor do pass
    float pass = players[playerID-1]->getPassValue();

    //numero de dias que o jogador esteve em convocatória
    //pesquisar no vetor de convocatorias
    for (auto i = callUps.begin(); i < callUps.end(); i++){
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){
            if ((*j)->getPlayerID() == playerID){
                //found player in this call up
                
            }
        }
    }


    //pesquisar no vetor de playerCallUp


    return 0.0;
}

void NationalTeam::read(ifstream *file) {
    //read files
}

bool NationalTeam::savePeople(string filename) {
    ofstream content(filename);
    for (int i = 0; i < people.size(); ++i) {

    }
    return true;
}
