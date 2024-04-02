#include <iostream>
#include "report.h"
#include "XMLParser.h"

using namespace std;

int main() {
    XMLParser parser(ProvinceCode::ON);
    parser.parseXML(fetchXMLData()); // fetchXMLData() should be implemented

    Report report(parser);
    cout << "Basic Weather Report:" << endl;
    cout << report.generateBasicReport() << endl;

    cout << "Complex Weather Report:" << endl;
    cout << report.generateComplexReport() << endl;

    return 0;
}
