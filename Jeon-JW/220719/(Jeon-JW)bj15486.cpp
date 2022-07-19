//https://www.acmicpc.net/problem/15486
//��� 2
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
		// (���� ������ �� �� (���� ���� ������ �� �޴� �� + ���� ��ģ ������ ��))
		else {
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}

	cout << dp[1];

	return 0;
}