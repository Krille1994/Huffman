#include "FileHandler.h"

#include <iostream>


std::string FileHandler::GetFileText(std::string file_path)
{
	std::string strRetVal;
	std::ifstream file_stream(file_path);
	std::string line;
	while (getline(file_stream, line))
	{
		strRetVal += line;
	}
	return strRetVal;
}
