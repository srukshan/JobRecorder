#include "UserInterface.h"
#include <stdlib.h>

tuple<string, string> UserInterface::displayLogin()
{
	string
		username,
		password;
	displayHeader();
	cout << "                             Login" << endl << endl;
	cout << "\tUsername	: ";
	cin >> username;
	cout << "\tPassword	: ";
	cin >> password;
	return make_tuple(username, password);
}

void UserInterface::displayErrorNPause(string error)
{
	cout << endl << "\t" << error << endl << endl;
	system("PAUSE");
}

int UserInterface::displayMainMenu()
{
	int option = 0;

	displayHeader();
	cout << "                           Main Menu" << endl << endl;
	cout << "\t1. View Company Details" << endl;
	cout << "\t2. Add Job" << endl;
	cout << "\t3. Update Job" << endl;
	cout << "\t4. Find and View Job" << endl;
	cout << "\t5. Delete Job" << endl;
	cout << "\t6. Logout" << endl;
	cout << "\t0. Exit" << endl << endl;

	cout << "\tSelect you an option : ";
	cin >> option;

	if ((option >= 0) && (option <= 6)) {
		return option;
	}
	return displayMainMenu();
}

void UserInterface::displayCompanyDetails()
{
	displayHeader();
	cout << "                      View Company Details" << endl << endl;
	cout << "\tCompany Name\t:\tMobileLine" << endl;
	cout << "\tLocation\t:\tKandy" << endl;
	cout << "\tType\t\t:\tMobile phone repairing center" << endl << endl;

	system("PAUSE");
}

void UserInterface::displayHeader()
{
	system("CLS");
	cout << "**************************************************************" << endl << endl;
	cout << "                   Welcome To Job Recorder" << endl << endl;
	cout << "**************************************************************" << endl << endl;
}
