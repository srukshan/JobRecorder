#include "Job.h"
#include <sstream>
#include <vector>

Job::Job()
{
	this->id = "";
	this->ownerNumber = 0;
	this->address = "";
	this->telNum = 0;
	this->phoneModel = "";
	this->phoneSerialNum = 0;
	this->recievedDate = "";
	this->deliveredDate = "";
	this->price = 0.0;
}

Job::Job(
	string id,
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate) : Job()
{
	this->id = id;
	this->ownerNumber = ownerNumber;
	this->address = address;
	this->telNum = telNum;
	this->phoneModel = phoneModel;
	this->phoneSerialNum = phoneSerialNum;
	this->recievedDate = recievedDate;
}

Job::Job(
	string id,
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate,
	string deliveredDate) : Job(id, ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate)
{
	this->deliveredDate = deliveredDate;
}

Job::Job(
	string id,
	int ownerNumber,
	string address,
	int telNum,
	string phoneModel,
	int phoneSerialNum,
	string recievedDate,
	string deliveredDate,
	double price) : Job(id, ownerNumber, address, telNum, phoneModel, phoneSerialNum, recievedDate, deliveredDate)
{
	this->price = price;
}

string Job::getId()
{
	return id;
}

void Job::setId(string id)
{
	this->id = id;
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
	oss << id << ","
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

Job Job::toObject(string source)
{
	std::vector<std::string> vars;

	std::stringstream data(source);

	string line;
	while (getline(data,line,','))
	{
		vars.push_back(line);
	}
	return Job(vars[0], stoi(vars[1]), vars[2], stoi(vars[3]), vars[4], stoi(vars[5]), vars[6], vars[7], stod(vars[8]));
}
