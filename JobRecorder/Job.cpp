#include "Job.h"
#include <sstream>

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

int Job::getOwnerNumber()
{
	return ownerNumber;
}

void Job::setOwnerNumber(int ownerNumber)
{
	this->ownerNumber = ownerNumber;
}

int Job::getTelNum()
{
	return telNum;
}

void Job::setTelNum(int telNum)
{
	this->telNum = telNum;
}

string Job::getPhoneModel()
{
	return phoneModel;
}

void Job::setPhoneModel(string phoneModel)
{
	this->phoneModel = phoneModel;
}

int Job::getPhoneSerialNum()
{
	return phoneSerialNum;
}

void Job::setPhoneSerialNum(int phoneSerialNum)
{
	this->phoneSerialNum = phoneSerialNum;
}

string Job::getRecievedDate()
{
	return recievedDate;
}

void Job::setRecievedDate(string recievedDate)
{
	this->recievedDate = recievedDate;
}

string Job::getDeliveredDate()
{
	return deliveredDate;
}

void Job::setDeliveredDate(string deliveredDate)
{
	this->deliveredDate = deliveredDate;
}

double Job::getPrice()
{
	return price;
}

void Job::setPrice(double price)
{
	this->price = price;
}

string Job::toString()
{
	std::ostringstream oss;
	oss << std::to_string(id) << ","
		<< ownerNumber << ","
		<< address << ","
		<< std::to_string(telNum) << ","
		<< phoneModel << ","
		<< std::to_string(phoneSerialNum) << ","
		<< recievedDate << ","
		<< deliveredDate << ","
		<< std::to_string(price) << endl;
	return oss.str();
}
