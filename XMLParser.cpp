#include "XMLParser.h"

XMLParser::XMLParser(ProvinceCode code) : HTTPParser(code) {}

void XMLParser::parseXML(const std::string &xmlData) {
  if (!xmlData.empty()) {
    _doc.Parse(xmlData.c_str());
  } else {
    _data = fetchData();
    _doc.Parse(_data.c_str());
  }
}

XMLElement *XMLParser::getRootElement() { return _doc.RootElement(); }
