//
// Created by tiago on 06/11/2019.
//

#include "NationalTeam.h"
#include "Date.h"
#include <algorithm>
#include <fstream>
using namespace std;


NationalTeam::NationalTeam(string fileName) {
    //readTeam(fileName);
    readPeople("..//FootballPlayers.txt");
}

bool NationalTeam::readTeam(string fileName) {
    string text;
    ifstream playersFile;
    int line= 0;
    FootballPlayer *player = new FootballPlayer("",Date());
    Date birthday = Date();

    playersFile.open(fileName);
    if(playersFile.fail()){
        cout << "Error Opening File";
        return false;
    }
    else
    {
        while (getline(playersFile, text))
        {
            switch (line)
            {
                case 0:
                    player->setName(text);
                    break;
                case 1:
                    player->setBirthday(birthday.dateTextConverter(text));
                    break;
                case 2:
                    player->setSalary(stof(text));
                    break;
                case 3:
                    player->setPosition(text);
                    break;
                case 4:
                    player->setClub(text);
                    break;
                case 5:
                    player->setWeight(stof(text));
                    break;
                case 6:
                    player->setHeight(stof(text));
                    break;
                case 7:
                    player->setPassValue(stof(text));
                    break;
                case 8:
                    bool isInjured;
                    if(text == "Healthy") isInjured= false;
                    if(text == "Injured") isInjured= true;
                    player->setInjury(isInjured);
                    break;
                case 9:
                    line = -1;
                    players.push_back(player);
                    people.push_back(player);
                    player = new FootballPlayer("",Date());
                    break;
                default:
                    break;
            }
            line++;
        }
    }
    //clientsVector.push_back(client);
    playersFile.close();

    return true;
}

bool NationalTeam::readPeople(string fileName) {
    string text;
    ifstream peopleFile;
    Date birthday = Date();
    peopleFile.open(fileName);
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
                FootballPlayer *player = new FootballPlayer("", birthday);
                player->read(&peopleFile);
                people.push_back((player));
                players.push_back(player);
                getline(peopleFile, text);
            }
        }
        else if(text == "Technicians File"){
            while(!peopleFile.eof()) {
                Technician *technician = new Technician("", birthday);
                technician->read(&peopleFile);
                people.push_back((technician));
                technicians.push_back(technician);
                getline(peopleFile, text);
            }
        }

    }
    //clientsVector.push_back(client);
    peopleFile.close();
    return true;
}