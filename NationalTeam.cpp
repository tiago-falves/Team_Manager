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
    string id;
    ifstream peopleFile;
    Date birthday = Date();
    peopleFile.open("..//Files//" + fileName);
    if(peopleFile.fail()){
        cerr << "Error Opening File";
        return false;
    }
    else{
        while(!peopleFile.eof()){
            getline(peopleFile, text);
            getline(peopleFile,id);
            if(text == "Football Player"){
                FootballPlayer *player = new FootballPlayer();
                player->read(&peopleFile);
                people.push_back((player));
                players.push_back(player);
                getline(peopleFile, text);
            }
            else if(text == "Technician"){
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

void NationalTeam::read(ifstream *file,string peopleFile) {
    readPeople(peopleFile);
}

bool NationalTeam::savePeople(string fileName) {
    ofstream content("..//Files//" + fileName);
    for (int i = 0; i < people.size(); ++i) {
        content << people[i];
        content << "::::::::::" << endl;
    }
    content.close();
    return true;
}

void NationalTeam::showEveryone(ostream &out) {
    for (int i = 0; i < people.size(); ++i) {
        people[i]->printNicely(out);
    }
}

void NationalTeam::showPerson(ostream &out, int id) {
    cout << searchByID(people,id);

}
void NationalTeam::sortByID(vector<Person *> &people) {
    sort(people.begin(),people.end());
}
Person* NationalTeam::searchByID(vector<Person *> &people,int id){
   return *lower_bound(people.begin(),people.end(),id,idComparable);
}



bool NationalTeam::nameComparable(const Person* person1, const Person* person2){
    return (person1->getName() < person2->getName());
}
bool NationalTeam::idComparable(const Person* person1, const int id){
    return (person1->getId() < id);
}
void NationalTeam::sortByName(vector<Person *> &people) {
    sort(people.begin(),people.end(),nameComparable);
}

vector<Person*> NationalTeam::searchByName(vector<Person *> people,string name) { //Devo ordenar duas vezes?? ou mais vale usar a sequencial?

    vector<Person*> peopleName;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i]->getName() == name){
            peopleName.push_back(people[i]);
        }
    }
    return peopleName;

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





