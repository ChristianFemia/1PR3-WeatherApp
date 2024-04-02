#pragma once
#include <string>
using namespace std;

class Userpreference {
private:
    string _name;
    string _choice;
public:
    Userpreference(string name, string choice);
    string getName();
    string getChoice();


};