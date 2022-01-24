// https://www.acmicpc.net/problem/7576
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int m, n;
int map[1001][1001];
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};
queue<pair<int, int>> q;

//동시에 각 익지않은 토마토 시점부터 시작해서 하나씩 늘려가기
void bfs() {
	while (q.empty() == 0) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + dir[1][i];
			int dy = y + dir[0][i];

			if (dx >= m || dy >= n || dx < 0 || dy < 0) continue;
			if (map[dy][dx] != 0) continue;

			map[dy][dx] = map[y][x] + 1;
			q.push(make_pair(dy, dx));
		}
	}
}

//익은 토마토 1, 안익은 0, 없음-1
int main() {

	cin >> m >> n;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) { // queue에 미리 넣어두기(동시에 확인하기 위해서)keypoint
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();


	//for (int i = 0; i < n; i++) { // col
	//	for (int j = 0; j < m; j++) { // row
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	int maxn = 0;
	for (int i = 0; i < n; i++) { // col
		for (int j = 0; j < m; j++) { // row
			//모두 익지 못하는 상황
			if (map[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			// 최소 날짜 계산
			if (map[i][j] > maxn) {
				maxn = map[i][j];
			}
		}
	}

	cout << maxn - 1 << endl;

	return 0;
}