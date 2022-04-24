//https://www.acmicpc.net/problem/3184
//¾ç
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int R, C;
char map[250][250];
bool visit[250][250];
int sheep, wolf;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = 1;
	int bfs_sheep = 0;
	int bfs_wolf = 0;
	bool flag1 = 0;
	if (map[i][j] == 'v') bfs_wolf++;
	else if (map[i][j] == 'o') bfs_sheep++;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int dy = y + dir[0][a];
			int dx = x + dir[1][a];

			if (map[dy][dx] == '#') continue;
			if (dy < 1 || dx < 1 || dy >= R - 1 || dx >= C - 1) flag1 = 1;
			if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
			if (visit[dy][dx]) continue;

			if (map[dy][dx] == 'v') bfs_wolf++;
			if (map[dy][dx] == 'o') bfs_sheep++;

			q.push(make_pair(dy, dx));
			visit[dy][dx] = 1;
		}
	}

	if (flag1) {
		//cout << i << " " << j << endl;
		return;
	}
	else {
		//¾ç°ú ´Á´ë°¡ Á×´Â ·ÎÁ÷
		if (bfs_sheep > bfs_wolf) sheep += bfs_sheep;
		else wolf += bfs_wolf;
	}
}




int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visit[i][j] || map[i][j] == '#') continue;
			bfs(i, j);
		}
	}

	cout << sheep << " " << wolf;

}