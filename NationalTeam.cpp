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