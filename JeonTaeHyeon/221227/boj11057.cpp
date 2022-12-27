//오르막 수
//https://www.acmicpc.net/problem/11057
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>
using namespace std;

int dp[10][1001];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dp[9][i] = 1;
	}

	for (int i = 0; i < 10; i++)
	{
		dp[i][1] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 8; j >= 0; j--)
		{
			dp[j][i] = dp[j + 1][i] % 10007 + dp[j][i - 1] % 10007;
		}
	}
	long long res = 0;
	for (int i = 0; i <= 9; i++)
	{
		res += dp[i][n] % 10007;
	}

	cout << res % 10007;

}