#include "include/Statistics.h"

Statistics::Statistics() { m_location = ""; };
Statistics::~Statistics() {};
Statistics::Statistics(string location) {
  m_location = location; 
  fstream File;
  File.open("CityData.txt");//Reading from CityData.txt into vairables.
  if (File){
    while(File >> m_location){
      File >> present_temp;
      File >> present_humidity;
      File >> presipitation;
      File >> wind_speed;
      File >> warmest_temp;
      File >> coldest_temp;
    }
  } else {
    cout << "Unable to open file." << endl;
  }
};