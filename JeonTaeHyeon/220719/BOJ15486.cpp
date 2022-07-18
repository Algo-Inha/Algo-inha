//15486Ήψ Επ»η2
//https://www.acmicpc.net/problem/15486
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t[1500050];
int p[1500050];
int dp[1500051];
int day;

int main() {
	cin >> day;
	for (int i = 1; i <= day; i++)
	{
		cin >> t[i] >> p[i];
		if (i + t[i] > day+1)p[i] = 0;
	}

	for (int i = day; i >0; i--)
	{
		for (int j = 0; j < t[i]; j++)
		{
			dp[i] = max(dp[i], p[i + j] + dp[i + j + t[i + j]]);
		}
	}

	cout << dp[1];
}