// https://www.acmicpc.net/problem/2624
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][10001];

bool compare(pair<int, int> coin, pair<int, int> num)
{
	return coin > num;
}

int main(void)
{	
	int T, k, coin, num;
	vector <pair<int, int>> v;

	cin >> T >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> coin >> num;
		v.push_back({ coin, num });
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j <= T; j++)
		{
			if (j == 0)
				dp[i][j] = 1;
			else if (i == 0)
			{
				if (j % v[i].first == 0 && j / v[i].first <= v[i].second)
					dp[i][j] = 1;
			}
			else
			{
				for (int k = 0; k <= v[i].second; k++)
				{
					if (k * v[i].first > j)
						break;
					else
						dp[i][j] += dp[i - 1][j - k * v[i].first];
				}
			}
		}
	}
	cout << dp[k-1][T] << endl;
}