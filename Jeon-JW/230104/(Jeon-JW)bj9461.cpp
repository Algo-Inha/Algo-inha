//https://www.acmicpc.net/problem/9461
//파도반 수열
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long dp[101];
int T;
int N[100000];
int num;
int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N[i];
		if (num < N[i]) num = N[i];
	}
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= num; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	for (int i = 0; i < T; i++) {
		cout << dp[N[i]] << endl;
	}




	return 0;
}