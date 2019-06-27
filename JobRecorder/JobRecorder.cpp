
#include <iostream>
#include "UserInterface.h"
#include "JobRecorder.h"

int main()
{
	UserInterface ui;
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
		switch (options) {
		case 1:
			ui.displayCompanyDetails();
			break;
		case 2:

		}
	}
}