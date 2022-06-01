//https://www.acmicpc.net/problem/10026
//적록색약
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
char map[101][101];
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
bool visited[101][101];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = y + dir[0][i];
		int dx = x + dir[1][i];

		if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
		if (visited[dy][dx] || map[y][x] != map[dy][dx]) continue;

		dfs(dy, dx);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
			else map[i][j] = map[i][j];
			visited[i][j] = 0;
		}
	}
	
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}