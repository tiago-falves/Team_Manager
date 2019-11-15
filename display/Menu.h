//
// Created by tiago on 15/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_MENU_H
#define AEDA_TEAM_MANAGER_MENU_H

#include "../NationalTeam.h"

class Menu:  public NationalTeam {
public:
    Menu();

    /**
     * Runs The main menu with all the main categories
     */
    void runMenu();

    /****************************************************
*******************MENUS*****************************
*****************************************************/
private:
    //Menu



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

    void showPersonByName();

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

    void tableHeaderPlayer(ostream &out);
    void tableHeaderAllGames(ostream &out);
    void tableHeaderStatistics(ostream &out);
    void tableHeaderEnemyTeam(ostream &out);
    void tableHeaderReferee(ostream &out);

    void tableFooterPlayer(ostream &out);
    void tableFooterAllGames(ostream &out);
    void tableFooterStatistics(ostream &out);
    void tableFooterEnemyTeamReferee(ostream &out);


    //Economies Menu
    /**
     * When called program advances to submenu where user can see costs associated with players
     */
    void playerMenu();
    /**
     * When called program advances to submenu where user can see costs associated with players
     * in a determined month
     */
    void playerMonthMenu();
    /**
     * When called program advances to submenu where user can see costs associated with players
     * between two given dates
     */
    void playerTimeMenu();

    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     */
    void teamMenu();
    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     * in a determined Month
     */
    void teamMonthMenu();
    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     * between two given dates
     */
    void teamTimeMenu();

    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     * and Staff
     */
    void staffMenu();
    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     * and Staff in a determined month
     */
    void staffMonthMenu();
    /**
     * When called program advances to submenu where user can see costs associated with all National Team
     * and Staff between two given dates
     */
    void staffTimeMenu();

    /**
     * When called program advance to submenu where user can see information about National Team's economies
     */
    void runEconomiesMenu();

    //Call Up Menu
    /**
     * When called program advance to submenu where user can see information about National Team's call ups
     */
    void runCallUpMenu();
    /**
     *Shows information on screen about all call ups
     */
    void allCallUpMenu();
    /**
     * Shows information on screen about one specific call up
     */
    void callUpMenu();
    /**
     * Creates a new call up
     */
    void createCallUpMenu();
    /**
     * Deletes an existant call up
     */
    void removeCallUpMenu();
    /**
     * Modifies certain parameters in call up
     */
    void modifyCallMenu();
    /**
     * Advances to menu where game with id (id) will be added to call up
     * @param id - id of game that will be added to call up
     */
    void addGameCallUpMenu(const int& id);
    /**
     * Advances to menu where game will be removed from call up
     */
    void removeGameCallUpMenu();

    /**
     * Asks user if he wants to set time that players were in call up equal for all of them
     * @param begDate - beggin Date of the interval
     * @param endDate - end Date of the interval
     * @param call_game - list of games that are part of the call up
     * @param stats - vector that contains date interval that all players were in call up
     */
    void allEqual(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    /**
     * Sets date interval that player was in call up equal for all of them
     * @param begDate - beggin Date of the interval
     * @param endDate - end Date of the interval
     * @param call_game - list of games that are part of the call up
     * @param stats - vector that contains date interval that all players were in call up
     */
    void setAllEqual(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    /**
     * Asks user to insert date interval for every player in call up
     * @param begDate - beggin Date of the interval
     * @param endDate - end Date of the interval
     * @param call_game - list of games that are part of the call up
     * @param stats - vector that contains date interval that all players were in call up
     */
    void infoManually(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);
    /**
     * Asks user the list of ids that were not the all time in call up, and sets that time manually
     * @param begDate - beggin Date of the interval
     * @param endDate - end Date of the interval
     * @param call_game - list of games that are part of the call up
     * @param stats - vector that contains date interval that all players were in call up
     */
    void listDifferent(Date begDate, Date endDate, vector<Game*> call_game, vector<CallUpPlayerStatistics*> stats);


    //HEADER WHEN PRINTING CALL UP OBJECTS
    /**
     * Header of the table which contains call up information that is shown on screen
     * @param out
     */
    void headerCallUp(ostream& out);

    /**
     * Asks for dates when creating call up
     * @param begDate - initial date
     * @param endDate - final date
     */
    void askForDates(Date& begDate, Date& endDate);


    //CHANGE CALLUP
    /**
     * Changes call up daily costs
     * @param id - id of the call up that will be changed
     */
    void changeDailyCosts(int id);
    /**
     * Sets beggin Date of the call up lower
     * @param id - id of the call up that will be changed
     */
    void reduceBegDate(int id);
    /**
     * Sets beggin Date of the call up higher
     * @param id - id of the call up that will be changed
     */
    void extendEndDate(int id);

};


#endif //AEDA_TEAM_MANAGER_MENU_H
