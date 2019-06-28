
#include <iostream>
#include "UserInterface.h"
#include "JobRecorder.h"
#include "Job.h"
#include "JobController.h"

int main()
{
	UserInterface ui;
	JobController controller;
	bool loggedIn = false;
	bool done = false;

	while (!done)
	{
		while (!loggedIn) {
			tuple<string, string> loginDetails = ui.displayLogin();
			if ((get<0>(loginDetails) == "admin") && (get<1>(loginDetails) == "admin")) {
				loggedIn = true;
			}
			else {
				ui.displayErrorNPause("Username or Password Doesn't Match");
			}
		}
		int options = ui.displayMainMenu();
		
		/*
	cout << "\t1. View Company Details" << endl;
	cout << "\t2. Add Job" << endl;
	cout << "\t3. Update Job" << endl;
	cout << "\t4. Find and View Job" << endl;
	cout << "\t5. Delete Job" << endl;
	cout << "\t6. Logout" << endl;
	cout << "\t0. Exit" << endl << endl;
		*/
		
		switch (options) {
		case 1:
			ui.displayCompanyDetails();
			break;
		case 2:
			Job job = ui.displayAddJob();
			controller.insertJob(job);
			break;
		case 3:
			string id = ui.displayGetId();
			Job job = controller.findByID(id);
			while (ui.displayUpdate(&job));
			controller.updateJob(job);
			break;
		}
	}
}