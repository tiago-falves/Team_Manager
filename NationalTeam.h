//
// Created by tiago on 06/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_NATIONALTEAM_H
#define AEDA_TEAM_MANAGER_NATIONALTEAM_H


#include <vector>
#include <string>
#include <sstream>
#include "Date.h"
#include "People//Person.h"
#include "People//FootballPlayer.h"
#include "People//Technician.h"
#include "CallUp.h"
#include "Exceptions.h"


class NationalTeam {
private:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;
    vector<CallUp*> callUps;
    vector<Game*> games;
    string peopleFile;
    string gameFile;
    string statisticsFile;
    string callUpFile;





public:
    NationalTeam();

    /**
     * Gets the name of the people File
     * @return  const string representig people file
     */
    const string &getPeopleFile() const;

    /**
     * Sets the name of the people's file
     * @param peopleFile - Name of the people file
     */
    void setPeopleFile(const string &peopleFile);

    const string &getCallUpFile() const;

    void setCallUpFile(const string &callUpFile);

    const string &getGameFile() const;

    void setGameFile(const string &gameFile);

    const string &getStatisticsFile() const;

    void setStatisticsFile(const string &statisticsFile);

    vector<Game*> getGames(){
        return games;
    }


    /****************************************************
    *******************PEOPLE FUNCTIONS******************
    *****************************************************/

    //Files

    /**
     * @brief Given the name of the file, reads all the
     * people that are in the file
     * it contains both Football Players and Technicians
     * @param fileName Name of the people's file
     * @return true if the file was read successfully
     */
    bool readPeople(string fileName);

    /**
     * @brief Given a file name, it outputs to the file all the information from everyone
     * @param filename - Name of the people's file
     * @return true in case the operation was successfull
     */
    bool savePeople(string filename);

    //Print

    /**
     * Prints to the ostream everyone in the database
     * @param out - Where to print the information
     */
    void showEveryone(ostream& out);

    /**
     * @brief Asks for an id, and prints Person with that id
     */
    void showSpecificPersonOption();

    /**
     * Given a vector of people, sorts it acoordingly to the ids
     * @param people vector of type Person*
     */
    void sortByID(vector<Person*> &people);

    //Search and Sort

    /**
     * Function used to campare People by their name
     * @param person1 Person to compare
     * @param person2 Person to compare
     * @return true if the name of the first Person is smaller than from the second one
     */
    static bool nameComparable(const Person* person1, const Person* person2);

    /**
     * Function used to compare if a id of a person is equal to id
     * @param person1 Person we want to compare
     * @param id to compare
     * @return True if the id of the person is equal to the second argument
     */
    static bool idComparable(const Person* person1, const int id);

    /**
     * Function used to Sort a Person* vector by their names
     * @param people
     */
    void sortByName(vector<Person*> &people);

    /**
     * Given a Person* vector and a name, returns all the people with that same name
     * @param people vector with all the people
     * @param name -Name we want to search for
     * @return vector with all the people with that name
     */
    vector<Person*> searchByName(vector<Person*> people, string name);

    /**
     * @brief Given a Object* vector and an id, Returns the Object with that same id
     * This sort uses Binary search since the ids are always ordered
     * @tparam T Template function so it accepts all types that have a unique ID as a menber
     * @param people vector we want to search
     * @param id - Id we want to search for
     * @return
     */
    template <class T>
    int searchByID(vector<T *> &people, int id){
        auto it = lower_bound(people.begin(),people.end(),id,idComparable);
        if (it != people.end() && (*it)->getId() == id) return (it-people.begin());
        else throw InexistentId(id);
    }

    //Vector operations

    /**
     * Given a person and a vector of people, it adds that person to the end of the vector
     * @tparam T It can be of any time if R is compatible
     * @tparam R can be of any type if T is compatible
     * @param people  vector we want to add the object
     * @param person Object we want to add
     * @return true if operation was successfull
     */
    template <class T, class R>
    bool addPerson(vector<T> &people, R person){
        people.push_back(person);
        return true;
    }

    /**
     * Given a id and a vector of people, it removes the person with the id of the vector
     * @tparam T Of type people or derivatives
     * @param people  vector we want to remove the object
     * @param id id of the person we want to remove
     * @return true if operation was successfull
     */
    template <class T>
    bool removePerson(vector<T> &people, int id){
        int index;
        try {index = searchByID(people,id);}
        catch (InexistentId(index)){
            cerr << "Tried to remove Person that doesn't exist" << endl;
            return false;
        }
        people.erase(people.begin()+index);
        return true;
    }

    /**
     * Given a vector of people, and two people, it sets all the atribbutes
     * from the person to the attributes of the newPerson
     * @tparam T Can be of type people or derivatives
     * @tparam R Can only be of people derivatives
     * @param people vector where we want to modify
     * @param person - person we want to modify
     * @param newPerson - Person with all the new information about the person
     * @return
     */
    template <class T, class R>
    bool modifyPerson(vector<T> &people, R person, R newPerson){
        try {personPosition(people,person);}
        catch (out_of_range){
            cerr << "Tried to modify Person that doesn't exist: " << person->getName() << endl;
            return false;
        }
        person->modify(newPerson);
        return true;
    }

