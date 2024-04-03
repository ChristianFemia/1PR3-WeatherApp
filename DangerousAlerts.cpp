#include "include/DangerousAlerts.h"


DangerousAlerts::DangerousAlerts() : Alerts() {
  m_dewPoint = (m_temp - ((100 - m_humidity) / 5));
}

double DangerousAlerts::getDewPoint() {
  return m_dewPoint;
}

void DangerousAlerts::displayAlert() {

  if (m_dewPoint >= 10 && m_windSpeed > 100) { cout << "WARNING TORNADO POSSIBILITY IN: " << m_location << endl; } 
  else if (m_pressure >= 1005) { cout << "WARNING STORM POSSIBILITY IN: " << m_location << endl; }
  else if (m_percipitation >= 8) {  cout << "WARNING HEAVY RAINFALL COMING IN: " << m_location << endl; }
  else { cout << "No alerts in: " << m_location << endl; }

}