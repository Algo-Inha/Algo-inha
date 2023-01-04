//https://www.acmicpc.net/problem/1012
//¿Ø±‚≥Û πË√ﬂ
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int T;
int N, M,K;
bool map[50][50];
bool visit[50][50];
int row, col;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

void mapClear() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i,j));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int a = 0; a < 4; a++) {
			int dy = y + dir[0][a];
			int dx = x + dir[1][a];

			if (dy < 0 || dy >= N || dx < 0 || dx >= M)continue;
			if (visit[dy][dx])continue;
			if (!map[dy][dx])continue;

			q.push(make_pair(dy, dx));
			visit[i][j] = 1;
		}
	}
}

int main() {

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		int ans = 0;
		mapClear();
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> col >> row;
			map[row][col] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visit[i][j]) {
					ans++;
					//cout << "---------k" << i << "---------------" << j << endl;
					visit[i][j] = 1;
					bfs(i, j);
				}
			}
		}
		

		cout << ans << endl;
	}



	return 0;
}