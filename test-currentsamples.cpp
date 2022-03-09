#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"

#include"currentSampleChecker.h"



TEST_CASE("Testing") 
{
	
	vector<int> test_samples = {3,3,5,4,10,11,12};
	map<string,int> expectedRange;
	
	currentSampleInputs(test_samples);
	
	expectedRange.insert(pair<string,int>("3-5",4));
    expectedRange.insert(pair<string,int>("10-12",3));
	
    REQUIRE(samplesInRange(3,5) == expectedRange.find("3-5")->second)
	
}
