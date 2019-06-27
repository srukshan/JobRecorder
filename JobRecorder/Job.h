#pragma once
#include <string>
using namespace std;

class Job
{
private:
	int id;
	int ownerNumber;
	string address;
	int telNum;
	string phoneModel;
	int phoneSerialNum;
	string recievedDate;
	string deliveredDate;
	double price;

public:
	Job();
	Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate);
	Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate);
	Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate, double price);
	int getId();
	string getAddress();
	void setAddress(string address);

};

