//https://www.acmicpc.net/problem/11053
//가장 긴 증가하는 부분수열
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int number[1000001];
int main() {
	int N;
	int cnt = 1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> number[i];
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = i - 1; j >= 0; j--)
			if (number[j] < number[i])
				dp[i] = max(dp[i], dp[j] + 1);
		if (dp[i] == 0)
			dp[i] = 1;
	}
	int max_value = 0;
	for (int i = 0; i < N; i++)
		if (max_value < dp[i])
			max_value = dp[i];
	cout << max_value;
}