#include "StringManipulator.h"

using namespace std;

void trimRight(string &s) {
	s.erase(s.find_last_not_of(" ") + 1);
}
void trimLeft(string &s) {
	s.erase(0, s.find_first_not_of(" "));
}
void trim(string &s) {
	trimRight(s);
	trimLeft(s);
}
vector<int> separateCharacterInt(string s, char ch) {
	vector<int> vetor;
	if (s == "")
		return vetor;
	while (s.find_first_of(ch) != s.npos)	{
		vetor.push_back(stoi(s.substr(0, s.find_first_of(ch))));
		s.erase(0, s.find_first_of(ch) + 1);
	}
	vetor.push_back(stoi(s.substr(0, s.find_first_of(ch))));
	return vetor;
}

vector<string> separateCharacterStr(string s, char ch) {
	vector<string> vetor;
	string aux;
	while (s.find_first_of(ch) != s.npos) {
		aux = s.substr(0, s.find_first_of(ch));
		trim(aux);
		vetor.push_back(aux);
		s.erase(0, s.find_first_of(ch) + 1);
	}
	aux = s.substr(0, s.find_first_of(ch));
	trim(aux);
	vetor.push_back(aux);
	return vetor;
}

bool stringIsNumber(string number){
	int count = 0;
	for (int i = 0; i < number.size(); i++)	{
		if (!isdigit(number[i]))
			return false;
	}
	return true;
}

