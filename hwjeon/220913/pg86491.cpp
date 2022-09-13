#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;
	int max = 0, min[4] = { 0 }, minmax = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (sizes[i][j] > max) {
				max = sizes[i][j];
			}
		}

		if (sizes[i][0]>sizes[i][1])
		{
			min[i] = sizes[i][1];
		}
		else {
			min[i] = sizes[i][0];
		}
		if (min[i]>minmax)
		{
			minmax = min[i];
		}
	}
	answer = minmax * max;
	return answer;
}