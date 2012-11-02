//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "GAUtility.h"

using namespace std;

namespace GAUtility
{
	int ConvertToInt(string toConvert)
	{
		// TODO: Error handling
		stringstream ss(toConvert);
		int ans;
		ss >> ans;
		return ans;
	}

	bool IsNumber(string toCheck)
	{
		if ((toCheck.length() == 1) && (toCheck[0] == '-'))
			return false;
		for (int i = 0; i < toCheck.length(); i++) {
			if (!isdigit(toCheck[i])) 
			{
				if ((i == 0) && (toCheck[i] != '-'))
					return false;
			}
		}
		return true;
	}

	vector<string> SplitString(string toSplit, string delimiter)
	{
		vector<string> returnVector;
		size_t current;
		size_t next = -1;
		string extracted;

		do
		{
			current = next + 1;
			next = toSplit.find_first_of(delimiter,current);
			extracted = GAUtility::TrimSpaces(toSplit.substr(current, next - current));
			returnVector.push_back(extracted);
		}
		while (next != string::npos);

		return returnVector;
	}

	string TrimSpaces(string toTrim)
	{
		size_t startpos, endpos;

		startpos = toTrim.find_first_not_of(" ");
		endpos = toTrim.find_last_not_of(" ");

		if (string::npos != startpos) 
			toTrim.substr(startpos).swap(toTrim);
		if (string::npos != endpos)
			toTrim.substr(0, endpos+1).swap(toTrim);

		return toTrim;
	}
		
	bool OperatorIsBinary(std::string operatorName)
	{
		if ((operatorName == "+") ||
			(operatorName == "-") ||
			(operatorName == "/") ||
			(operatorName == "*") ||
			(operatorName == "^") ||
			(operatorName == "max"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool IsOperatorChar(char input)
	{
		if ((input == '+') | (input == '^') | (input == '-') | (input == '*') | 
			(input == '/') | (input == '(') | (input == ')') | (input == ',') | (input == '='))
				return true;
			else
				return false; 
	}
	
	string SpaceString(string inputString)
	{
		bool insLeft = false;
		string localString = inputString;
		int ir, lsLength;
		bool replace = true;
		
		while (replace) 
		{
			replace = false;
			lsLength = (int)localString.length();
		
			for (int i = 0; i < lsLength; i++)
			{
				if (GAUtility::IsOperatorChar(localString.at(i)))
				{

					// Make the left of the operator a space if it isn't
					if (i > 0)
					{
						if (localString.at(i-1) != ' ')
						{
							localString.insert(i," ");
							insLeft = true;
							replace = true;
						}
					}
					// Make the right of the operator a space if it isn't
					ir = (insLeft) ? i+1 : i;
					if (ir < lsLength-1)
					{
						if (localString.at(ir+1) != ' ')
						{
							// Special case for - negation
							if (ir == 0)
							{
								if (localString.at(ir) != '-')
								{
									localString.insert(ir+1," ");
									replace = true;
								}
							}
							else
							{
								// Special case for - negation
								if ((localString.at(ir) == '-'))
								{ 
									if ((localString.at(ir - 2) == '(') || (localString.at(ir-2) == '=') || (localString.at(ir-2) == ',')) {} else
									{
										localString.insert(ir+1," ");
										replace = true;
									}
								}
								else
								{
									localString.insert(ir+1," ");
									replace = true;
								}
							}
						}
					}
					insLeft = false;
				}
				if (replace) break;
			}
		}
		
		return localString;
	}
	
	double GenerateRandomProbability(int seedMod)
	{
		double ans;
		srand(time(NULL));
		ans = rand()/(7329.1398+(seedMod*5));
		ans = ans - (int)ans;
		return ans;
	}
	
	int GenerateRandomNumber(int min, int max, int seedMod)
	{
		return (int)(min + (GAUtility::GenerateRandomProbability(seedMod) * (max-min)));
	}

}