//BOJ 1010 다리놓기
//https://www.acmicpc.net/problem/1010
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int dp[31][31];
int t;
int n, m;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		dp[1][1] = 1;
		dp[1][2] = 2;
		dp[2][2] = 1;
		dp[2][3] = 3;

		for (size_t i = 1; i <= 30; i++)
		{
			dp[1][i] = i;
		}
		for (int i = 1; i <= 30; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (!dp[i][j])dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}

		cout << dp[n][m] << "\n";
	}
}