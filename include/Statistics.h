#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Statistics
{
protected:
  string m_location;
public:
  Statistics();
  ~Statistics();
  Statistics(string location);
  void virtual display() = 0;
};