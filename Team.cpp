
#include <algorithm>
#include "Team.h"
#include "Utilities.h"
using namespace std;


//Constructor
Team::Team(vector<Person> &people) {
    this->people = people;
    insertionSort(this->people);
}

bool Team::addPerson(const Person &person) {
    insert_sorted(people,person);

    return true;
}
bool Team::removePerson(const Person &person) {
    int index = personPosition(person);
    if(index != -1){
        people.erase(people.begin()+index);
        return true;
    }
    else return false;
}



int Team::personPosition(const Person &person){
    int index = BinarySearch(people,person);
    return index;
}
