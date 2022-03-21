#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<algorithm> 

typedef std:: vector<std::pair<int, int> > T_RangeList;
typedef std:: vector<int> T_Readings;


void currentSampleInputs(std::vector<int>& samples);
T_Readings detectFrequency(std::vector<int>& samples, T_RangeList CurrentRange);
T_RangeList detectRanges(std::vector<int>& samples);

bool isSampleValid(std::vector<int>& samples);