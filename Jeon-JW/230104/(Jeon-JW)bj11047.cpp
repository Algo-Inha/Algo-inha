//https://www.acmicpc.net/problem/11047
//���� 0
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N,K;
long long arr[11];
int ans;

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K >= arr[i]) {
			for (;;) {
				K -= arr[i];
				ans++;
				if (K < arr[i]) break;
			}
		}
	}

	cout << ans;

	return 0;
}

//A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ��� - �̰� ��Ʈ�ε