//
// Created by tiago on 08/11/2019.
//


#include "../NationalTeam.h"

void NationalTeam::runGameMenu() {
    int option;

    while (true) {
        cout << "Welcome to the Game Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "See information from all games.                                    [1]" << endl;
        cout << "See information from a specific game.                              [2]" << endl;
        cout << "See information from a specific game for a specific player.        [3]" << endl;
        cout << "Create new game.                                                   [4]" << endl;
        cout << "Remove Game.                                                       [5]" << endl;
        cout << "Modify Game.                                                       [6]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        while (cin.fail() || option < 0 || option > 6) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> option;
        }

        cin.clear();
        cin.ignore(100, '\n');

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { showAllGames(cout); }
        if (option == 2) { showSpecificGame(cout); }
        if (option == 3) { showSpecificStats(cout); }
        if (option == 4) { addGameCallUpMenu(createGameOption(cout)); }
        if (option == 5) { removeGameCallUpMenu(); }
        if (option == 6) { showModifyGameOptions(cout); }

        break;
    }
}

void NationalTeam::tableHeaderAllGames(ostream &out) {
    out << endl << endl << endl;
    out << "Games:\n";
    out << setw(83) << setfill('-') << "-" <<  endl;
    out <<  left << setw(4)  << setfill(' ') << "id" << "│  ";
    out <<  left << setw(20) << setfill(' ') << "City"  << "│ ";
    out <<  left << setw(11) << setfill(' ') <<  "Country"<< "│ ";
    out <<  left << setw(18)  << setfill(' ') << "Stadium" << "│ ";
    out <<  left << setw(20)  << setfill(' ') << "Game Title" << "│ ";
    out << endl << setw(82) << setfill('-') << "-" << "│" <<  endl;

}

void NationalTeam::tableFooterAllGames(ostream &out) {
    out << setw(83) << setfill('-') << "-" << endl;
}

void NationalTeam::tableHeaderStatistics(ostream &out) {
    out << endl << endl << endl;
    out << "Player Statistics:\n";
    out << setw(110) << setfill('-') << "-" <<  endl;
    out <<  left << setw(11)  << setfill(' ') << "Player ID" << "│ ";
    out <<  left << setw(15) << setfill(' ') << "Goals"  << "│ ";
    out <<  left << setw(16) << setfill(' ') <<  "Minutes Played"<< "│ ";
    out <<  left << setw(12)  << setfill(' ') << "Kilometers" << "│ ";
    out <<  left << setw(18)  << setfill(' ') << "Number of Passes" << "│ ";
    out <<  left << setw(14)  << setfill(' ') << "Yellow Cards" << "│ ";
    out <<  left << setw(11)  << setfill(' ') << "Red Cards" << "│ ";
    out <<  endl << setw(109) << setfill('-') << "-" << "│" <<  endl;
}

void NationalTeam::tableHeaderEnemyTeam(ostream &out) {
    out << endl << endl << endl;
    out << "Enemy Team:\n";
    out << setw(15) << setfill('-') << "-" <<  endl;
    out <<  left << setw(15) << setfill(' ') << "Name"  << "│ ";
    out <<  endl << setw(15) << setfill('-') << "-" << "│" <<  endl;
}

void NationalTeam::tableHeaderReferee(ostream &out) {
    out << endl << endl << endl;
    out << "Referees:\n";
    out << setw(15) << setfill('-') << "-" <<  endl;
    out <<  left << setw(15) << setfill(' ') << "Name"  << "│ ";
    out <<  endl << setw(15) << setfill('-') << "-" << "│" <<  endl;
}

void NationalTeam::tableFooterStatistics(ostream &out){
    out << setw(110) << setfill('-') << "-" << endl;
}

void NationalTeam::tableFooterEnemyTeamReferee(ostream &out) {
    out << setw(15) << setfill('-') << "-" << endl;
}

void NationalTeam::showAllGames(ostream &out) {

    tableHeaderAllGames(out);
    for(Game* g : games){
        g->print(out);
    }

    tableFooterAllGames(out);

}

void NationalTeam::showSpecificGame(ostream &out) {
    out << "Which game do you which to see?\n";
    int id = askForId();

    tableHeaderAllGames(out);

    games[id - 1]->print(out);

    tableFooterAllGames(out);

    tableHeaderStatistics(out);

    for(PlayerGameStatistics stat : games[id - 1]->getPlayerStatistics()){
        stat.print(out);
    }

    tableFooterStatistics(out);

    tableHeaderPlayer(out);

    for(FootballPlayer * p : games[id -1]->getNationalPlayers()){
        p->print(out);
    }

    tableFooterPlayer(out);

    tableHeaderEnemyTeam(out);

    for(string s : games[id - 1]->getEnemyPlayers()){
        out <<  left << setw(15) << setfill(' ') << s  << "│\n";
    }

    tableFooterEnemyTeamReferee(out);

    tableHeaderReferee(out);

    for(string s : games[id - 1]->getReferees()){
        out <<  left << setw(15) << setfill(' ') << s  << "│\n";
    }

    tableFooterEnemyTeamReferee(out);

}

void NationalTeam::showSpecificStats(ostream &out) {
    out << "Which game do you which to see?\n";
    int gameID = askForId();
    out << "Which player do you which to see?\n";
    int playerID = askForId();

    tableHeaderAllGames(out);

    games[gameID - 1]->print(out);

    tableFooterAllGames(out);

    tableHeaderStatistics(out);

    for(PlayerGameStatistics stat : games[gameID - 1]->getPlayerStatistics()) {
        if (stat.getPlayerID() == playerID) {
            stat.print(out);
            break;
        }
    }
    tableFooterStatistics(out);
}

