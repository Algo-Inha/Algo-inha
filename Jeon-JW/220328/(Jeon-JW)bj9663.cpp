//https://www.acmicpc.net/problem/9663
//N-Queen
#include<iostream>

using namespace std;

int N;
int ans;

bool chess[15][15];
bool visit[15];

bool check(int row, int col) {
	for (int i = 1; i < row+1; i++) {
		int dy = row - i;
		int dx1 = col - i;
		int dx2 = col + i;
		
		if (dx1 >= 0) {
			if (chess[dy][dx1] == 1) return true;
		}
		if (dx2 < N) {
			if (chess[dy][dx2] == 1) return true;
		}
		if (dx1 < 0 && dx2 >= N) return false;
	}
	return false;
}

void recur(int n) {
	if (n == N) {
		ans++;
	}

	for (int i = 0; i < N; i++) {
		//같은 라인에 있을 경우
		if (visit[i]) continue;
		//대각선에 있을 경우
		if (check(n, i)) continue;

		chess[n][i] = 1;
		visit[i] = 1;
		recur(n + 1);
		visit[i] = 0;
		chess[n][i] = 0;
	}
}


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		chess[0][i] = 1;
		visit[i] = 1;
		recur(1);
		visit[i] = 0;
		chess[0][i] = 0;
	}

	cout << ans;

	return 0;
}