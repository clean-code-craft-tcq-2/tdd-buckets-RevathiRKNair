#include "currentSampleChecker.h"


std::vector<int> current_samples;

struct Limits
{
	int maxElement;
	int minElement;
};

std::string getCsvInfo(T_RangeList range,std::vector<int> readings)
{
	std::string outputString = "Range, Readings";
    for (int i=0; i<range.size(); i++) {
        outputString += "\n" + std::to_string(range[i].first) + "-"+std::to_string(range[i].first)+ ", " + std::to_string(readings[i]);
    }
	
    return outputString;
}

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
	bool validitySatus = 1;

	if(!samples.size())
	{
		
		validitySatus = 0;
	}
	else
	{

		for(int i=0; i<=samples.size(); i++) 
		{
			if(-1 >= samples[i])
			{
				validitySatus = 0;
			}
	
		}	
	}


	return validitySatus;
}




std::string checkTheRangeAndReadings(std::vector<int> sequence)
{
	T_RangeList range;
	std::vector<int> readings;
	std::string csvData = "";

    if(isSampleValid(sequence))
	{
		range = detectRanges(sequence);
		readings = detectFrequency(sequence, range);
		csvData= getCsvInfo(range, readings);
		std::cout << csvData;
	}

	return csvData;
}

