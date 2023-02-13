//https://www.acmicpc.net/problem/14719
//ºø¹°
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int w, h;
int wh[500];
int left1, right1;
int ans = 0;

int main() {

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> wh[i];
	}

	for (int i = 1; i < w - 1; i++) {
		left1 = 0; right1 = 0;
		for (int j = 0; j < i; j++) left1 = max(left1, wh[j]);
		for (int j = w - 1; j > i; j--) right1 = max(right1, wh[j]);
		ans += max(0, min(left1, right1) - wh[i]);
	}
	cout << ans;

	return 0;
}