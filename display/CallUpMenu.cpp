//
// Created by tiago on 08/11/2019.
//


#include "../NationalTeam.h"
#include <algorithm>

void NationalTeam::runCallUpMenu() {
    int option;

    while(true) {
        cout << "Welcome to the Call Up menu! Please choose what you want to do: ";
        cout << endl << endl;
        cout << "Go back.                                                           [0]" << endl;
        cout << "See information from all Call Ups.                                 [1]" << endl;
        cout << "See information from a specific call up.                           [2]" << endl;
        cout << "Create new Call up.                                                [3]" << endl;
        cout << "Remove Call Up.                                                    [4]" << endl;
        cout << "Modify Call Up.                                                    [5]" << endl;
        cout << "Add Game to Call Up.                                               [6]" << endl;
        cout << "Remove Game from Call Up.                                          [7]" << endl;
        cout << "Insert the number correspondent to your option: ";
        cin >> option;

        validOption(option, 7);

        menuSeparator();

        if (option == 0) { break; }
        if (option == 1) { allCallUpMenu(); break;}
        if (option == 2) { callUpMenu(); }
        if (option == 3) { createCallUpMenu(); }
        if (option == 4) { removeCallUpMenu(); }
        if (option == 5) { modifyCallMenu(); }
        if (option == 6) { addGameCallUpMenu(); }
        if (option == 7) { removeGameCallUpMenu(); }

    }
}

void NationalTeam::headerCallUp(ostream &out) {
    out << endl << endl << endl;
    out << setw(55) << setfill('-') << "-" <<  endl;
    out <<  left << setw(5)  << setfill(' ') << "ID" << "│  ";
    out <<  left << setw(8)  << setfill(' ') << "Begin date" << "│  ";
    out <<  left << setw(10) << setfill(' ') << "End date"  << "│ ";
    out <<  left << setw(20) << setfill(' ') <<  "List of games"<< "│ ";
    out << endl;
}

void NationalTeam::allCallUpMenu() {
    headerCallUp(cout);
    for (auto i = callUps.begin(); i != callUps.end(); i++) {
        (*i)->showCallUp(cout);
    }
}

void NationalTeam::callUpMenu() {
    menuSeparator();
    int option;

    while (true){
        cout << "Insert the ID of the call up you want to see: ";
        cin >> option;

        if (cin.fail()){
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try{
            searchCallUpByID(option);
        }
        catch(InexistentId){
            cout << "There are no call ups with such id (" << option << ") !" << endl;
            menuSeparator();
            break;
        }

        headerCallUp(cout);
        for (auto i = callUps.begin(); i != callUps.end(); i++) {
            if (option == (*i)->getId()) (*i)->showCallUp(cout);
        }

        menuSeparator();
        break;
    }
}

void NationalTeam::createCallUpMenu() {
    menuSeparator();
    int id;
    float cost;

    string indexes; vector<int> vec_indexes;
    vector<Game*> call_games;

    string date;
    Date begDate, endDate;

    Date begPlayerDate, endPlayerDate;
    vector<CallUpPlayerStatistics*> stats;

    while (true) {
        //DEFAULT ID
        id = callUps.back()->getId() + 1;

        //GET DAILY COST
        cout << "Accomodation daily cost: ";
        cin >> cost;

        while (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> cost;
        }

        //GET INDEX OF GAMES
        cout << "Insert a list of the game's indexes separated by commas: ";
        cin >> indexes;

        try {
            vec_indexes = separateCharacterInt(indexes, ',');
            insertionSort(vec_indexes);
        }
        catch (exception) {
            cout << "The inserted list was not written properly!" << endl;
            menuSeparator();
            break;
        }

        //ITERATE INDEXES
        bool got_exception = false;
        for (auto i = vec_indexes.begin(); i != vec_indexes.end(); i++) {
            try {
                call_games.push_back(getGameWithID(*i));
            }
            catch (InexistentId) {
                got_exception = true;
                cout << "The id: " << *i << " does not correspond to an existant game!" << endl;
            }
        }
        if (got_exception) {
            menuSeparator();
            break;
        }

        //GET BEGINNING DATE
        cout << "Insert beggining date (DD/MM/YYYY): ";
        cin >> date;

        if (begDate.validDateText(date)) {
            begDate = begDate.dateTextConverter(date);
        } else {
            cout << "The inserted date was not written properly!";
            menuSeparator();
            break;
        }

        //GET END DATE
        cout << "Insert ending date (DD/MM/YYYY): ";
        cin >> date;

        if (endDate.validDateText(date)) {
            endDate = endDate.dateTextConverter(date);
        } else {
            cout << "The inserted date was not written properly!";
            menuSeparator();
            break;
        }

        //CHECK IF ENDING IS AFTER BEGINNING
        if (!endDate.isAfter(begDate)) {
            cout << "The ending date cannot come before the beginning date!";
            menuSeparator();
            break;
        }

        //GET PLAYER DATES IN CALL UP
        bool error = false;

        for (auto i = call_games.begin(); i != call_games.end(); i++) {
            for (auto j = (*i)->getNationalPlayers().begin(); j != (*i)->getNationalPlayers().end(); j++) {
                //GET BEGINNING DATE

                cout << "Insert player's with id " << (*j)->getId() << " beggining date (DD/MM/YYYY): ";
                cin >> date;

                if (begPlayerDate.validDateText(date)) {
                    begPlayerDate = begPlayerDate.dateTextConverter(date);
                }
                else {
                    cout << "The inserted date was not written properly!";
                    menuSeparator();
                    error = true;
                    break;
                }
                //CHECK IF BEGGING PLAYER DATE IS AFTER OR EQUAL TO CALL UP'S


                if (begPlayerDate.dateToDays() < begDate.dateToDays()) {
                    cout << "Player date is not included in call up time!";
                    menuSeparator();
                    error = true;
                    break;
                }

                //GET END DATE
                cout << "Insert player's with id " << (*j)->getId() << " ending date (DD/MM/YYYY): ";
                cin >> date;

                if (endPlayerDate.validDateText(date)) {
                    endPlayerDate = endPlayerDate.dateTextConverter(date);
                }
                else {
                    cout << "The inserted date was not written properly!";
                    menuSeparator();
                    error = true;
                    break;
                }

                //CHECK IF ENDING IS AFTER BEGINNING
                if (!endPlayerDate.isAfter(begPlayerDate)) {
                    cout << "The ending date cannot come before the beginning date!";
                    menuSeparator();
                    error = true;
                    break;
                }

                //CHECK IF ENDING PLAYER DATE IS BEFORE OR EQUAL TO CALL UP'S
                if (endPlayerDate.dateToDays() > endDate.dateToDays()) {
                    cout << "Player date is not included in call up time!";
                    menuSeparator();
                    error = true;
                    break;
                }

                stats.push_back(new CallUpPlayerStatistics((*j)->getId(), begPlayerDate, endPlayerDate));
                cout << "STATS BUILLD AND PUSHED" << endl;

            }
            if (error) break;
        }
        menuSeparator();
        break;
    }

    //ADD NEW CALL UP DATA BASE
    callUps.push_back(new CallUp(id, cost, call_games, stats, begDate, endDate));
}

void NationalTeam::removeCallUpMenu() {
    menuSeparator();
    int option;

    while (true) {
        cout << "Insert the ID of the call up you want to remove: ";
        cin >> option;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try {
            searchCallUpByID(option);
        }
        catch (InexistentId) {
            cout << "There are no call ups with such id (" << option << ") !" << endl;
            menuSeparator();
            break;
        }

        //ERASE ELEMENT
        deleteCallUp(option);

        menuSeparator();
        break;

    }
}

void NationalTeam::modifyCallMenu() {
    menuSeparator();

    int option, id;

    while (true) {
        cout << "Insert the ID of the call up you want to modify: ";
        cin >> id;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try {
            searchCallUpByID(id);
        }
        catch (InexistentId) {
            cout << "There are no call ups with such id (" << id << ") !" << endl;
            menuSeparator();
            break;
        }

        cout << "Go back.                                                           [0]" << endl;
        cout << "Change daily costs.                                                [1]" << endl;
        cout << "Reduce beggining date.                                             [2]" << endl;
        cout << "Extend end date.                                                   [3]" << endl;

        validOption(option, 3);

        menuSeparator();

        if (option == 0) break;
        if (option == 1){
            changeDailyCosts(id);
            menuSeparator();
            break;
        }
        if (option == 2){
            reduceBegDate(id);
            menuSeparator();
            break;
        }
        if (option == 3) {
            extendEndDate(id);
            menuSeparator();
            break;
        }
    }
}

void NationalTeam::changeDailyCosts(int id) {
    float cost;
    cout << "New accomodation daily cost: ";
    cin >> cost;

    while (cin.fail()) {
        cout << "Invalid option, please insert the option again: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cost;
    }

    getCallUpWithID(id)->setId(id);
}

void NationalTeam::reduceBegDate(int id) {
    string date;
    Date begDate;

    while (true) {

        cout << "Insert the new beggining date (DD/MM/YYYY): ";
        cin >> date;

        if (begDate.validDateText(date)) {
            begDate = begDate.dateTextConverter(date);
        }
        else {
            cout << "The inserted date was not written properly!";
            menuSeparator();
            break;
        }

        if (begDate.dateToDays() > getCallUpWithID(id)->getBegDate().dateToDays()){
            cout << "You can only reduce the date value!" << endl;
            menuSeparator();
            break;
        }

        getCallUpWithID(id)->setBegDate(begDate);

        break;
    }
}

void NationalTeam::extendEndDate(int id){
    string date;
    Date endDate;

    while (true) {

        cout << "Insert the new beggining date (DD/MM/YYYY): ";
        cin >> date;

        if (endDate.validDateText(date)) {
            endDate = endDate.dateTextConverter(date);
        }
        else {
            cout << "The inserted date was not written properly!";
            menuSeparator();
            break;
        }

        if (endDate.dateToDays() < getCallUpWithID(id)->getEndDate().dateToDays()){
            cout << "You can only extend the date value!" << endl;
            menuSeparator();
            break;
        }

        getCallUpWithID(id)->setEndDate(endDate);

        menuSeparator();
        break;
    }
}

void NationalTeam::addGameCallUpMenu() {
    menuSeparator();

    int idc, idg;
    Game* g;

    while (true) {
        cout << "Insert the ID of the call up you want to add the game to: ";
        cin >> idc;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try {
            searchCallUpByID(idc);
        }
        catch (InexistentId) {
            cout << "There are no call ups with such id (" << idc << ") !" << endl;
            menuSeparator();
            break;
        }


        cout << "Insert the ID of the game: ";
        cin >> idg;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }

        try {
            g = getGameWithID(idg);
        }
        catch (InexistentId) {
            cout << "There are no games with such id (" << idg << ") !" << endl;
            menuSeparator();
            break;
        }

        try {
            getCallUpWithID(idc)->addGame(g);
        }
        catch(GameExistsCallUp){
            cout << "The game already exists in call up!" << endl;
            menuSeparator();
            break;
        }
        menuSeparator();
        break;
    }
}

void NationalTeam::removeGameCallUpMenu() {
    menuSeparator();

    int idc, idg;
    Game* g;

    while (true) {
        cout << "Insert the ID of the call up you want to add the game to: ";
        cin >> idc;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');

            menuSeparator();
            break;
        }

        try {
            searchCallUpByID(idc);
        }
        catch (InexistentId) {
            cout << "There are no call ups with such id (" << idc << ") !" << endl;

            menuSeparator();
            break;
        }


        cout << "Insert the ID of the game: ";
        cin >> idg;

        if (cin.fail()) {
            cout << "Invalid option, please insert the option again: ";
            cin.clear();
            cin.ignore(10000, '\n');

            menuSeparator();
            break;
        }

        try {
            g = getGameWithID(idg);
        }
        catch (InexistentId) {
            cout << "There are no games with such id (" << idg << ") !" << endl;
            menuSeparator();
            break;
        }

        try {
            getCallUpWithID(idc)->removeGame(g);
        }
        catch(GameDontExistsCallUp){
            cout << "The game does not exist in call up!" << endl;
            menuSeparator();
            break;
        }

        menuSeparator();
        break;
    }
}