#include <iostream>
#include <fcntl.h>
#include "NationalTeam.h"
#include "Utilities.h"

#include <windows.h>
#include <cstdio>
#include "Test.h"
using namespace std;



int main() {

    //testPerson();
    //testExceptions();
    //testPlayers();
    //testNationalTeam();;
    SetConsoleOutputCP(CP_UTF8);



    //_setmode(_fileno(stdout), _O_U16TEXT);
    //std::wcout << L"Testing unicode -- English -- Ελληνικά -- Español." << std::endl;
    NationalTeam team;
    team.readPeople("Person.txt");
    team.runMenu();




    system("Pause");


}