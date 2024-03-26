#pragma once
#include "HTTPParser.h"
#include "tinyxml2.h"
using namespace tinyxml2;
class XMLParser : public HTTPParser {
private:
  string _data;
  ProvinceCode _code;

public:
  XMLParser();
  XMLParser(ProvinceCode code);

  XMLElement* parseXML(string xmlData);

  void printXMLElements(XMLElement* element);

};