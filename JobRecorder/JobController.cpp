#include "JobController.h"
#include <fstream>
#include <vector>

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
		return Job();
	}
	ifstream file(FILENAME);
	if (!file.is_open()) {
		return Job();
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
	return Job();
}

bool JobController::updateJob(Job job)
{
	if (!fileExists(FILENAME)) {
		return false;
	}
	ifstream file(FILENAME);
	if (!file.is_open()) {
		return false;
	}

	if (!fileExists("temp_" + FILENAME)) {
		if (!createFile("temp_" + FILENAME)) {
			return false;
		}
	}
	ofstream tempfile("temp_" + FILENAME);

	string line;

	while (getline(file, line))
	{
		Job newjob = Job::toObject(line);
		if (newjob.getId() == job.getId()) {
			tempfile << job.toString();
		}
		else {
			tempfile << newjob.toString();
		}
	}
	file.close();
	tempfile.close();
	remove(FILENAME.c_str());
	if (rename(("temp_" + FILENAME).c_str(), FILENAME.c_str()) != 0) {
		return false;
	}
	return true;
}

vector<Job> JobController::getAll()
{
	vector<Job> jobs;
	if (!fileExists(FILENAME)) {
		return jobs;
	}
	ifstream file(FILENAME);
	if (!file.is_open()) {
		return jobs;
	}
	string line;

	while (getline(file, line))
	{
		Job job = Job::toObject(line);
		jobs.push_back(job);
	}
	file.close();
	return jobs;
}

bool JobController::deleteJob(Job job)
{
	if (!fileExists(FILENAME)) {
		return false;
	}
	ifstream file(FILENAME);
	if (!file.is_open()) {
		return false;
	}

	if (!fileExists("temp_" + FILENAME)) {
		if (!createFile("temp_" + FILENAME)) {
			return false;
		}
	}

	ofstream tempfile("temp_" + FILENAME);

	string line;

	while (getline(file, line))
	{
		Job newjob = Job::toObject(line);
		if (newjob.getId() != job.getId()) {
			tempfile << newjob.toString();
		}
	}
	file.close();
	tempfile.close();
	remove(FILENAME.c_str());
	if (rename(("temp_" + FILENAME).c_str(), FILENAME.c_str()) != 0) {
		return false;
	}
	return true;
}
