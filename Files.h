#pragma once

#include <fstream>

struct Files {

	std::ifstream inFile;
	std::ofstream outFile;
	std::ofstream logFile;

	Files(const char* in = "in.txt", const char* out = "out.txt", const char* log = "log.txt");

	~Files();

};