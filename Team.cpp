
#include <algorithm>
#include <fstream>
#include "Team.h"
using namespace std;


Team::Team(string fileName) {
    readFile(fileName);
}

bool Team::readFile(string fileName) {
    string personText;
    ifstream peopleFile;
    int line= 0;

    peopleFile.open(fileName);
    if(peopleFile.fail()){
        cout << "Error Opening";
        return false;
    }
    else{

    }


    return false;
}
