//
// Created by berna on 23/12/2019.
//

#include <cstdlib>
#include <iostream>
#include "People/Person.h"

using namespace std;

#ifndef AEDA_TEAM_MANAGER_HASHTABLE_H
#define AEDA_TEAM_MANAGER_HASHTABLE_H


class HashTable {

    static const int tableSize = 40;

    struct item{
        Person * person;
        bool currentlyWorking;
        item * next;
    };

    item* hashTable[tableSize];

public:
    HashTable();

    virtual ~HashTable();

    int hash(Person * key);
    void addItem(Person * person, bool currentlyWorking);
    int numberOfItemsInIndex(int index);
    void removeItem(Person * person);
    void printAll();
    void printOld();
    void printCurrent();
};


#endif //AEDA_TEAM_MANAGER_HASHTABLE_H
