//https://www.acmicpc.net/problem/1495
//기타리스트
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, S, M;
int V[51];
int dp[51][1001];
int main() {

	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	dp[0][S] = 1;

	for (int i = 1; i <= N; i++) {
		for(int j = 0; j <= M; j++){
			if (dp[i - 1][j] == 1) {
				if (dp[i - 1][j] == 1) {
					if (j + V[i] <= M) {
						dp[i][j + V[i]] = 1;
					}
					if (j - V[i] >= 0) {
						dp[i][j - V[i]] = 1;
					}
				}
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= M; i++) {
		if (dp[N][i] == 1) {
			answer = max(answer, i);
		}
	}
	cout << answer;

	return 0;
}