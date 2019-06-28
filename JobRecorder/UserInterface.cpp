#include "UserInterface.h"
#include <stdlib.h>
#include "Job.h"

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

Job UserInterface::displayAddJob()
{
	string id;
	int ownerNumber;
	string address;
	int telNum;
	string phoneModel;
	int phoneSerialNum;
	string recievedDate;
	string deliveredDate;
	double price;
	char condition,
		c;

	displayHeader();
	cout << "                            Add Job" << endl << endl;
	cout << "\tid\t\t:\t";
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, id);
	cout << "\tOwner Number\t:\t";
	cin >> ownerNumber;
	cout << "\tAddress\t\t:\t";
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, address);
	cout << "\tTel Number\t:\t";
	cin >> telNum;
	cout << "\tPhone Model\t:\t";
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, phoneModel);
	cout << "\tPhone Serial Number\t:\t";
	cin >> phoneSerialNum;
	cout << "\tRecieved Date\t:\t";
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, recievedDate);

	cout << endl << "\tDo you want to enter the deleivered Date (y/n)";
	cin >> condition;
	if (condition == 'y') {
		cout << "\Delivered Date\t:\t";
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		getline(cin, deliveredDate);
	}
	else {
		system("PAUSE");
		return Job(id,ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate);
	}
	cout << endl << "\tDo you want to enter the price (y/n)";
	cin >> condition;
	if (condition == 'y') {
		cout << "\Price\t\t:\t";
		cin >> price;
	}
	else {
		system("PAUSE");
		return Job(id,ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate, deliveredDate);
	}
	system("PAUSE");
	return Job(id,ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate, deliveredDate, price);
}

string UserInterface::displayGetId()
{
	char c;
	string id;
	displayHeader();
	cout << "                          Find Job By Id" << endl << endl;
	cout << "\tID\t\t:\t";
	while (cin.get(c) && c != '\n')
		if (!std::isspace(c))
		{
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	getline(cin, id);
	system("PAUSE");
	return id;
}

bool UserInterface::displayUpdate(Job* job)
{
	displayHeader();

}

void UserInterface::displayHeader()
{
	system("CLS");
	cout << "**************************************************************" << endl << endl;
	cout << "                   Welcome To Job Recorder" << endl << endl;
	cout << "**************************************************************" << endl << endl;
}

