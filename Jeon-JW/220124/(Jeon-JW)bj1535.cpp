// https://www.acmicpc.net/problem/1535
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> hea; // 체력
vector<int> hap; // 기쁨
int dp[21][101];//[사람 수][체력]

int main() {
	cin >> n; // 20
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		hea.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		hap.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 99; j++) {
			if (hea[i-1] > j) { // 
				dp[i][j] = dp[i - 1][j];
			}
			else { // max(이전 사람까지 계산했던 (체력, 기쁨), 이전사람(체력-체력,기쁨)+가진기쁨)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - hea[i-1]] + hap[i-1]);
			}
		}
	}

	cout << dp[n][99] << endl;


	return 0;
}