#include "include/XMLParser.h"

XMLDocument* parseXML(const string& xmlData, XMLDocument &pDoc) {
    XMLDocument* doc = &pDoc;
    doc->Parse(xmlData.c_str());
    if (doc->Error()) {
        cerr << "Failed to parse XML" << endl;
    }
    return doc;
}
/*
void printXMLElements(const TiXmlDocument& doc) {
    const TiXmlElement* root = doc.RootElement();
    if (root) {
        for (const TiXmlElement* elem = root->FirstChildElement(); elem; elem = elem->NextSiblingElement()) {
            cout << "Element name: " << elem->Value() << ", value: " << elem->GetText() << endl;
        }
    } else {
        cerr << "XML data is empty or invalid." << endl;
        throw runtime_error("XML data is empty or invalid.");
    }
}*/