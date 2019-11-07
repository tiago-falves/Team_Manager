//
// Created by tiago on 07/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_TEST_H
#define AEDA_TEAM_MANAGER_TEST_H
#include <iostream>
#include "Person.h"
#include "FootballPlayer.h"
#include "Date.h"
#include "NationalTeam.h"
#include "Utilities.h"
using namespace std;

//CLASS JUST FOR TESTING


void testPerson(){

    vector<Person*> people;
    vector<Person*> people1;
    Date date(1,1,3000);

    Date birthdayDate(1,2,2018);
    Person *person1 = new Person("John Wick",birthdayDate,100);
    Person *person2 = new Person("Terry Wick",birthdayDate,100);
    Person *footballPlayer = new FootballPlayer("name", date,200,"position", "club",50.0, 20.0, 5.0,false);
    Person *person3 = new Person("Tiago Wick",birthdayDate,200);
    Person *person4 = new Person("Richard Wick",birthdayDate,300);
    Person *person5 = new Person("Bob Wick",birthdayDate,100);
    Person *person6 = new Person("John Wick",birthdayDate,300);
    Person *person7 = new Person("Bob Wick",birthdayDate,200);



    /*people1.push_back(person2);
    people1.push_back(person5);
    people1.push_back(person1);
    for (int j = 0; j < people1.size(); ++j) {
        cout << people1[j]->getName() << " ";
    }
    cout << endl;
    Person::sortByName(people1);
    for (int j = 0; j < people1.size(); ++j) {
        cout << people1[j]->getName() << " ";
    }
    cout << endl;*/


    person1->addPerson(people);
    person2->addPerson(people);
    person3->addPerson(people);
    person4->addPerson(people);
    person5->addPerson(people);
    person6->addPerson(people);
    person7->addPerson(people);

    footballPlayer->addPerson(people);

    vector<Person*> p = Person::searchByName(people,"Bob Wick");
    cout << p[0]->getName() << p.size() << endl;


    for (int i = 0; i < people.size(); ++i) {
        cout << people[i]->getId() << endl;
    }

    //Verify Position Team
    int index = footballPlayer->personPosition(people);
    cout << index << endl;
    //cout << people[index]->type() << endl;
    //cout << people[6]->type() << endl;
    people[index]->print();
    people[index+1]->print();
    people[index]->print();


    footballPlayer->removePerson(people);
    cout << footballPlayer->personPosition(people);


}



void testPlayers(){

    vector<FootballPlayer*> players;
    Date date(1,1,3000);
    Date birthdayDate(1,2,2018);

    FootballPlayer *player1 = new FootballPlayer("name", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player2 = new FootballPlayer("John", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player3 = new FootballPlayer("Ramalho", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player4 = new FootballPlayer("Diogo", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player5 = new FootballPlayer("Tiago", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player6 = new FootballPlayer("Terry", date,200,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player7 = new FootballPlayer("Zas", date,300,"position", "club",40.0, 30.0, 4.0,true);

    player1->addFootballPlayer(players);
    player2->addFootballPlayer(players);
    player3->addFootballPlayer(players);
    player4->addFootballPlayer(players);
    player5->addFootballPlayer(players);
    player6->addFootballPlayer(players);
    player7->addFootballPlayer(players);

    for (int i = 0; i < players.size() ; ++i) {
        players[i]->print();

    }

    cout << player3->playerPosition(players) << endl;
    player3->modifyFootballPlayer(players, player1);
    cout << player3->getName() << endl;
    player3->removeFootballPlayer(players);
    cout << player3->playerPosition(players) << endl;


}

void testNationalTeam(){
    NationalTeam team = NationalTeam();
    team.readPeople("FootballPlayers.txt");
    team.readPeople("Person.txt");
    for (int i = 0; i < team.people.size() ; i++) {
        team.people[i]->print();
    }

}

#endif //AEDA_TEAM_MANAGER_TEST_H
