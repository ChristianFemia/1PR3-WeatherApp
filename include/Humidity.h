#pragma once
#include "Statistics.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Humidity :
    public Statistics
{
public:
    Humidity();
    ~Humidity();
    Humidity(string location);
    void display();
};