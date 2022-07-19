//https://www.acmicpc.net/problem/15486
//퇴사 2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int T[1500001];
int P[1500001];
long long dp[1500001];

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
	}

	for (int i = N; i >= 1; i--) {
		if (i + T[i] > N + 1) {
			dp[i] = dp[i + 1];
		}
		// (일을 안했을 때 돈 (현재 일을 마쳤을 때 받는 돈 + 일을 마친 다음날 돈))
		else {
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}

	cout << dp[1];

	return 0;
}