#include <iostream>
#include "NationalTeam.h"
#include "Utilities.h"

#include "Test.h"
using namespace std;


int main() {

    //testPerson();
    //testExceptions();
    //testPlayers();
    //testNationalTeam();;



    NationalTeam team;
    team.readPeople("Person.txt");
    team.runMenu();




    system("Pause");


}