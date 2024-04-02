#pragma once
#include <iostream>
#include <string>

using namespace std;

class Alerts 
{

protected:
  string m_location;
  double m_temp;
  double m_windSpeed;

public:
  Alerts();

  Alerts(string loc, double temp, double wind);
  //Pure Virtual Functions
  virtual void displayAlert() = 0;
};
