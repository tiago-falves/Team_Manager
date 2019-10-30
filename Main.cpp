#include <iostream>
#include "Person.h"
#include "Team.h"
#include "FootballPlayer.h"
#include "Date.h"
#include "Utilities.h"
using namespace std;


void testPerson(){

    vector<Person*> people;
    Date date(1,1,3000);

    Date birthdayDate(1,2,2018);
    Person *person1 = new Person(1,"John Wick",birthdayDate);
    Person *footballPlayer = new FootballPlayer(10, "name", date,"position", "club",50.0, 20.0, 5.0,false);
    Person *person2 = new Person(2,"Terry Wick",birthdayDate);
    Person *person3 = new Person(3,"Tiago Wick",birthdayDate);
    Person *person4 = new Person(4,"Richard Wick",birthdayDate);
    Person *person5 = new Person(5,"Bob Wick",birthdayDate);
    Person *person6 = new Person(6,"John Wick",birthdayDate);

    person1->addPerson(people);
    person2->addPerson(people);
    person3->addPerson(people);
    person4->addPerson(people);
    person5->addPerson(people);
    person6->addPerson(people);
    footballPlayer->addPerson(people);



    //Verify Position Team
    int index = footballPlayer->personPosition(people);
    cout << index << endl;
    cout << people[index]->type() << endl;
    cout << people[6]->type() << endl;
    people[index]->print();
    footballPlayer->removePerson(people);
    cout << footballPlayer->personPosition(people);


}



void testPlayers(){

    vector<FootballPlayer*> players;
    Date date(1,1,3000);
    Date birthdayDate(1,2,2018);

    FootballPlayer *player1 = new FootballPlayer(1, "name", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player2 = new FootballPlayer(2, "John", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player3 = new FootballPlayer(3, "Ramalho", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player4 = new FootballPlayer(4, "Diogo", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player5 = new FootballPlayer(5, "Tiago", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player6 = new FootballPlayer(6, "Terry", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player7 = new FootballPlayer(7, "Zas", date,"position", "club",50.0, 20.0, 5.0,false);

    player1->addFootballPlayer(players);
    player2->addFootballPlayer(players);
    player3->addFootballPlayer(players);
    player4->addFootballPlayer(players);
    player5->addFootballPlayer(players);
    player6->addFootballPlayer(players);
    player7->addFootballPlayer(players);

    cout << player3->playerPosition(players) << endl;
    player3->modifyFootballPlayer(players, player1);
    cout << player3->getName() << endl;
    player3->removeFootballPlayer(players);
    cout << player3->playerPosition(players) << endl;


}

int main() {

    testPerson();
    //testPlayers();


    system("Pause");


}