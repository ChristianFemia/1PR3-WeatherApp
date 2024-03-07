#pragma once
#include <string>
#include <stdexcept>
#include <curl/curl.h>
#include <iostream>
#include "ProvinceCodes.h"
using namespace std;
class HTTPParser
{
private:
    string _url;
    ProvinceCode _code;

public:
    HTTPParser();
    HTTPParser(ProvinceCode code);

    void callUrl();
};
