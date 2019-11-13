#include <iostream>
#include <fcntl.h>
#include "NationalTeam.h"
#include "Utilities.h"

#include <windows.h>
#include <cstdio>
#include "Test.h"
using namespace std;

void runTeamManager(){

    NationalTeam team;
    team.readNationalTeam("NationalTeam.txt");
    team.runMenu();
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    runTeamManager();

    system("Pause");

    return 0;


}