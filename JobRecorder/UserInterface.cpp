#include "UserInterface.h"
#include <stdlib.h>
#include "Job.h"
#include <vector>

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
		cout << "\tDelivered Date\t:\t";
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
		cout << "\tPrice\t\t:\t";
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
	char c;
	int input;
	displayHeader();
	cout << "                            Update Job" << endl << endl;
	cout << "\t1. ID\t\t:\t" << job->getId() << endl;
	cout << "\t2. Owner Number\t:\t" << job->getOwnerNumber() << endl;
	cout << "\t3. Address\t:\t" << job->getAddress() << endl;
	cout << "\t4. Telphone Number\t:\t" << job->getTelNum() << endl;
	cout << "\t5. Phone Model\t:\t" << job->getPhoneModel() << endl;
	cout << "\t6. Phone Serial Number\t:\t" << job->getPhoneSerialNum() << endl;
	cout << "\t7. Recieved Date\t:\t" << job->getRecievedDate() << endl;
	cout << "\t8. Delivered Date\t:\t" << job->getDeliveredDate() << endl;
	cout << "\t9. Price\t:\t" << job->getPrice() << endl;
	cout << "\t0. Save and Exit" << endl;

	cout << "Select an option : ";
	cin >> input;

	switch (input) {
	case 1: {
		displayHeader();
		cout << "                             Update ID" << endl << endl;
		cout << "\tOld ID\t:\t" << job->getId() << endl;
		cout << "\tNew ID\t:\t";
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		string id;
		getline(cin, id);
		job->setId(id);
		system("PAUSE");
		return true;
	}
	case 2: {
		displayHeader();
		cout << "                        Update Owner Number" << endl << endl;
		cout << "\tOld Owner Number\t:\t" << job->getOwnerNumber() << endl;
		cout << "\tNew Owner Number\t:\t";
		int in;
		cin >> in;
		job->setOwnerNumber(in);
		system("PAUSE");
		return true;
	}
	case 3: {
		displayHeader();
		cout << "                           Update Address" << endl << endl;
		cout << "\tOld Address\t:\t" << job->getAddress() << endl;
		cout << "\tNew Address\t:\t";
		string in;
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		getline(cin, in);
		job->setAddress(in);
		system("PAUSE");
		return true;
	}
	case 4: {
		displayHeader();
		cout << "                      Update Telephone Number" << endl << endl;
		cout << "\tOld Telephone Number\t:\t" << job->getTelNum() << endl;
		cout << "\tNew Telephone Number\t:\t";
		int in;
		cin >> in;
		job->setTelNum(in);
		system("PAUSE");
		return true;
	}
	case 5: {
		displayHeader();
		cout << "                        Update Phone Model" << endl << endl;
		cout << "\tOld Phone Model\t:\t" << job->getPhoneModel() << endl;
		cout << "\tNew Phone Model\t:\t";
		string in;
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		getline(cin, in);
		job->setPhoneModel(in);
		system("PAUSE");
		return true;
	}
	case 6: {
		displayHeader();
		cout << "                  Update Phone Serial Number" << endl << endl;
		cout << "\tOld Phone Serial Number\t:\t" << job->getPhoneSerialNum() << endl;
		cout << "\tNew Phone Serial Number\t:\t";
		int in;
		cin >> in;
		job->setPhoneSerialNum(in);
		system("PAUSE");
		return true;
	}
	case 7: {
		displayHeader();
		cout << "                      Update Recieved Date" << endl << endl;
		cout << "\tOld Recieved Date\t:\t" << job->getRecievedDate() << endl;
		cout << "\tNew Recieved Date\t:\t";
		string in;
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		getline(cin, in);
		job->setRecievedDate(in);
		system("PAUSE");
		return true;
	}
	case 8: {
		displayHeader();
		cout << "                     Update Delivered Date" << endl << endl;
		cout << "\tOld Delivered Date\t:\t" << job->getDeliveredDate() << endl;
		cout << "\tNew Delivered Date\t:\t";
		string in;
		while (cin.get(c) && c != '\n')
			if (!std::isspace(c))
			{
				std::cerr << "ERROR unexpected character '" << c << "' found\n";
				exit(EXIT_FAILURE);
			}
		getline(cin, in);
		job->setDeliveredDate(in);
		system("PAUSE");
		return true;
	}
	case 9: {
		displayHeader();
		cout << "                          Update Price" << endl << endl;
		cout << "\tOld Price\t:\t" << job->getPrice() << endl;
		cout << "\tNew Price\t:\t";
		double in;
		cin >> in;
		job->setPrice(in);
		system("PAUSE");
		return true;
	}
	default:
		return false;
	}
}
void UserInterface::displayJob(Job job)
{
	displayHeader();
	cout << "                             View Job" << endl << endl;
	displaySimpleJob(job);
	system("PAUSE");
}

void UserInterface::displayJob(vector<Job> jobs)
{
	displayHeader();
	cout << "                             View Jobs" << endl << endl;
	for (Job job : jobs) {
		displaySimpleJob(job);
	}
	system("PAUSE");
}


void UserInterface::displayHeader()
{
	system("CLS");
	cout << "**************************************************************" << endl << endl;
	cout << "                   Welcome To Job Recorder" << endl << endl;
	cout << "**************************************************************" << endl << endl;
}

void UserInterface::displaySimpleJob(Job job)
{
	cout << "\tID\t\t:\t" << job.getId() << endl;
	cout << "\tOwner Number\t:\t" << job.getOwnerNumber() << endl;
	cout << "\tAddress\t:\t" << job.getAddress() << endl;
	cout << "\tTelphone Number\t:\t" << job.getTelNum() << endl;
	cout << "\tPhone Model\t:\t" << job.getPhoneModel() << endl;
	cout << "\tPhone Serial Number\t:\t" << job.getPhoneSerialNum() << endl;
	cout << "\tRecieved Date\t:\t" << job.getRecievedDate() << endl;
	cout << "\tDelivered Date\t:\t" << job.getDeliveredDate() << endl;
	cout << "\tPrice\t:\t" << job.getPrice() << endl << endl;
	
}

bool UserInterface::displayDecision(string reason) {
	displayHeader();
	cout << "Do you want to " << reason << "? (y/n)";
	char in;
	cin >> in;
	if (in == 'y') {
		return true;
	}
	return false;
}