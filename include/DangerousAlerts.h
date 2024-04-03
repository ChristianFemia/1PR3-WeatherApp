#pragma once
#include "Alerts.h"
class DangerousAlerts : public Alerts
{

private:

  double m_percipitation;
  double m_humidity;
  double m_dewPoint; 
  double m_pressure; 

public:

  DangerousAlerts();

  double getDewPoint();
  void displayAlert();
};
