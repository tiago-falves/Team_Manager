#pragma once
#include <string>
#include <vector>
using namespace std;

void trimRight(std::string &s);

void trimLeft(std::string &s);

void trim(std::string &s);

vector<int> separateCharacterInt(string s, char ch);

bool stringIsNumber(string number);

vector<string> separateCharacterStr(string s, char ch);
