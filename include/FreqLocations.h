#pragma once
#include <string> 
using namespace std;

class FreqLocations{
private:
    string m_province;
    string m_city;
    string m_frequence;
public:
FreqLocations();
~FreqLocations();

string getProvince(){return m_province;};
string getCity(){return m_city;};
string getFrequence(){return m_frequence;}

void setProvince(string province);
void setCity(string city);
void setFrequence(string frequence);
};