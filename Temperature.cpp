#include "include/Temperature.h"
#include "include/Statistics.h"

Temperature::Temperature() {
};
Temperature::~Temperature() {};
Temperature::Temperature(string location) : Statistics(location){}
void Temperature::display() {
  double warmest_temp;
  double coldest_temp;
  double presipitation;
  double present_humidity;
  int const basetemp = 5;
  double wind_speed;
  double present_temp;
  const int solar_radiation = 1380;

  string l = m_location;

  fstream File;
  File.open("CityData.txt");

  if (File) {

    while(File >> l){

    if (l == m_location) {
      File >> present_temp;
      File >> present_humidity;
      File >> presipitation;
      File >> wind_speed;
      File >> warmest_temp;
      File >> coldest_temp;

      cout << "TEMPERATURE FACTORS" << endl;
      cout << "______________________" << endl;

      cout << "Growing Green Days (Estimates the growth and development of crops): " << (warmest_temp + coldest_temp) / 2 - basetemp << endl;

      cout << "\nWind chill factor (Estimates air temperature feels like to the human skin \ndue to the combination of cold temperatures and winds blowing on exposed skin): " << (13.12 + 0.625 * present_temp - 11.37 * pow(wind_speed, 0.16) + 0.3965 * wind_speed * present_temp) << "km/h * C" << endl;

      cout << "\nEvaporation( the number of water molecules evaporating in a \ngiven area over a given time period): " << (0.408 * 0.003 * (present_temp + 20) * pow((warmest_temp - coldest_temp), 0.4) * solar_radiation) << "C * W/m^2" << endl;
      break;
    }
  }
      if (l != m_location) {
    cout << "Error City not found" << endl;
  }

  }


};