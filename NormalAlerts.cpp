#include "include/NormalAlerts.h"

NormalAlerts::NormalAlerts() : Alerts() {

}

void NormalAlerts::displayAlert() {

  if (m_temp <= -20 && m_windSpeed <= 50) { cout << "Freeze Alert for " << m_location << ": Temperature is " << m_temp << " degrees Celsius." << endl; }
  
  else if (m_temp < -20 && m_windSpeed > 50) { cout << "Blizzard Alert for " << m_location << ": Temperature is " << m_temp << " degrees Celsius and wind speed is " << m_windSpeed << " kph." << endl; }
  
  else if (m_temp >= 30 && m_windSpeed <= 50) { cout << "Heat warning for " << m_location << ": Temperature is " << m_temp << " degrees Celsius." << endl; }
    
  else if (m_temp > 30 && m_windSpeed > 50) { cout << "Warning for heat stroke and high speeds of wind in " << m_location << ": Temperature is " << m_temp << " degrees Celsius and wind speed is " << m_windSpeed << " kph." << endl; }
  else {
    cout << "No Important Alerts for: " << m_location << endl;
  }

}
