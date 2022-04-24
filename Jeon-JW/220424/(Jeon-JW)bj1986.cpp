//https://www.acmicpc.net/problem/1986
//체스
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 0빈곳, 1잡히는 곳, 2퀸, 3나이트, 4폰 // 폰은 없어도 된다.
int map[1000][1000];
int n, m;
vector<pair<int, int>> queen;
vector<pair<int, int>> knight;
int dir[2][8] = {
	{-1,-1,0,1,1,1,0,-1},
	{0,1,1,1,0,-1,-1,-1}
};
int knight_dir[2][8] = {
	{-2,-1,1,2,2,1,-1,-2},
	{1,2,2,1,-1,-2,-2,-1}
};

int main() {

	cin >> n >> m;
	int y, x;
	int num;
	for (int i = 0; i < 3; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> y >> x;
			if (i == 0) {
				queen.push_back(make_pair(y-1, x-1));
				map[y-1][x-1] = 2;
			}
			else if (i == 1) {
				knight.push_back(make_pair(y-1, x-1));
				map[y-1][x-1] = 3;
			}
			else {
				map[y-1][x-1] = 4;
			}
		}
	}

	for (int i = 0; i < queen.size(); i++) {
		int dy = queen[i].first;
		int dx = queen[i].second;
		for (int d = 0; d < 8; d++) {
			for (;;) {
				dy = dy + dir[0][d];
				dx = dx + dir[1][d];

				if (dy < 0 || dx < 0 || dy >= n || dx >= m) break;
				if (map[dy][dx] > 1) break;
				map[dy][dx] = 1;
			}
			dy = queen[i].first;
			dx = queen[i].second;
		}
	}
	for (int i = 0; i < knight.size(); i++) {
		int y = knight[i].first;
		int x = knight[i].second;
		for (int d = 0; d < 8; d++) {
			int dy = y + knight_dir[0][d];
			int dx = x + knight_dir[1][d];

			if (dy < 0 || dx < 0 || dy >= n || dx >= m)continue;
			if (map[dy][dx] > 1) continue;
			map[dy][dx] = 1;
		}
	}

//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < m; j++){
//			cout << map[i][j] << " ";
//}
//		cout << endl;
//}


	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0) ans++;

	cout << ans;

	return 0;
}