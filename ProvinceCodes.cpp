#include "include/ProvinceCodes.h"
ProvinceCodes::ProvinceCodes(){
    throw std::invalid_argument("Error! This is a utility class!");
}
std::map<ProvinceCode, std::string> ProvinceCodes::enumToString = {
        {ProvinceCode::AB, "AB"},
        {ProvinceCode::BC, "BC"},
        {ProvinceCode::MB, "MB"},
        {ProvinceCode::NB, "NB"},
        {ProvinceCode::NL, "NL"},
        {ProvinceCode::NS, "NS"},
        {ProvinceCode::NT, "NT"},
        {ProvinceCode::NU, "NU"},
        {ProvinceCode::ON, "ON"},
        {ProvinceCode::PE, "PE"},
        {ProvinceCode::QC, "QC"},
        {ProvinceCode::SK, "SK"},
        {ProvinceCode::YT, "YT"}
    };