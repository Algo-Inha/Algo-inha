//가장 큰 증가하는 부분수열
//https://www.acmicpc.net/problem/11055
#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int num[1001];
int dp[1001];
int n;
int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (num[i] > num[j]) {
				dp[i] = max(dp[i], dp[j] + num[i]);

			}
		}
		res = max(res, dp[i]);
	}
	cout << res;
}