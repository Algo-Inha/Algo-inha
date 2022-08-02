//타일 채우기
//https://www.acmicpc.net/problem/2133
#include<iostream>

using namespace std;

int dp[31];
int n;

int main() {
	cin >> n;
	dp[2] = 3;
	dp[0]=1;
	for (size_t i = 4; i <= 30; i+=2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j+=2)
		{
			dp[i] += 2 * dp[i-j];
		}
	}
	cout << dp[n];
}