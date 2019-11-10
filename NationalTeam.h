//
// Created by tiago on 06/11/2019.
//

#ifndef AEDA_TEAM_MANAGER_NATIONALTEAM_H
#define AEDA_TEAM_MANAGER_NATIONALTEAM_H


#include <vector>
#include <sstream>
#include "Date.h"
#include "People//Person.h"
#include "People//FootballPlayer.h"
#include "People//Technician.h"
#include "CallUp.h"
#include "Exceptions.h"


class NationalTeam {
private:
public:
    vector<Person*> people;
    vector<FootballPlayer*> players;
    vector<Technician*> technicians;
    vector<CallUp*> callUps;

    NationalTeam();

    /****************************************************
    *******************PEOPLE FUNCTIONS******************
    *****************************************************/

    //Files
    bool readPeople(string fileName);
    bool savePeople(string filename);

    //Print
    void showEveryone(ostream& out);
    void sortByID(vector<Person*> &people);

    //Search and Sort
    static bool nameComparable(const Person* person1, const Person* person2);
    static bool idComparable(const Person* person1, const int id);
    void sortByName(vector<Person*> &people);
    vector<Person*> searchByName(vector<Person*> people, string name);

    template <class T>
    int searchByID(vector<T *> &people, int id){
        auto it = lower_bound(people.begin(),people.end(),id,idComparable);
        if (it != people.end() && (*it)->getId() == id) return (it-people.begin());
        else throw InexistentId(id);
    }

    //Vector operations
    template <class T, class R>
    bool addPerson(vector<T> &people, R person){
        people.push_back(person);
        return true;
    }
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
    template <class T, class R>
    int personPosition(vector<T> &people,R person){
        int index = BinarySearch(people,person);
        if(index==-1) throw out_of_range("Person not in vector");
        return index;
    }


    /****************************************************
    *******************MENUS*****************************
    *****************************************************/

    //Menu
    void runMenu();
    void menuSeparator();
    void validOption(int &option,int optionsNumber);
    void validCin(int &option);
    Date askForDate(string dateName,string &text);
    bool askYesNoQuestion();
    float askForFloat(string &text, const string &what);
    string askForString(const string &what);
    int askForId();

    //People Menu
    void runPeopleMenu();
    void runPlayersMenu();
    void runTechnicianMenu();
    void showSpecificPerson();
    void askPersonInformation(string &name,float &salary,Date &birthday);
    void createPlayerOption();
    void removePlayerOption();
    void modifyPlayerOption();
    void removeTechOption();
    void createTechOption();
    void modifyTechOption();
    Technician *askTechInformation();
    FootballPlayer* askPlayerInformation();

    template <class T>
    int askForValidId(vector<T *> &peepz){
        int id = askForId();
        while (true)
        {
            try {
                searchByID(peepz, id);
                break;
            }
            catch (InexistentId(id)) {
                id = askForId();
            }
        }
        return id;
    }


    //Game Menu
    void runGameMenu();

    //Economies Menu
    void playerMonthMenu();
    void playerTimeMenu();
    void teamMonthMenu();
    void teamTimeMenu();
    void staffMonthMenu();
    void staffTimeMenu();
    void runEconomiesMenu();

    //Call Up Menu
    void runCallUpMenu();




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
    //team+staff costs
    float allCostCalculator(Date d1, Date d2);
    float allCostCalculatorMonth(int monthNumber, int yearNumber);


    //READ FROM TEXT FILES
    void read(ifstream *file,string peopleFile);
    void readCallUp(ifstream *file);

    //FIND PLAYER IN CALLUPS AND CALCULATE NUMBER OF DAYS HE WAS IN




};

#endif //AEDA_TEAM_MANAGER_NATIONALTEAM_H
