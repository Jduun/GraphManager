#ifndef FILE_LOGGING
#define FILE_LOGGING
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>

class FileLogging
{
public:
	FileLogging(std::string fileName);
	void Logging(std::string message);

private:
	std::string getTime();
	std::string fileName;
};
#endif