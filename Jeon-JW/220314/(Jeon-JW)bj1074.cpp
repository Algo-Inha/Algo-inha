//https://www.acmicpc.net/problem/1074
//Z
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N, r, c;
int answer = 0;

// 4개로 나누자
void recur(int N, int y, int x) {
	if (y == r && x == c) {
		cout << answer;
		return;
	}
	//cout << N << " " << y << " " << x << endl;
	if (r >= y && r < y + N && c >= x && c < x + N) {
		recur(N >> 1, y, x); // 왼쪽 위
		recur(N >> 1, y, x + (N >> 1)); // 오른쪽 위
		recur(N >> 1, y + (N >> 1), x); // 왼쪽 아래
		recur(N >> 1, y + (N >> 1), x + (N >> 1)); // 오른쪽 아래
	}
	else {
		answer += pow(N, 2);
	}
}


int main() {

	cin >> N >> r >> c;

	//int a = pow(2, N);
	recur(1 << N, 0, 0);

	return 0;
}