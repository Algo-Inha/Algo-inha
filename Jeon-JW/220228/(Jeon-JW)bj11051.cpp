//https://www.acmicpc.net/problem/11051
//이항 계수 2
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n, k;
int dp[1001][1001];

int main() {

	cin >> n >> k;

	// (n k) = n!/(k!(n-k)!) // 이건 overflow때문에 못쓴다
	// 파스칼의 법칙
	dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 0; j < i; j++) {
			dp[i][j] = dp[i - 1][j-1] + dp[i - 1][j];
			dp[i][j] = dp[i][j] % 10007;
		}
	}

	cout << dp[n][k];

	return 0;
}