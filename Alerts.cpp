#include "include/Alerts.h"

Alerts::Alerts() {

  fstream File;
  File.open("CityData.txt");//Reading from CityData.txt into vairables.
  if (File){
    while(File){
      File >> m_location;
      File >> m_temp;
      File >> m_rain;
      File >> m_windSpeed;
      File >> m_humidity;
      File >> m_highTemp;
      File >> m_lowTemp;
      File >> m_pressure;
    }
  } else {
    cout << "Unable to open file." << endl;
  }

}

