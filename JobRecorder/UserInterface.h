#pragma once
#include <tuple>
#include <iostream>
#include "Job.h"
#include <vector>

using namespace std;

class UserInterface
{
public:
	tuple<string, string> displayLogin();
	void displayErrorNPause(string);
	int displayMainMenu();
	void displayCompanyDetails();
	Job displayAddJob();
	string displayGetId();
	bool displayUpdate(Job* job);
	void displayJob(vector<Job> jobs);
	void displayJob(Job job);
	bool displayDecision(string reason);

private:
	void displayHeader();
	void displaySimpleJob(Job job);
};

