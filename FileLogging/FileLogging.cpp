#include "FileLogging.hpp"

FileLogging::FileLogging(std::string fileName)
{
	this->fileName = fileName;
}

void FileLogging::Logging(std::string message)
{
	std::ofstream fout(fileName, std::ios::out | std::ios::app);
	if (fout.is_open())
	{
		fout << "[" << getTime() << "] " << message << "\n";
	}
	fout.close();
}

std::string FileLogging::getTime()
{
	time_t seconds = time(nullptr);
	tm* timeinfo = localtime(&seconds);
	std::string currTime = asctime(timeinfo);
	currTime.pop_back();
	return currTime;
}