//https://www.acmicpc.net/problem/1245
//丑厘 包府
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dir[2][8] = {
	{-1,-1,0,1,1,1,0,-1},{0,1,1,1,0,-1,-1,-1}
};
int map[101][101];
bool visit[101][101];

int N, M;
int cnt;
bool flag;


void dfs(int y, int x) {
	for (int i = 0; i < 8; i++) {
		int dy = y + dir[0][i];
		int dx = x + dir[1][i];

		if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;
		
		// 豪快府老 版快父
		if (map[y][x] < map[dy][dx]) flag = 0;
		if (visit[dy][dx])continue;
		if (map[y][x] == map[dy][dx]) {
			visit[dy][dx] = 1;
			dfs(dy, dx);
		}
	}

}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0) {
				flag = 1;
				visit[i][j] = 1;
				dfs(i, j);
				if (flag) cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}