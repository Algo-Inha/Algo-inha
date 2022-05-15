//https://www.acmicpc.net/problem/11062
//ī�� ����
#include<iostream>
#include<algorithm>

using namespace std;

int N, test_case;
int arr[1001];
int dp[1001][1001][2];

// true�� �ٿ���
int func(int start, int end, bool turn) {
	int& ans = dp[start][end][turn];
	if (ans != -1) return ans;

	if (start >= end) {
		if (turn) return ans = arr[start];
		else return ans = 0;
	}

	if (turn) { // �ٿ찡 ���� �� �ִ� �ִ� ����
		ans = max(func(start + 1, end, !turn) + arr[start], func(start, end - 1, !turn) + arr[end]);
	}
	else { // ��� ���忡���� �ٿ찡 ���� ������ �Դ´�.
		ans = min(func(start + 1, end, !turn), func(start, end - 1, !turn));
	}


	return ans;
}

 // ���ټҸ���

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