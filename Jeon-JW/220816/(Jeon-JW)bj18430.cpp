//https://www.acmicpc.net/problem/18430
//무기 공학
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, M;
int map[5][5];
bool visit[5][5];
int answer;
int temp;
 
void func(int y, int x, int sum) {
	if (x == M) {
		x = 0;
		y++;
	}
	if (y == N) {
		/*if (sum > answer) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << visit[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}*/
		answer = max(answer, sum);
		return;
	}
	if (!visit[y][x]) {
		if (y + 1 < N && x - 1 >= 0 && !visit[y + 1][x] && !visit[y][x - 1]) {
			visit[y + 1][x] = 1;
			visit[y][x - 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y + 1][y] + map[y][x - 1];
			func(y, x+1, temp);
			visit[y + 1][x] = 0;
			visit[y][x - 1] = 0;
			visit[y][x] = 0;
		}
		if (y - 1 >= 0 && x - 1 >= 0 && !visit[y - 1][x] && !visit[y][x - 1]) {
			visit[y - 1][x] = 1;
			visit[y][x - 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y - 1][x] + map[y][x - 1];
			func(y, x + 1, temp);
			visit[y - 1][x] = 0;
			visit[y][x - 1] = 0;
			visit[y][x] = 0;
		}
		if (y - 1 >= 0 && x + 1 < M && !visit[y - 1][x] && !visit[y][x + 1]) {
			visit[y - 1][x] = 1;
			visit[y][x + 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y - 1][x] + map[y][x + 1];
			func(y, x + 1, temp);
			visit[y - 1][x] = 0;
			visit[y][x + 1] = 0;
			visit[y][x] = 0;
		}
		if (y + 1 < N && x + 1 < M && !visit[y + 1][x] && !visit[y][x + 1]) {
			visit[y + 1][x] = 1;
			visit[y][x + 1] = 1;
			visit[y][x] = 1;
			temp = sum + (2 * map[y][x]) + map[y + 1][x] + map[y][x + 1];
			func(y, x + 1, temp);
			visit[y + 1][x] = 0;
			visit[y][x + 1] = 0;
			visit[y][x] = 0;
		}
	}
	func(y, x + 1, sum);
}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	if (N < 2 || M < 2) {
		cout << 0;
		return 0;
	}

	func(0, 0, 0);

	cout << answer;

	return 0;
}