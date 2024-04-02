#include "include/XMLParser.h"
#include <fstream>

XMLParser::XMLParser(){
  throw std::invalid_argument("Class requires parameters");
}
XMLParser::XMLParser(ProvinceCode code, string cityCode) : HTTPParser(code, cityCode){
  _data = "";
}
  
void XMLParser::parseXML() {

  tinyxml2::XMLDocument doc;
  doc.Parse(fetchData().c_str());
  
  fstream file("CityData.txt");
  const char* elementToSearch[] = { "temperature", "relativeHumidity", "precipitation", "winds"};

  string name = 
doc.FirstChildElement("siteData")->FirstChildElement("location")->FirstChildElement("name")->GetText();
   cout << name << endl;
  string temp = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("temperature")->GetText();
  cout << temp << endl;

  //precip
  string rain = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("forecast")->FirstChildElement("precipitation")->FirstChildElement("accumulation")->FirstChildElement("amount")->GetText();
  if(rain !="") {
    cout << "Precipitation: " << rain << endl;
  } else{
    rain = "";
    cout << "Precipitation: 0" << endl;
  }
  //wind speeds
  string wind = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("wind")->FirstChildElement("speed")->GetText();
  if(wind != ""){
    cout << wind << endl;
  } else{
    wind = "";
    cout << "No wind data" << endl;
  }

  string humidity = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("relativeHumidity")->GetText();
  cout << humidity << endl;

  string high = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("regionalNormals")->FirstChildElement("temperature")->GetText();
  cout << high << endl;

  string low = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("regionalNormals")->FirstChildElement("temperature")->NextSiblingElement()->GetText();
  cout << low << endl;
  file << name << " " << temp  << " " << rain  << " " << wind << " " << humidity << " " << high << " "  << low;
  file.close();
}