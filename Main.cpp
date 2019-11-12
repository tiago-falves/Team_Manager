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
    team.readGames("Games.txt");
    team.runMenu();
}

int main() {

    //testPerson();
    //testExceptions();
    //testPlayers();
    //testNationalTeam();;
    SetConsoleOutputCP(CP_UTF8);

    //runAgency();


    //_setmode(_fileno(stdout), _O_U16TEXT);
    //std::wcout << L"Testing unicode -- English -- Ελληνικά -- Español." << std::endl;
    NationalTeam team;
    team.readPeople("Person.txt");
    team.readGames("Games.txt");
    team.runMenu();

    system("Pause");


}