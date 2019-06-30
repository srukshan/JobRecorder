#include "Validator.h"
#include <regex>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <iostream>

using namespace std;

bool Validator::isPhoneNumber(string telNo)
{
	if ((telNo.length() >= 10) && (regex_match(telNo, regex("^[0-9]+$")))) {
		return true;
	}
	cout << "\t\tInvalid Phone number" << endl;
	return false;
}

bool Validator::isDate(string date)
{
	if (regex_match(date, regex("[0-3][0-9]/[01][0-9]/[0-2][0-9]{3}"))) {
		return true;
	}
	cout << "\t\tInvalid Date Format" << endl;
	return false;
}

bool Validator::isPrice(double price)
{
	if (price >= 0) {
		return true;
	}
	cout << "\t\tInvalid Price" << endl;
	return false;
}

bool Validator::isNotEmpty(string text)
{
	if (trim(text) != "") {
		return true;
	}
	cout << "\t\tFeild is Empty" << endl;
	return false;
}

// trim from start (in place)
void Validator::ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
void Validator::rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
string Validator::trim(std::string s) {
	ltrim(s);
	rtrim(s);
	return s;
}