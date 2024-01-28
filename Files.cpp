#include "Files.h"

Files::Files(const char* in, const char* out, const char* log) {
	this->inFile.open(in);
	this->outFile.open(out);
	this->logFile.open(log);
}

Files::~Files() {
	this->inFile.close();
	this->outFile.close();
	this->logFile.close();
}