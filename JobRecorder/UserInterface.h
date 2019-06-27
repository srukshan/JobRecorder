#pragma once
#include <tuple>
#include <iostream>
#include "Job.h"

using namespace std;

class UserInterface
{
public:
	tuple<string, string> displayLogin();
	void displayErrorNPause(string);
	int displayMainMenu();
	void displayCompanyDetails();
	Job displayAddJob();

private:
	void displayHeader();
};

