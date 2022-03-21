#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include"currentSampleChecker.h"


TEST_CASE("Check validity - PASS")
{
	std::vector<int> test_samples = {3,3,5,4,10,11,12};
	REQUIRE(1 == isSampleValid(test_samples));
}

TEST_CASE("Check validity - FAIL")
{
	std::vector<int> test_samples = {3,3,-5,0,10,11,12};
	REQUIRE(0 == isSampleValid(test_samples));
}

TEST_CASE("Detect sample frequency")
{
	std::vector<int> testSamples = {2,3,5,4,1,8,7,7};
	T_RangeList testRange = {{1,3},{4,6},{7,8}};
	std::vector<int> expectedReadings = {2,2,3};
	std::vector<int> calcReadings;
	calcReadings = detectFrequency(testSamples, testRange);

	REQUIRE(expectedReadings == calcReadings);
	
}

TEST_CASE("Detect current range")
{
	T_RangeList calcRange;
	T_RangeList expectedRange = {{1,3},{4,6},{7,8}};
	std::vector<int> testSamples = {2,3,5,4,1,8,7,7};
	
	calcRange = detectRanges(testSamples);

	REQUIRE(expectedRange == calcRange);
	
}


TEST_CASE("Print range in csv") 
{
	
	std::vector<int> testSamples = {2,3,5,4,1,8,7,7};
	
	checkTheRangeAndReadings(testSamples);
	
}

