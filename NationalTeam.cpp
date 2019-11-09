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


bool NationalTeam::modifyFootballPlayer(vector<FootballPlayer*> &players, FootballPlayer *newFootballPlayer, FootballPlayer *previousFootbalPlayer) {
    int index = playerPosition(players, previousFootbalPlayer);
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

bool NationalTeam::addPerson(vector<Person*> &people, Person *person) {
    insert_sorted(people,person);
    return true;
}

bool NationalTeam::removePerson(vector<Person*> &people, Person *person) {
    int index;
    try {index = personPosition(people,person);}
    catch (out_of_range){
        cerr << "Tried to remove Person that doesn't exist: " << person->getName() << endl;
        return false;
    }
    people.erase(people.begin()+index);
    return true;

}

bool NationalTeam::modifyPerson(vector<Person*> &people, Person *person, Person *newPerson) {
    int index;
    try {index = personPosition(people,person);}
    catch (out_of_range){
        cerr << "Tried to modify Person that doesn't exist: " << person->getName() << endl;
        return false;
    }
    people[index]->setName(newPerson->getName());
    people[index]->setBirthday(newPerson->getBirthday());
    people[index]->setSalary(newPerson->getSalary());
    return true;
}


int NationalTeam::personPosition(vector<Person*> &people, Person *person){
    int index = BinarySearch(people,person);
    if(index==-1) throw out_of_range("Person not in vector");
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