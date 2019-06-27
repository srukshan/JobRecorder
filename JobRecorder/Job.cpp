#include "Job.h"

Job::Job()
{
	id = ++currentMaxId;
}

Job::Job(
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate) : Job()
{
	this->ownerNumber = ownerNumber;
	this->address = address;
	this->telNum = telNum;
	this->phoneModel = phoneModel;
	this->phoneSerialNum = phoneSerialNum;
	this->recievedDate = recievedDate;
}

Job::Job(
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate,
	string deliveredDate) : Job(ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate)
{
	this->deliveredDate = deliveredDate;
}

Job::Job(
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate,
	string deliveredDate,
	double price) : Job(ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate, deliveredDate)
{
	this->price = price;
}

int Job::getId()
{
	return id;
}

string Job::getAddress()
{
	return address;
}

void Job::setAddress(string address)
{
	this->address = address;
}
