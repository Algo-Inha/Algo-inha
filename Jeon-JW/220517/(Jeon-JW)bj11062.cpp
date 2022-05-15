//https://www.acmicpc.net/problem/11062
//카드 게임
#include<iostream>
#include<algorithm>

using namespace std;

int N, test_case;
int arr[1001];
int dp[1001][1001][2];

// true면 근우턴
int func(int start, int end, bool turn) {
	int& ans = dp[start][end][turn];
	if (ans != -1) return ans;

	if (start >= end) {
		if (turn) return ans = arr[start];
		else return ans = 0;
	}

	if (turn) { // 근우가 가질 수 있는 최대 점수
		ans = max(func(start + 1, end, !turn) + arr[start], func(start, end - 1, !turn) + arr[end]);
	}
	else { // 명우 입장에서는 근우가 작은 점수를 먹는다.
		ans = min(func(start + 1, end, !turn), func(start, end - 1, !turn));
	}


	return ans;
}

 // 뭔근소리여

int main() {

	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 2; k++) {
					dp[i][j][k] = -1;
				}
			}
		}


		cout << func(0, N - 1, 1) << "\n";
	}


	return 0;
}