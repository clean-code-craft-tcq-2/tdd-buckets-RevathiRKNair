#include "currentSampleChecker.h"


std::vector<int> current_samples;

struct Limits
{
	int maxElement;
	int minElement;
};


Limits getUpperandLowerlimits(std::vector<int>& samples)
{
	Limits limit;

	limit.maxElement = *std::max_element(samples.begin(), samples.end());
	
	limit.minElement = *std::min_element(samples.begin(), samples.end());

	return limit;

}

T_RangeList detectRanges(std::vector<int>& samples)
{
	T_RangeList rangList;
    Limits limits = getUpperandLowerlimits(samples);
    for (int i = limits.minElement; i < limits.maxElement; )
    {
        rangList.push_back(std::make_pair(i,(i+2)));
        i=i+2;
    }
  
 return rangList;
}

T_Readings detectFrequency(std::vector<int>& samples, T_RangeList CurrentRange)
{
	int frequencyCount = 0;
	std::vector<int> noOfReadings;

	for(int i=0; i= samples.size(); i++)
	{
		for(std::vector<int>::iterator it = samples.begin(); it != current_samples.end(); ++it)
		{
			if(*it >=CurrentRange[i].first && *it <= CurrentRange[i].second)
			{
				frequencyCount++;
			}
		}
		noOfReadings.push_back(frequencyCount);
		frequencyCount = 0;
	}

	return noOfReadings;

}

bool isSampleValid(std::vector<int>& samples)
{
	std::cout << "hhere0"<<std::endl;
	if(!samples.size())
	{
		std::cout << "hhere1"<<std::endl;
		return false;
	}
	else
	{
		for(std::vector<int>::iterator it = samples.begin(); it != current_samples.end(); ++it) 
		{
			if(-1 >= *it)
			{
				std::cout << *it<<std::endl;
				return false;
			}
	
		}	
	}
	return true;
}

std::string printInCsv(T_RangeList range,std::vector<int> readings)
{
	std::string outputString = "Range, Readings";
    for (int i=0; i<range.size(); i++) {
        outputString += "\n" + std::to_string(range[i].first) + "-"+std::to_string(range[i].first)+ ", " + std::to_string(readings[i]);
    }
	std::cout << outputString << std::endl;
    return outputString;
}


void checkTheRangeAndReadings(std::vector<int> sequence)
{
	T_RangeList range;
	std::vector<int> readings;
	

    if(isSampleValid(sequence))
	{
		range = detectRanges(sequence);
		readings = detectFrequency(sequence, range);
		printInCsv(range, readings);
	}
}