int NationalTeam::createGameOption(ostream &out) {
    Game *newGame = new Game();

    newGame->setCity(askForString("City"));
    newGame->setCountry(askForString("Country"));
    newGame->setStadium(askForString("Stadium"));
    newGame->setGameTitle(askForString("Game Title"));
    askForPlayers(out, newGame);

    menuSeparator();
    askForStringVector(out, "EnemyPlayers", newGame);

    menuSeparator();
    askForStringVector(out, "Referee", newGame);

    games.push_back(newGame);

    out << "Game created with success.\n";

    return newGame->getID();
}

int NationalTeam::removeGameOption(ostream &out, const int& idc) {
    out << "What Game do you wish to remove?\n";
    int gameID = askForId();

    //GETS CALL UP AND REMOVES GAME FROM IR
    try {
        getCallUpWithID(idc)->removeGame(getGameWithID(gameID));
    }
    catch(GameDontExistsCallUp){
        cout << "The game does not exist in call up!" << endl;
        menuSeparator();
        return 0;
    }

    //REMOVES GAME FROM LIST OF GAMES
    if(removeGame(games, gameID)){
        out << "Game removed with success.\n";
        return gameID;
    }

    out << "Unable to remove the game.\n";
    return 0;
}

const string &NationalTeam::getGameFile() const {
    return gameFile;
}

void NationalTeam::setGameFile(const string &gameFile) {
    NationalTeam::gameFile = gameFile;
}

void NationalTeam::askForPlayers(ostream &out, Game * game) {
    int playerID;
    PlayerGameStatistics stats;
    int index;
    for(int i = 0; i < 11; i++){
        out << "Insert the ID of the player number " << i+1 << " to add.\n";
        playerID = askForValidId(players);
        index = searchByID(players, playerID);
        game->addNationalPlayer(players[index], askForPlayerStatistics(out, playerID));

        menuSeparator();
    }
}

void NationalTeam::askForStringVector(ostream &out, string what, Game *game) {
    int counter = 0;

    if(what == "EnemyPlayers") {
        for (int i = 0; i < 11; i++) {
            counter++;
            game->addEnemyPlayer(askForString("Enemy Player " + to_string(counter)));
        }
    }
    else {
        counter = 0;
        for(int i=0; i < 5; i++){
            game->addReferee(askForString("Referee " + to_string(counter)));
        }
    }

}

PlayerGameStatistics NationalTeam::askForPlayerStatistics(ostream &out, int playerID) {
    PlayerGameStatistics stats;

    stats.setPlayerID(playerID);
    stats.setNumberOfGoals(askForInt("Number of Goals"));
    stats.setMinutesPlayed(askForInt("Minutes Played"));
    stats.setKilometers(askForInt("Kilometers"));
    stats.setNumberOfPasses(askForInt("Passes"));
    stats.setNumberOfYellowCards(askForInt("Yellow Cards"));
    stats.setNumberOfRedCards(askForInt("Red Cards"));

    return stats;
}

void NationalTeam::showModifyGameOptions(ostream &out) {
    int option;

    while(true) {
        cout << "Welcome to the Game Menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "City                                                               [1] " << endl;
        cout << "Country                                                            [2]" << endl;
        cout << "Stadium                                                            [3]" << endl;
        cout << "Player Statistics                                                  [4]" << endl;
        cout << "National Players                                                   [5]" << endl;
        cout << "Enemy Players                                                      [6]" << endl;
        cout << "Referees                                                           [7]" << endl;
        cout << "Everything                                                         [8]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        while (cin.fail() || option < 0 || option > 8) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> option;
        }

        cin.clear();
        cin.ignore(10000, '\n');

        menuSeparator();

        if (option == 0) { break; }
        else { modifyGameOption(cout, option); }

        break;
    }
}

void NationalTeam::modifyGameOption(ostream &out, int option) {
    out << "What Game do you wish to modify?\n";
    int gameID = askForId();

    cin.clear();

    int index = searchGameByID(games, gameID);


    if(option == 1){
        games[index]->setCity(askForString("City"));
    }
    else if(option == 2){
        games[index]->setCountry(askForString("Country"));
    }
    else if(option == 3){
        games[index]->setStadium(askForString("Stadium"));
    }
    else if(option == 4){
        games[index]->setGameTitle(askForString("Game Title"));
    }
    else if(option == 5){

        tableHeaderPlayer(out);

        for(FootballPlayer * p : games[index]->getNationalPlayers()){
            p->print(out);
        }

        tableFooterPlayer(out);

        modifyPlayerOption();

    }
    else if(option == 6){
        tableHeaderEnemyTeam(out);

        for(string s : games[index]->getEnemyPlayers()){
            out <<  left << setw(15) << setfill(' ') << s  << "│\n";
        }

        tableFooterEnemyTeamReferee(out);

        askForStringVector(out, "EnemyPlayers", games[index]);

    }
    else if(option == 7){
        tableHeaderReferee(out);

        for(string s : games[index]->getReferees()){
            out <<  left << setw(15) << setfill(' ') << s  << "│\n";
        }

        tableFooterEnemyTeamReferee(out);

        askForStringVector(out, "Referee", games[index]);
    }
    else if(option == 8){
        modifyGameOption(cout, 1);
        modifyGameOption(cout, 2);
        modifyGameOption(cout, 3);
        modifyGameOption(cout, 4);
        modifyGameOption(cout, 5);
        modifyGameOption(cout, 6);
        modifyGameOption(cout, 7);
    }


}