//https://www.acmicpc.net/problem/16957
//체스판 위의 공
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int r, c;

int map[505][505];
int path[505 * 505];
int ans[505 * 505];
queue<int> q;

int dir[2][9] = {
	 { 0, 1, 1, 1, 0, -1, -1, -1, 0 },
	{ 1, 1, 0, -1, -1, -1, 0, 1, 0 }
};
int find(int x) {
	if (x == path[x]) return x;
	return path[x] = find(path[x]);
}

int main() {

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int min = 9999999999;
			int dy = 0;
			int dx = 0;
			for (int k = 0; k < 9; k++) {
				int y = i + dir[0][k];
				int x = j + dir[1][k];

				if (y < 0 || y >= r || x < 0 || x >= c)continue;

				if (min > map[y][x]) {
					min = map[y][x];
					dy = y;
					dx = x;
				}

				//부모표시
				path[i * c + j] = dy * c + dx;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			++ans[find(i * c + j)];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << ans[i * c + j] << " ";
		}
		cout << '\n';
	}

	return 0;
}