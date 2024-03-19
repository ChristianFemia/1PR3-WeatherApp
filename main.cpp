#include <iostream>
#include "HTTPParser.h"

using namespace std;

int main() {
    HTTPParser parser( ProvinceCode::ON);
    parser.callUrl();
    return 0;
}