    /**
     * Given a person and a vector of people, it returns the position of the person in the vector
     * Uses Bynary search since people vectors are always ordered by the id
     * @tparam T Can be of people or derivatives
     * @tparam R Can only be of people derivatives
     * @param people vector where we want to search
     * @param person Person we want to search
     * @return Index of the person position in the vector
     */
    template <class T, class R>
    int personPosition(vector<T> &people,R person){
        int index = BinarySearch(people,person);
        if(index==-1) throw out_of_range("Person not in vector");
        return index;
    }

    /****************************************************
    ********************GAMES FUNCTIONS******************
    *****************************************************/
    bool readGames(string filename);
    bool readGameStatiscs(string filename);
    void saveGames(string filename);
    void printAllGameInfo(ostream& out, Game * game);


    template <class T>
    bool removeGame(vector<T> &game, int id){
        int index;
        try {index = searchGameByID(game,id);}
        catch (InexistentId(index)){
            cerr << "Tried to remove Game that doesn't exist" << endl;
            return false;
        }
        games.erase(games.begin()+index);
        return true;
    }

    template <class T, class R>
    bool addGame(vector<T> &game, R person){
        games.push_back(game);
        return true;
    }

    static bool idGameComparable(const Game* game, const int id){
        return (game->getID() < id);
    }

    int searchGameByID(vector<Game *> &game, int id){
        auto it = lower_bound(game.begin(),game.end(),id,idGameComparable);
        if (it != game.end() && (*it)->getID() == id) return (it-game.begin());
        else throw InexistentId(id);
    }

    static bool idStatsComparable(const PlayerGameStatistics stats, const int id){
        return (stats.getPlayerID() < id);
    }

    int searchStatsByID(vector<PlayerGameStatistics> stats, int id){
        auto it = lower_bound(stats.begin(), stats.end(),id,idStatsComparable);
        if (it != stats.end() && (*it).getPlayerID() == id) return (it-stats.begin());
        else throw InexistentId(id);
    }


    vector<Game*> getAllGamesForPlayer(FootballPlayer * player);

    /****************************************************
    *******************MENUS*****************************
    *****************************************************/

    //Menu

    /**
     * Runs The main menu with all the main categories
     */
    void runMenu();

    /**
     * Prints to the screen a string used to separate the menus
     */
    void menuSeparator();

    /**
     * Given a certain option, and an option number, verifies if the
     * option  is valid, and if it isn't, keeps asking the user for a new one
     * the option can vary from 0 to optionsNumber
     * @param option Option of the user
     * @param optionsNumber Limiter of options
     */
    void validOption(int &option,int optionsNumber);

    /*
     * Verifies if the input is valid, and if it isn't, keeps asking the user for a valid option
     * @param it Gives the option as a paramter, and in case it fails, changes the option
     */
    void validCin(int &option);

    /**
     * Asks the user for a Date
     * Keeps asking the user if the date is invalid
     * @param dateName Ocasion of the Date, for example "Birthday"
     * @param text is the place where the final string input of the user is savd
     * @return Returns a date of type Date
     */
    Date askForDate(string dateName,string &text);

    /**
     * Asks the user a yes or no question
     * @return True if the answer was yes
     */
    bool askYesNoQuestion();

    /**
     * Asks for a float until the input is valid
     * @param text input of the user
     * @param what For example Salary
     * @return float containing a valid float
     */
    float askForFloat(string &text, const string &what,float lower,float higher);

    /**
     * Asks for an integer until the input is valid
     * @param text input of the user
     * @param what For example Salary
     * @return integer containing a valid integer
     */
    int askForInt(const string &what);

    /**
     * Asks the user for a string
     * @param what What type of string? for example "name"
     * @return the input of the user
     */
    string askForString(const string &what);

    /**
     * @brief Asks the user for an id until it inserts a valid input
     * @return valid id chosen by the user
     */
    int askForId();

    //People Menu

    /**
     * Runs the Menin People Menu with all the options
     */
    void runPeopleMenu();

    /**
     * Runs the main Player's Menu with all Football Player coorelated options
     */
    void runPlayersMenu();

    /**
     * Runs the main Technician's Menu with all Technician coorelated options
     */
    void runTechnicianMenu();

    /**
     *Given an id, it shows the Person with that id
     * @param out where the information is going to be outputted
     * @param i id of the Person that will be printed
     */
    void showSpecificPerson(ostream &out,int i);

    /**
     * Asks the user all the information about a person and it returns it's attributes in the paramters
     * @param name Name of the Person
     * @param salary Salary of the Person
     * @param birthday Birthday Date of the Person
     */
    void askPersonInformation(string &name,float &salary,Date &birthday);

    /**
     * Asks the user for the information of the player
     * Adds it to the database
     */
    void createPlayerOption();

    /**
     * Asks the id of the Player it wants to remove
     * removes it from the database
     */
    void removePlayerOption();

    /**
     * Asks the id of the Player it wants to modify
     * Asks all the new information about the player
     * Modifies it in the Database
     */
    void modifyPlayerOption();

    /**
     * Asks the id of the Technician it wants to remove
     * removes it from the database
     */
    void removeTechOption();

    /**
     * Asks the user for the information of the technician
     * Adds it to the database
     */
    void createTechOption();

    /**
     * Asks the id of the Technician it wants to modify
     * Asks all the new information about the technician
     * Modifies it in the Database
     */
    void modifyTechOption();

    /**
     * Asks the user all the information about a Technician
     * @param technician technician we want to set the informations
     */
    void askTechInformation(Technician *technician);

    /**
     * Asks the user all the informations about the player
     * @param footballPlayer Player we want to set the data
     */
    void askPlayerInformation(FootballPlayer *footballPlayer);

    void showPlayerGames(int id);
    void showPlayerCallUps(int id);

    void showGameStats(int id);
    void showCallUpStats(int id);

    void playerMenuTransition();


    /**
     * Template class that asks the user for id and catches exception
     * if the user tris to search for an id that is not
     * in the database
     * @tparam T Can be of any type that has the atribbute id
     * @param peepz of type T, in this represents any pointer of type person
     * @return  int representing a valid id
     */
    template <class T>
    int askForValidId(vector<T *> &peepz){

        int id;

        while (true)
        {
            id = askForId();

            try {
                searchByID(peepz, id);
                break;
            }
            catch (InexistentId(id)) {
                cout << "Invalid Input.\n";
            }
        }

        return id;
    }


    //Game Menu
    void runGameMenu();
    int createGameOption(ostream &out);
    int removeGameOption(ostream &out, const int& id);
    void modifyGameOption(ostream &out, int option);
    void modifyVectorOption(ostream &out, string vectorType);
    void showAllGames(ostream &out);
    void showSpecificGame(ostream &out);
    void showSpecificStats(ostream &out);
    void askForPlayers(ostream &out, Game * game);
    void askForStringVector(ostream &out, string what, Game* game);
    PlayerGameStatistics askForPlayerStatistics(ostream &out, int playerID);
    void showModifyGameOptions(ostream &out);


    //Economies Menu
    void playerMenu();
    void playerMonthMenu();
    void playerTimeMenu();

    void teamMenu();
    void teamMonthMenu();
    void teamTimeMenu();

    void staffMenu();
    void staffMonthMenu();
    void staffTimeMenu();

    void runEconomiesMenu();

    //Call Up Menu
    void runCallUpMenu();
    void allCallUpMenu();
    void callUpMenu();
    void createCallUpMenu();
    void removeCallUpMenu();
    void modifyCallMenu();
    void addGameCallUpMenu(const int& id);
    void removeGameCallUpMenu();

    void allEqual(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    void setAllEqual(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    void infoManually(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    void listDifferent(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);

    /****************************************************
    *******************SALARY FUNCTIONS******************
    *****************************************************/



    //Handle costs (sallaries + insurance)
    //player costs
    float playerCostCalculator(Date d1, Date d2, int playerID);
    float playerCostCalculatorMonth(int monthNumber, int yearNumber, int playerID);
    //team costs
    float teamCostCalculator(Date d1, Date d2);
    float teamCostCalculatorMonth(int monthNumber, int yearNumber);
    //staff costs
    float staffCostCalculator(Date d1, Date d2);
    float staffCostCalculatorMonth(int monthNumber);


    //READ FROM TEXT FILES
    void read(string peopleFile,string callUpFile,string gameFile,string statisticsFile);


    void tableHeaderPlayer(ostream &out);
    void tableHeaderAllGames(ostream &out);
    void tableHeaderStatistics(ostream &out);
    void tableHeaderEnemyTeam(ostream &out);
    void tableHeaderReferee(ostream &out);

    void tableFooterPlayer(ostream &out);
    void tableFooterAllGames(ostream &out);
    void tableFooterStatistics(ostream &out);
    void tableFooterEnemyTeamReferee(ostream &out);

    /****************************************************
    *******************HANDLE CALLUPS******************
    *****************************************************/
    //READ FROM FILE
    bool readCallUp(string file);

    //CHANGE CALLUP
    void changeDailyCosts(int id);
    void reduceBegDate(int id);
    void extendEndDate(int id);

    //DELETE CALLUP
    void deleteCallUp(int id);

    //HEADER WHEN PRINTING CALL UP OBJECTS
    void headerCallUp(ostream& out);

    //SEARCH CALL UP BY ID
    bool searchCallUpByID(const int &id);

    //GET GAME AND CALLUP USING ID
    Game* getGameWithID(int id);
    CallUp* getCallUpWithID(int id);





    void saveAndExit(string fileName,string callUpFileName,string gamesFileName, string etcFileName);

    bool readNationalTeam(string fileName);

    void showPersonByName();
};

#endif //AEDA_TEAM_MANAGER_NATIONALTEAM_H
