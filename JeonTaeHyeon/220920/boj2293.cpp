//백준 동전1
//https://www.acmicpc.net/problem/2293

#include<iostream>

using namespace	std;

int n, k,coin[101],dp[10001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if(j>=coin[i])//j-coin[i]<0이면 컴파일 에러
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
}