#pragma once
#include <string>

using namespace std;

class Validator
{
private:
	void ltrim(string& s);
	void rtrim(string& s);
	string trim(string s);
public:
	bool isPhoneNumber(string telNo);
	bool isDate(string date);
	bool isPrice(double price);
	bool isNotEmpty(string text);
};

