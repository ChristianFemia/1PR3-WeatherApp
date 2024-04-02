#include "include/Alerts.h"

Alerts::Alerts() {

  m_location = "";
  m_temp = 0;
  m_windSpeed = 0;

}

Alerts::Alerts(string loc, double temp, double wind) {

  m_location = loc;
  m_temp = temp;
  m_windSpeed = wind;

}
