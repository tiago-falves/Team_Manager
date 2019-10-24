#include <iostream>
#include "Person.h"
#include "Team.h"
#include "FootbalPlayer.h"
#include "Date.h"
#include "Utilities.h"
using namespace std;

int main() {

    vector<Person> people;

    Date birthdayDate(1,2,2018);
    Person person1(1,"John Wick",birthdayDate);
    Person person2(2,"Terry Wick",birthdayDate);
    Person person3(3,"Tiago Wick",birthdayDate);
    Person person4(4,"Richard Wick",birthdayDate);
    Person person5(5,"Bob Wick",birthdayDate);
    Person person6(6,"John Wick",birthdayDate);

    people.push_back(person2);
    people.push_back(person4);
    people.push_back(person1);
    people.push_back(person3);
    people.push_back(person5);


    Team team(people);

    //Verify if Team is ordered
    //for (int i = 0; i < team.people.size(); ++i) {cout << team.people[i].getId() << endl;}cout << endl;


    //Verify Position Team
    //cout << team.personPosition(person4);

    //Add person
    /*team.addPerson(person6);
    for (int i = 0; i < team.people.size(); ++i) { cout << team.people[i].getId() << endl;}*/

    //Remove Person
    //team.removePerson(person3);
    //for (int i = 0; i < team.people.size(); ++i) { cout << team.people[i].getId() << endl;}



    system("Pause");


}