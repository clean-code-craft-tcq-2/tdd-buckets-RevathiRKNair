#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include"currentSampleChecker.h"


TEST_CASE("Check validity")
{
	std::vector<int> test_samples = {3,3,5,4,10,11,12};
	REQUIRE(1 == isSampleValid(test_samples));
}

TEST_CASE("Detect sample frequency")
{
	std::vector<int> testSamples = {3,3,5,4,10,11,12};
	T_RangeList testRange = {{1,3},{4,6},{7,8}};
	std::vector<int> expectedReadings = {2,6,4};
	std::vector<int> calcReadings;
	calcReadings = detectFrequency(testSamples, testRange);
	std::cout << "Hello" << std::endl;

	
	REQUIRE(expectedReadings == calcReadings);
	
}

TEST_CASE("Detect current range")
{
	T_RangeList calcRange;
	T_RangeList expectedRange = {{1,3},{4,6},{7,8}};
	std::vector<int> testSamples = {3,3,5,4,10,11,12};
	
	calcRange = detectRanges(testSamples);

	for(int i = 0; i<expectedRange.size(); i++)
	{
		REQUIRE(expectedRange[i]==calcRange[i]);
	}
}

#if 0
TEST_CASE("Testing") 
{
	
	std::vector<int> test_samples = {3,3,5,4,10,11,12};
	std::map<std::string,int> expectedRange;
	
	currentSampleInputs(test_samples);
	
	expectedRange.insert(std::pair<std::string,int>("3-5",4));
    expectedRange.insert(std::pair<std::string,int>("10-12",3));
	
    REQUIRE(samplesInRange(3,5) == expectedRange.find("3-5")->second);
	
}
#endif
