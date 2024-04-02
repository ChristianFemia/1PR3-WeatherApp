#include "include/GeneralData.h"
GeneralData::GeneralData() {};
GeneralData::~GeneralData() {};
GeneralData::GeneralData(string location) : Statistics(location){}
void GeneralData::display() {
  double warmest_temp;
  double coldest_temp;
  double present_humidity;
  double present_temp;
  double presipitation;
  double wind_speed;

  string l;

  fstream File;
  File.open("CityData.txt");

  if (File) {

    while (File >> l) {
      if (l == m_location) {
        File >> present_temp;
        File >> present_humidity;
        File >> presipitation;
        File >> wind_speed;
        File >> warmest_temp;
        File >> coldest_temp;

        cout << "TODAYS UPDATE " << m_location << endl;
        cout << "______________" << endl;
        cout << "Todays temperature is: " << present_temp << " degres celcius" << endl;
        cout << "Todays humidity is: " << present_humidity << "%" << endl;
        cout << "The chance of percipitation is: " << presipitation << "%" << endl << endl;

        cout << "HIGHS & LOWS" << endl;
        cout << "____________" << endl;
        cout << "The warmest temperature this week was: " << warmest_temp - 15 << " degres celcius" << endl;
        cout << "The coldest temperature this week was: " << coldest_temp + 10 << " degres celcius" << endl;
        break;
      }

    }
        if (l != m_location) {
    cout << "Error City not found" << endl;
  }

  }


};