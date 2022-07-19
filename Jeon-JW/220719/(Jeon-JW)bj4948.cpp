//https://www.acmicpc.net/problem/4948
//베르트랑 공준
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
//소수는 에라토스테네스의 체
int arr[246913]; // n의 범위 123456


int main() {

	//사전작업
	for (int i = 0; i < 246914; i++) {
		arr[i] = i;
	}

	//에라토스테네스의 체
	for (int i = 2; i <= 246913; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 246913; j += i) {
			arr[j] = 0;
		}
	}

	for (;;) {
		cin >> n;
		if (n == 0) return 0;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}