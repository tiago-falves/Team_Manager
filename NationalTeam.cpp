//
// Created by tiago on 06/11/2019.
//

#include "NationalTeam.h"
#include "Date.h"
#include <algorithm>
#include <fstream>
using namespace std;


NationalTeam::NationalTeam(string fileName) {
    readTeam(fileName);
}

bool NationalTeam::readTeam(string fileName) {
    string text;
    ifstream playersFile;
    int line= 0;
    FootballPlayer *player = new FootballPlayer("",Date());
    Date birthday = Date();

    playersFile.open(fileName);
    if(playersFile.fail()){
        cout << "Error Opening";
        return false;
    }
    else
    {
        while (getline(playersFile, text))
        {
            /*string position;
            string club;
            float weight;
            float height;
            float pass_value;
            bool injury;
            vector<int> temporary;*/
            switch (line)
            {
                case 0:
                    player->setId(stoi(text));
                    break;
                case 1:
                    player->setName(text);
                    break;
                case 2:
                    player->setBirthday(birthday.dateTextConverter(text));
                    break;
                case 3:
                    player->setSalary(stof(text));
                    break;
                case 4:
                    player->setPosition(text);
                    break;
                case 5:
                    player->setClub(text);
                    break;
                case 6:
                    player->setWeight(stof(text));
                    break;
                case 7:
                    player->setHeight(stof(text));
                    break;
                case 8:
                    player->setPassValue(stof(text));
                    break;
                case 9:
                    bool isInjured;
                    if(text == "Healthy") isInjured= false;
                    if(text == "Injured") isInjured= true;
                    player->setInjury(isInjured);
                    break;
                case 10:
                    line = -1;
                    players.push_back(player);
                    people.push_back(player);
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
