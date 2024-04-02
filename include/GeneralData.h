#pragma once
#include "Statistics.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class GeneralData :
    public Statistics
{
public:
    GeneralData();
    ~GeneralData();
    GeneralData(string location);
    void display();
};