#include "JobController.h"
#include <fstream>

const string FILENAME = "data.txt";

bool JobController::fileExists(std::string name)
{
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

bool JobController::createFile(std::string name)
{
	std::fstream file;
 
	file.open(name, std::ios::out);
 
	if (!file)
	{
		return false;
	}

	file.close();
	return true;
}

bool JobController::insertJob(Job job)
{
	if (!fileExists(FILENAME)) {
		if (!createFile(FILENAME)) {
			return false;
		}
	}
	fstream file;

	file.open(FILENAME, std::ios::app);

	file << job.toString();

	file.close();

	return true;
}

Job JobController::findByID(string id)
{
	if (!fileExists(FILENAME)) {
		return;
	}
	ifstream file(FILENAME);
	if (!file.is_open()) {
		return;
	}
	
	string line;

	while (getline(file,line))
	{
		Job job = Job::toObject(line);
		if (job.getId() == id) {
			file.close();
			return job;
		}
	}
	file.close();
	return;
}
