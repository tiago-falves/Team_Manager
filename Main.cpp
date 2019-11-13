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
    team.readGameStatiscs("Statistics.txt");

    cout << team.getGames()[0]->getPlayerStatistics().size() << endl;
    cout << team.getGames()[1]->getPlayerStatistics().size() << endl;

    cout << endl << endl;

    cout << "START" << endl;

    vector<Game*> games = team.getGames();

    for (auto i = games.begin(); i < games.end(); i++){
        cout << "GOT IN " << endl;
        for (auto j = (*i)->getPlayerStatistics().begin(); j < (*i)->getPlayerStatistics().end(); j++){
            cout << "playerID: " << j->getPlayerID() << endl;
            cout << "Goals: " << j->getNumberOfGoals() << endl;
            cout << "Minutes: " << j->getMinutesPlayed() << endl;
            cout << "Kilometers: " << j->getKilometers() << endl;
            cout << "Passes: " << j->getNumberOfPasses() << endl;
            cout << "Yellows: " << j->getNumberOfYellowCards() << endl;
            cout << "Reds: " << j->getNumberOfRedCards() << endl;
            cout << "---------" << endl;
        }
        cout << "::::::::::" << endl;
    }
    cout << "END" << endl;

    team.readCallUp("CallUp.txt");
    team.runMenu();

    system("Pause");


}