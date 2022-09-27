//https://www.acmicpc.net/problem/7562
//나이트의 이동
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


int T, I;
int map[301][301];
int py, px; // 현재위치
int fy, fx; // 최종위치
int cnt;
int dir[2][8]{
	{-2,-1,1,2,2,1,-1,-2},
	{1,2,2,1,-1,-2,-2,-1}
};

void clear_map() {
	for (int i = 0; i <= I; i++) {
		for (int j = 0; j <= I; j++) {
			map[i][j] = 0;
		}
	}
}


void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(py, px));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dx < 0 || dy >= I || dx >= I) continue;

			if (map[dy][dx] == 0) {
				q.push(make_pair(dy, dx));
				map[dy][dx] = map[y][x] + 1;
			}
		}
	}


}



int main() {

	cin >> T;
	
	for (int test_case = 0; test_case < T; test_case++) {

		clear_map();
		cin >> I;
		cin >> py >> px;
		cin >> fy >> fx;

		if (py == fy && px == fx) {
			cout << 0 << '\n';
			continue;
		}

		bfs();
		cout << map[fy][fx] << '\n';
		/*for (int i = 0; i <= I; i++) {
			for (int j = 0; j <= I; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
	}



	return 0;
}