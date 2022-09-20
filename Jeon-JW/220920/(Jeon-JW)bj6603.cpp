//https://www.acmicpc.net/problem/6603
//·Î¶Ç
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int k;
bool visit[50];
int S[13];
int ans[6];

void recur(int pivot, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = pivot; i < k; i++) {
		ans[cnt] = S[i];
		recur(i + 1, cnt + 1);
	}
}


int main() {

	for (;;) {
		cin >> k;
		if (k == 0) return 0;
		for (int i = 0; i < k; i++) {
			cin >> S[i];
		}
		recur(0, 0);
		cout << '\n';
	}


	return 0;
}