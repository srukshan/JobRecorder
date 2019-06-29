#pragma once
#include <string>

using namespace std;

class Validator
{
public:
	bool isPhoneNumber(int telNo);
	bool isDate(string date);
	bool isPrice(double price);
	bool isNotEmpty(string text);
};

