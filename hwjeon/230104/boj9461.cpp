#include <iostream>
using namespace std;
int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		long long dp[101];
		dp[0] = dp[1] = dp[2] = dp[3] = 1, dp[4] = dp[5] = 2;
		for (int j = 6; j <= N; j++) {
			dp[j] = dp[j - 1] + dp[j - 5];
		}
		cout << dp[N] << "\n";
	}
	return 0;
}
