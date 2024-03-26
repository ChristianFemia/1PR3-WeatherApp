#include "include/XMLParser.h"


XMLParser::XMLParser(){
  throw std::invalid_argument("Class requires parameters");
}
XMLParser::XMLParser(ProvinceCode code) : HTTPParser(code){
  _data = "";
}
  
XMLElement* XMLParser::parseXML(string xmlData) {

  tinyxml2::XMLDocument doc;
  doc.Parse(fetchData().c_str());
  XMLElement* child = doc.FirstChildElement();
  printXMLElements(child);
  return child;
}

void XMLParser::printXMLElements(XMLElement* element) {
  for (XMLElement* elem = element; elem != nullptr; elem = elem->NextSiblingElement()) {
      const char* elementName = elem->Value();
      cout << "Element: " << elementName;

      // Print attributes if any
      const XMLAttribute* attr = elem->FirstAttribute();
      while (attr) {
          cout << " | Attribute: " << attr->Name() << " = " << attr->Value();
          attr = attr->Next();
      }

      // Print text content if any
      const char* text = elem->GetText();
      if (text) {
          cout << " | Text: " << text;
      }

      cout << endl;

      // Recursively print child elements
        printXMLElements(elem->FirstChildElement());
  }
}