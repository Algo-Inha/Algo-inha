//https://www.acmicpc.net/problem/16926
//배열 돌리기1
#include<iostream>
#include<algorithm>
using namespace std;

int N, M, R;

int map[301][301];
bool flag1 = 0;

//N이 더 작고 짝수인경우
void rotateN() {
	for (int a = 1; a <= N / 2; a++) {
		int temp = map[a][a];

		for (int i = a; i <= M - a; i++) {
			map[a][i] = map[a][i + 1];
		}

		for (int i = a; i <= N - a; i++) {
			map[i][M - a + 1] = map[i + 1][M - a + 1];
		}

		for (int i = M - a + 1; i > a; i--) {
			map[N - a + 1][i] = map[N - a + 1][i - 1];
		}

		for (int i = N - a + 1; i > a; i--) {
			map[i][a] = map[i - 1][a];
		}

		map[a + 1][a] = temp;
	}
}
//M이 더 작고 짝수인경우
void rotateM() {
	for (int a = 1; a <= M / 2; a++) {
		int temp = map[a][a];

		for (int i = a; i <= M - a; i++) {
			map[a][i] = map[a][i + 1];
		}

		for (int i = a; i <= N - a; i++) {
			map[i][M - a + 1] = map[i + 1][M - a + 1];
		}

		for (int i = M - a + 1; i > a; i--) {
			map[N - a + 1][i] = map[N - a + 1][i - 1];
		}

		for (int i = N - a + 1; i > a; i--) {
			map[i][a] = map[i - 1][a];
		}

		map[a + 1][a] = temp;
	}
}


/*
4 4 1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/

int main() {

	cin >> N >> M >> R;
	// N 과 M중 작은 쪽은 짝수이다.

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	if (min(N, M) == N) flag1 = 1;

	if (flag1) {
		for (int i = 0; i < R; i++) {
			rotateN();
		}
	}
	else {
		for (int i = 0; i < R; i++) {
			rotateM();
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}