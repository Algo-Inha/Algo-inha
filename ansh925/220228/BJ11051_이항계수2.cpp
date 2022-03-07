// https://www.acmicpc.net/problem/11051
// 이항 계수 2

#include <iostream>
using namespace std;

int n, k;
int dp[1001][1001];

int main()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = i;
		dp[i][i] = dp[i][0] = 1;
	}
	for (int i = 3; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}