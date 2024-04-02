#include "include/Humidity.h"

Humidity::Humidity() {};
Humidity::~Humidity() {};
Humidity::Humidity(string location):Statistics(location){}
void Humidity::display() {
  double warmest_temp;
  double coldest_temp;
  double present_humidity;
  double present_temp;
  double presipitation;
  double wind_speed;
  double const PM25 = 6;

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

        cout << "HUMIDITY FACTORS" << endl;
        cout << "________________" << endl;

        cout << "Visibilaty: " << (17.3 + 0.09 * present_temp - 0.11 * present_humidity + 0.34 * wind_speed * PM25) << "%" << endl;

        cout << "Heat Index: " << (-8.78469475556 + (1.61139411 * present_temp) + (2.33854883889 * present_humidity) + (-0.14611605 * present_temp * present_humidity) + (-0.012308094 * pow(present_temp, 2)) + (-0.0164248277778 * pow(present_humidity, 2)) + (2.211732 * 0.001 * pow(present_temp, 2) * present_humidity) + (7.2546 * 0.0001 * present_humidity * pow(present_humidity, 2)) + (-3.582 * 0.000001 * pow(present_temp, 2) * pow(present_humidity, 2))) << endl;
        break;
      }
    }

    if (l != m_location) {
      cout << "Error City not found" << endl;
    }

  }
};