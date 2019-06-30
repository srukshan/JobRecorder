#pragma once
#include <string>
using namespace std;

class Job
{
private:
	string id;
	int ownerNumber;
	string address;
	string telNum;
	string phoneModel;
	int phoneSerialNum;
	string recievedDate;
	string deliveredDate;
	double price;

public:
	Job();
	Job(string id, int ownerNumber, string address, string telNum, string phoneModel, int phoneSerialNum, string recievedDate);
	Job(string id, int ownerNumber, string address, string telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate);
	Job(string id, int ownerNumber, string address, string telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate, double price);
	string getId();
	void setId(string id);
	string getAddress();
	void setAddress(string address);
	int getOwnerNumber();
	void setOwnerNumber(int ownerNumber);
	string getTelNum();
	void setTelNum(string telNum);
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
	static Job toObject(string source);
};
