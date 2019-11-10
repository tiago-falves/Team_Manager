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
        people[i]->printToFile(content);
        content << "::::::::::" << endl;
    }
    content.close();
    return true;
}

void NationalTeam::showEveryone(ostream &out) {
    for (int i = 0; i < people.size(); ++i) {
        out << people[i];
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

    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass = players[playerID-1]->getPassValue() * 0.01;

    //variable that sums the costs associated with this player
    float val = 0;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++){

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){

            if ((*j)->getPlayerID() == playerID){
                //found player in this call up
                //checking number of days player was in call up between the given days
                if (d1 <= (*j)->getBegDate() && d2 >= (*j)->getEndDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()) {
                        val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * (*i)->getDailyCost();
                }
                else if (d1 <= (*j)->getBegDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else  val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays())  * (*i)->getDailyCost();
                }
                else if (d2 >= (*j)->getEndDate()) {
                    if (players[(*j)->getPlayerID()]->isInjury()) {
                        val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays())  * (*i)->getDailyCost();
                }
                else if (d1 >= (*j)->getBegDate() && d2 <= (*j)->getEndDate()){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (d2.dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                    }
                    else val += pass * (d2.dateToDays() - d1.dateToDays()) * (*i)->getDailyCost();
                }
            }
        }
    }
    return val;
}

float NationalTeam::teamCostCalculator(Date d1, Date d2) {
    float val = 0;
    float pass;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++){

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){

            pass = players[(*j)->getPlayerID()]->getPassValue() * 0.01;

            //checking number of days player was in call up between the given days
            if (d1 <= (*j)->getBegDate() && d2 >= (*j)->getEndDate()){
                if (players[(*j)->getPlayerID()]->isInjury()) {
                    val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * ((*j)->getEndDate().dateToDays() - (*j)->getBegDate().dateToDays()) * (*i)->getDailyCost();
            }
            else if (d1 <= (*j)->getBegDate()){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else  val += pass * (d2.dateToDays() - (*j)->getBegDate().dateToDays())  * (*i)->getDailyCost();
            }
            else if (d2 >= (*j)->getEndDate()) {
                if (players[(*j)->getPlayerID()]->isInjury()) {
                    val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * ((*j)->getEndDate().dateToDays() - d1.dateToDays())  * (*i)->getDailyCost();
            }
            else if (d1 >= (*j)->getBegDate() && d2 <= (*j)->getEndDate()){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (d2.dateToDays() - d1.dateToDays()) * 3 * (*i)->getDailyCost();
                }
                else val += pass * (d2.dateToDays() - d1.dateToDays()) * (*i)->getDailyCost();
            }
        }
    }
    return val;
}

float NationalTeam::playerCostCalculatorMonth(int monthNumber, int yearNumber, int playerID) {
    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass = players[playerID-1]->getPassValue() * 0.01;

    //variable that sums the costs associated with this player
    float val = 0;

    //Date variables used in loops
    Date beg, end;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++) {

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++) {

            if ((*j)->getPlayerID() == playerID) {
                //found player in this call up
                beg = (*j)->getBegDate();
                end = (*j)->getEndDate();

                if (beg.getMonth() == monthNumber && end.getMonth() == monthNumber && beg.getYear() == yearNumber && end.getYear() == yearNumber){
                    if (players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost();
                }
                else if (beg.getMonth() == monthNumber && end.getYear() == yearNumber){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost();
                }
                else if (end.getMonth() == monthNumber && end.getYear() == yearNumber){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (end.getDay()) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (end.getDay()) * (*i)->getDailyCost();
                }
                else if (((beg.getMonth() <= monthNumber && beg.getYear() == yearNumber) || (beg.getYear() == yearNumber)) && ((end.getMonth() >= monthNumber && end.getYear() == yearNumber) || (end.getYear() == yearNumber))){
                    if(players[(*j)->getPlayerID()]->isInjury()){
                        val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost() *3;
                    }
                    else val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost();
                }
                else{
                    //lançar exceção de jogador não estar em nenhuma convocatória na data fornecida
                }
            }
        }
    }
}
float NationalTeam::teamCostCalculatorMonth(int monthNumber, int yearNumber) {
    //save pass value - wre assumed 1% of the pass value as current player's value has astronomical values
    float pass;

    //variable that sums the costs associated with this player
    float val = 0;

    //Date variables used in loops
    Date beg, end;

    //iterates over different call ups
    for (auto i = callUps.begin(); i < callUps.end(); i++) {

        //iterates over the players that were in that call up
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++) {

            //found player in this call up
            beg = (*j)->getBegDate();
            end = (*j)->getEndDate();
            pass = players[(*j)->getPlayerID()]->getPassValue() * 0.01;

            if (beg.getMonth() == monthNumber && end.getMonth() == monthNumber && beg.getYear() == yearNumber && end.getYear() == yearNumber){
                if (players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (end.dateToDays() - beg.dateToDays()) * (*i)->getDailyCost();
            }
            else if (beg.getMonth() == monthNumber && end.getYear() == yearNumber){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (beg.daysInMonth(monthNumber, yearNumber) - beg.getDay()) * (*i)->getDailyCost();
            }
            else if (end.getMonth() == monthNumber && end.getYear() == yearNumber){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (end.getDay()) * (*i)->getDailyCost() *3;
                }
                else val += pass * (end.getDay()) * (*i)->getDailyCost();
            }
            else if (((beg.getMonth() <= monthNumber && beg.getYear() == yearNumber) || (beg.getYear() == yearNumber)) && ((end.getMonth() >= monthNumber && end.getYear() == yearNumber) || (end.getYear() == yearNumber))){
                if(players[(*j)->getPlayerID()]->isInjury()){
                    val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost() *3;
                }
                else val += pass * (beg.daysInMonth(monthNumber, yearNumber)) * (*i)->getDailyCost();
            }
            else{
                //lançar exceção de jogador não estar em nenhuma convocatória na data fornecida
            }
        }
    }
}





