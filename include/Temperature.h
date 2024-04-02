#pragma once
#include "Statistics.h"
#include <fstream>
class Temperature :
    public Statistics
{
public:
    Temperature();
    ~Temperature();
    Temperature(string location);
    void display();
};