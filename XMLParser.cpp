#include "include/XMLParser.h"
#include <fstream>

XMLParser::XMLParser() : HTTPParser(){ _data = ""; }
  
void XMLParser::parseXML() {

  tinyxml2::XMLDocument doc;
  doc.Parse(fetchData().c_str()); //Fetch the data and parse it.
  //Open the file and overwrite its contents
  fstream file("CityData.txt");

  //Each XMLDocument is parsing the data down-stream from each element, with the first element being the root, siteData.
//name of city 
  string name = 
doc.FirstChildElement("siteData")->FirstChildElement("location")->FirstChildElement("name")->GetText(); 
  
  string temp = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("temperature")->GetText();
  //Sometimes, these elements do not exist, so we need a try-catch to handle the exception.
  string rain = "537";
  XMLElement* rainEle;
  try {
   rainEle = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("forecast")->FirstChildElement("precipitation")->FirstChildElement("accumulation");
  }catch (std::exception& e){
    rain = "537";
  }
 
  //wind speeds
  string wind = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("wind")->FirstChildElement("speed")->GetText();
  if(wind != ""){
  } else{
    wind = "";
  }
  string humidity = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("relativeHumidity")->GetText();
  
// high temp and low temp
  string high = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("regionalNormals")->FirstChildElement("temperature")->GetText();
  string low = doc.FirstChildElement("siteData")->FirstChildElement("forecastGroup")->FirstChildElement("regionalNormals")->FirstChildElement("temperature")->NextSiblingElement()->GetText();
  string pressure = doc.FirstChildElement("siteData")->FirstChildElement("currentConditions")->FirstChildElement("pressure")->GetText();
  
  file << name << " " << temp  << " " << rain << " " << wind << " " << humidity << " " << high << " "  << low  << " " << pressure; //Save the data to the file.
  file.close();
}



