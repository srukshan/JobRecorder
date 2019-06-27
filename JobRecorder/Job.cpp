#include "Job.h"

Job::Job()
{
}

Job::Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate)
{
}

Job::Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate)
{
}

Job::Job(int ownerNumber, string address, int telNum, string phoneModel, int phoneSerialNum, string recievedDate, string deliveredDate, double price)
{
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
