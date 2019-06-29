
#include <iostream>
#include "UserInterface.h"
#include "JobRecorder.h"
#include "Job.h"
#include "JobController.h"
#include <vector>

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
		{
			Job job = ui.displayAddJob();
			controller.insertJob(job);
		}
			break;

		case 3:
		{
			string id = ui.displayGetId();
			if (id == "") {
				break;
			}
			Job job = controller.findByID(id);
			while (ui.displayUpdate(&job));
			if (!controller.updateJob(job)) {
				ui.displayErrorNPause("Error Updating the Database");
			}
		}
			break;
		case 4:
		{
			string id = ui.displayGetId();
			if (id == "") {
				vector<Job> jobs = controller.getAll();
				if (jobs.size() == 0) {
					ui.displayErrorNPause("No Jobs are available in the Database");
				}
				else {
					ui.displayJob(jobs);
				}
			}
			else {
				Job job = controller.findByID(id);
				if (job.getId() != "") {
					ui.displayJob(job);
				}
				else {
					ui.displayErrorNPause("Job ID entered is invalid");
				}
			}

		}
			break;
		case 5:
		{
			string id = ui.displayGetId();
			if (id == "") {
				ui.displayErrorNPause("Job ID entered is invalid");
				break;
			}
			Job job = controller.findByID(id);
			if ((job.getId() != "") && ui.displayDecision("Delete Job(" + id + ")")) {
				controller.deleteJob(job);
			}
		}
			break;
		case 6:
		{
			if (ui.displayDecision("Log Out")) {
				loggedIn = false;
			}
		}
			break;
		default:
			done = true;
		}
	}
}