//https://www.acmicpc.net/problem/2688
//줄어들지 않아
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int T, n;
long long dp[10][66]; // [맨 앞 자리][자리개수]


int main() {

	cin >> T;

	for (int i = 0; i < 10; i++ ) {
		dp[i][1] = 1;
	}

	for (int i = 1; i < 66; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 9; k >= j; k--) {
				dp[j][i] += dp[k][i - 1]; // 미리 맨앞이 0~9에 대해서 
			}
		}
	}
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		cout << dp[0][n + 1] << endl;
	}


	return 0;
}