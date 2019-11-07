#include <iostream>
#include "Person.h"
#include "FootballPlayer.h"
#include "Date.h"
#include "NationalTeam.h"
#include "Utilities.h"
using namespace std;


void testPerson(){

    vector<Person*> people;
    vector<Person*> people1;
    Date date(1,1,3000);

    Date birthdayDate(1,2,2018);
    Person *person1 = new Person("John Wick",birthdayDate);
    Person *person2 = new Person("Terry Wick",birthdayDate);
    Person *footballPlayer = new FootballPlayer("name", date,"position", "club",50.0, 20.0, 5.0,false);
    Person *person3 = new Person("Tiago Wick",birthdayDate);
    Person *person4 = new Person("Richard Wick",birthdayDate);
    Person *person5 = new Person("Bob Wick",birthdayDate);
    Person *person6 = new Person("John Wick",birthdayDate);
    Person *person7 = new Person("Bob Wick",birthdayDate);



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

    FootballPlayer *player1 = new FootballPlayer("name", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player2 = new FootballPlayer("John", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player3 = new FootballPlayer("Ramalho", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player4 = new FootballPlayer("Diogo", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player5 = new FootballPlayer("Tiago", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player6 = new FootballPlayer("Terry", date,"position", "club",50.0, 20.0, 5.0,false);
    FootballPlayer *player7 = new FootballPlayer("Zas", date,"position", "club",50.0, 20.0, 5.0,false);

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

void testNationalTeam(){
    NationalTeam team = NationalTeam("..\\FootballPlayers.txt");
    for (int i = 0; i < team.players.size() ; i++) {
        team.players[i]->print();
    }

}

int main() {

    //testPerson();
    //testPlayers();
    testNationalTeam();


    system("Pause");


}