#pragma once
#include <iostream>
#include "Job.h"

class JobController
{
private:
	bool fileExists(std::string name);
	bool createFile(std::string name);

public:
	bool insertJob(Job job);
	Job findByID(string id);
};

