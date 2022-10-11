//https://www.acmicpc.net/problem/14888
//연산자 끼워넣기
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[4]; // 연산자의 개수
int n; // n개의 수 2~11
int num[11]; // 수열
int maxn = -100000001;
int minn = 100000001; // 최대 최소

void re(int ans, int index) {
	if (index == n) {
		if (ans > maxn) maxn = ans;
		if (ans < minn) minn = ans;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (a[i] > 0) {
			a[i]--;
			if (i == 0) re(ans + num[index], index + 1);
			else if (i == 1) re(ans - num[index], index + 1);
			else if (i == 2) re(ans * num[index], index + 1);
			else re(ans / num[index], index + 1);
			a[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	re(num[0], 1);


	cout << maxn << endl << minn << endl;

	return 0;
}