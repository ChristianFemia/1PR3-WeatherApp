#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Alerts 
{

protected:
  string m_location;
  double m_temp;
  double m_windSpeed;
  double m_rain;
  double m_pressure;
  double m_humidity;
  double m_highTemp;
  double m_lowTemp;

public:
  Alerts();

  //Pure Virtual Functions
  virtual void displayAlert() = 0;
};
