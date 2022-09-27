#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dur[8];
int w[8];
int solve(int target)
{
	if (target == n)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
			if (dur[i] <= 0)
				sum++;

		return sum;
	}
	if (dur[target] <= 0)
		return solve(target + 1);

	bool check = false;
	int ret = 0;
	for (int cand = 0; cand < n; ++cand)
	{
		if (target == cand) continue;
		if (dur[cand] <= 0) continue;
		check = true;

		dur[target] -= w[cand];
		dur[cand] -= w[target];

		ret = max(ret, solve(target + 1));

		dur[target] += w[cand];
		dur[cand] += w[target];

	}
	if (!check)
	{
		return solve(target + 1);
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> dur[i] >> w[i];
	}

	cout << solve(0) << "\n";
}