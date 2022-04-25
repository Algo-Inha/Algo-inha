//https://www.acmicpc.net/problem/1932
//Á¤¼ö»ï°¢Çü
#include<iostream>
#include<algorithm>

using namespace std;

int dp[500][500];
int val[500][500];

int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> val[i][j];
		}
	}
	dp[0][0] = val[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + val[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + val[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + val[i][j];
		}
	}
	int max = dp[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (max < dp[n - 1][i]) max = dp[n - 1][i];
	}
	cout << max << endl;
	return 0;
}