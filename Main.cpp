#include <iostream>
#include <fcntl.h>
#include "NationalTeam.h"
#include "Utilities.h"

#include <windows.h>
#include <cstdio>
#include "Test.h"
using namespace std;

void runAgency(){
    //Read Team File
    //File will contain the name of the other documents

    //Isto e so para testar
    NationalTeam team;
    team.setPeopleFile("Person.txt");
    team.readPeople(team.getPeopleFile());
    team.runMenu();
}

int main() {

    //testPerson();
    //testExceptions();
    //testPlayers();
    //testNationalTeam();;
    SetConsoleOutputCP(CP_UTF8);

    runAgency();





    system("Pause");


}