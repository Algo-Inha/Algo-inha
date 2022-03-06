//https://www.acmicpc.net/problem/17144
//미세먼지 안녕!
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int R, C, T;
int map[51][51];
int map_copy[51][51];
vector<pair<int, int>> cleaner;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
int answer = 0;

int main() {

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				cleaner.push_back(make_pair(i, j));
			}
			else {
				answer += map[i][j];
			}
		}
	}
	//cout << answer << endl;
	for (int t = 0; t < T; t++) {
		// 미세먼지 확산
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == -1 || map[i][j] == 0) continue; // 빈곳, 공기청정기 있는 곳
				int dust = map[i][j];
				int dust_delete = 0;
				int dust_spread = dust / 5;
				for (int k = 0; k < 4; k++) {
					int dy = i + dir[0][k];
					int dx = j + dir[1][k];

					if (dy < 0 || dx < 0 || dy >= R || dx >= C) continue;
					if (map[dy][dx] == -1) continue;

					map_copy[dy][dx] += dust_spread;
					dust_delete += dust_spread;
				}
				map_copy[i][j] -= dust_delete;
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == -1) continue;
				map[i][j] = map[i][j] + map_copy[i][j];
				map_copy[i][j] = 0;
			}
		}

		//공기청정기 동작
		answer = answer - map[cleaner[0].first - 1][0] - map[cleaner[1].first + 1][0];
		//위 공기 청정기
		for (int i = cleaner[0].first - 1; i > 0; i--) {
			map[i][0] = map[i - 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			map[0][i] = map[0][i + 1];
		}
		for (int i = 1; i <= cleaner[0].first; i++) {
			map[i - 1][C - 1] = map[i][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			map[cleaner[0].first][i] = map[cleaner[0].first][i - 1];
		}
		map[cleaner[0].first][1] = 0;
		//아래 공기 청정기
		for (int i = cleaner[1].first + 1; i < R - 1; i++) {
			map[i][0] = map[i + 1][0];
		}
		for (int i = 0; i < C - 1; i++) {
			map[R - 1][i] = map[R - 1][i + 1];
		}
		for (int i = R - 1; i >= cleaner[1].first; i--) {
			map[i][C - 1] = map[i - 1][C - 1];
		}
		for (int i = C - 1; i > 1; i--) {
			map[cleaner[1].first][i] = map[cleaner[1].first][i - 1];
		}
		map[cleaner[1].first][1] = 0;
	}

	cout << answer;

	/*for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}