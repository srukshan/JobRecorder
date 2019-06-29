#pragma once
#include <iostream>
#include "Job.h"
#include <vector>

class JobController
{
private:
	bool fileExists(std::string name);
	bool createFile(std::string name);

public:
	bool insertJob(Job job);
	Job findByID(string id);
	bool updateJob(Job job);
	vector<Job> getAll();
	bool deleteJob(Job job);
};

