//
// Created by tiago on 07/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_TEST_H
#define AEDA_TEAM_MANAGER_TEST_H
#include <iostream>
#include <sstream>
#include "People//Person.h"
#include "People//FootballPlayer.h"
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


    NationalTeam team;

    team.addPerson(people,person1);
    team.addPerson(people,person1);
    team.addPerson(people,person1);
    team.addPerson(people,person2);
    team.addPerson(people,person3);
    team.addPerson(people,person4);
    team.addPerson(people,person5);
    team.addPerson(people,person6);

    team.addPerson(people,footballPlayer);

    vector<Person*> p = Person::searchByName(people,"Bob Wick");
    cout << p[0]->getName() << p.size() << endl;


    for (int i = 0; i < people.size(); ++i) {
        cout << people[i]->getId() << endl;
    }

    //Verify Position Team
    int index = team.personPosition(people,footballPlayer);
    cout << index << endl;
    //cout << people[index]->type() << endl;
    //cout << people[6]->type() << endl;


    people[index]->print(cout);
    cout << people[index];
    //people[index+1]->print(cout);
    //people[index]->print(cout);




}

//Untested when changed to National Team

void testPlayers(){
    NationalTeam n;

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

    n.addFootballPlayer(players, player1);
    n.addFootballPlayer(players, player2);
    n.addFootballPlayer(players, player3);
    n.addFootballPlayer(players, player4);
    n.addFootballPlayer(players, player5);
    n.addFootballPlayer(players, player6);
    n.addFootballPlayer(players, player7);

    for (int i = 0; i < players.size() ; ++i) {
        players[i]->print(cout);

    }

    cout << n.playerPosition(players, player3) << endl;
    n.modifyFootballPlayer(players, player1, player3);
    cout << player3->getName() << endl;
    n.removeFootballPlayer(players, player3);
    cout << n.playerPosition(players, player3) << endl;


}

void testNationalTeam(){
    NationalTeam team = NationalTeam();
    team.readPeople("FootballPlayers.txt");
    team.readPeople("Person.txt");
    for (int i = 0; i < team.people.size() ; i++) {
        team.people[i]->print(cout);
    }

}

void testExceptions(){

    //Invalid Date
    /*try { Date date = Date(32,1,2000);}
    catch (InvalidDate &a){cout << a.getMessage();
        throw;
    }*/



    vector<Person*> people;
    vector<Person*> people1;
    Date date(1,1,3000);

    Date birthdayDate(1,2,2018);
    Person *person1 = new Person("John Wick",birthdayDate,100);
    Person *person2 = new Person("Terry Wick",birthdayDate,100);
    Person *footballPlayer = new FootballPlayer("name", date,200,"position", "club",50.0, 20.0, 5.0,false);
    Person *person3 = new Person("Tiago Wick",birthdayDate,200);


    NationalTeam team;
    team.addPerson(people,person1);
    team.addPerson(people,person2);
    team.addPerson(people,footballPlayer);

    //Remove Element that doesnt exist
    team.removePerson(people,person1);
    team.removePerson(people,person1);



}

#endif //AEDA_TEAM_MANAGER_TEST_H
