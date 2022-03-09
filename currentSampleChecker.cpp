
#include <vector>
#include <string>
#include <map>

vector<int> current_samples;

void currentSampleInputs(vector<int>& samples)
{
	int sample_size = samples.size();
	for(int i=0; i= samples.size(); i++)
	{
		current_samples.push_back(samples[i]);
	}
}


int samplesInRange(int lowerRange, int upperRange)
{
	return 0;
}
