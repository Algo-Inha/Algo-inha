//백준 구간합구하기5
//https://www.acmicpc.net/status?user_id=3991j&problem_id=11660&from_mine=1

#include<iostream>
using namespace std;

int dp[1025][1025];
int m;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] <<"\n";

	}

}