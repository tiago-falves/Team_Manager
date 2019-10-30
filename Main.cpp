#include <iostream>
#include "Person.h"
#include "Team.h"
#include "FootbalPlayer.h"
#include "Date.h"
#include "Utilities.h"
using namespace std;


void testPerson(){

    vector<Person> people;
    Date date(1,1,3000);

    Date birthdayDate(1,2,2018);
    Person person1(1,"John Wick",birthdayDate);
    Person person2(2,"Terry Wick",birthdayDate);
    Person person3(3,"Tiago Wick",birthdayDate);
    Person person4(4,"Richard Wick",birthdayDate);
    Person person5(5,"Bob Wick",birthdayDate);
    Person person6(6,"John Wick",birthdayDate);
    FootbalPlayer footbalPlayer(10, "name", date,"position", "club",50.0, 20.0, 5.0,false);

    person1.addPerson(people);
    person2.addPerson(people);
    person3.addPerson(people);
    person4.addPerson(people);
    person5.addPerson(people);
    person6.addPerson(people);
    footbalPlayer.addPerson(people);




    Team team(people);

    //Verify if Team is ordered
    //for (int i = 0; i < team.people.size(); ++i) {cout << team.people[i].getId() << endl;}cout << endl;


    //Verify Position Team
    //cout << footbalPlayer.personPosition(people);
    //footbalPlayer.removePerson(people);
    //cout << footbalPlayer.personPosition(people);


    //Add person
    //team.addPerson(person6);
    //for (int i = 0; i < team.people.size(); ++i) { cout << team.people[i].getId() << endl;}

    //Remove Person
    //team.removePerson(person3);
    //for (int i = 0; i < team.people.size(); ++i) { cout << team.people[i].getId() << endl;}


}

int main() {

    testPerson();


    system("Pause");


}