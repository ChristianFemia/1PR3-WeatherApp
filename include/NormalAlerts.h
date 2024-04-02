#pragma once
#include "Alerts.h"
class NormalAlerts : public Alerts
{

public:
  NormalAlerts();
  NormalAlerts(string loc, double temp, double wind);

  void displayAlert();
};
