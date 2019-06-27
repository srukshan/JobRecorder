#pragma once
#include <string>
using namespace std;

class Job
{
private:
	static int currentMaxId;
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
	int getOwnerNumber();
	void setOwnerNumber(int ownerNumber);
	int getTelNum();
	void setTelNum(int telNum);
	string getPhoneModel();
	void setPhoneModel(string phoneModel);
	int getPhoneSerialNum();
	void setPhoneSerialNum(int phoneSerialNum);
	string getRecievedDate();
	void setRecievedDate(string recievedDate);
	string getDeliveredDate();
	void setDeliveredDate(string deliveredDate);
	double getPrice();
	void setPrice(double price);
	string toString();
};
