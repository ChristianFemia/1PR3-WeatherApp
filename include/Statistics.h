#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
class Statistics
{
protected:
  string m_location;
  double warmest_temp;
  double coldest_temp;
  double present_humidity;
  double present_temp;
  double presipitation;
  double wind_speed;
public:
  Statistics();
  ~Statistics();
  Statistics(string location);
  void virtual display() = 0;
};