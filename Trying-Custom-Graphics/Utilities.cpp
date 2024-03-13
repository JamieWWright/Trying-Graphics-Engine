#include "Utilities.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string LoadFileAsString(std::string filename)
{
	std::ifstream curFile(filename);
	std::stringstream fileContent;

	if (curFile.is_open())
	{
		while (!curFile.eof())
		{
			std::string thisLine;
			std::getline(curFile, thisLine);
			fileContent << thisLine << '\n';
		}
		return fileContent.str();
	}
	else
	{
		std::cout << "Couldn't load: " << filename << " as string";
		return "";
	}

}