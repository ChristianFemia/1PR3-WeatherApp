#include <iostream>
#include "include/XMLParser.h"

using namespace std;

int main() {

    XMLParser parser(ProvinceCode::ON, "s0000549");
    parser.parseXML();
}
