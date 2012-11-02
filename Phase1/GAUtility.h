//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef GAUTILITY_H
#define GAUTILITY_H

#include <string>
#include <sstream>
#include <vector>

namespace GAUtility 
{
	int ConvertToInt(std::string);
	bool IsNumber(std::string);
	std::vector<std::string> SplitString(std::string toSplit, std::string delimiter);
	std::string TrimSpaces(std::string toTrim);
	bool OperatorIsBinary(std::string operatorName);
	std::string SpaceString(std::string inputString);
}

#endif