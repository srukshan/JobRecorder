#pragma once
#include <tuple>
#include <iostream>

using namespace std;

class UserInterface
{
public:
	tuple<string, string> displayLogin();
	void displayErrorNPause(string);
	int displayMainMenu();
	void displayCompanyDetails();

private:
	void displayHeader();
};

