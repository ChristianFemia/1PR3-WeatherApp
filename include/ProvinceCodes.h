#pragma once
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>

//An ENUM class that allows for easy implementation of province codes.
enum class ProvinceCode
{
    AB,
    BC,
    HEF,
    MB,
    NB,
    NL,
    NS,
    NT,
    NU,
    ON,
    PE,
    QC,
    SK,
    YT
};
//A utility class that allows for ENUM province codes to be converted into strings.
class ProvinceCodes
{
    ProvinceCodes();
private:
    static std::map<ProvinceCode, std::string> enumToString;

public:
    static std::string toString(ProvinceCode value){ return enumToString[value]; }
};
