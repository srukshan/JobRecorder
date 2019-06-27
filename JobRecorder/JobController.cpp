#include "JobController.h"
#include <fstream>

const string FILENAME = "data.txt";

bool JobController::fileExists(std::string name)
{
	if (FILE * file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
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