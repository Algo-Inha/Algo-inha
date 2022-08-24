#include<iostream>

using namespace std;

int t, n;
long long dp[10][65];


int main() {
	cin >> t;
	for (int i = 0; i < 10; i++)
	{
		dp[i][1]=1;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[j][i] += dp[k][i - 1];
			}
		}
	}
	while (t--) {
		cin >> n;

		long long res = 0;
		for (int i = 0; i < 10; i++)
		{
			res += dp[i][n];
		}
		cout << res<<"\n";
	}
}