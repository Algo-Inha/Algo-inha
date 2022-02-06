//https://www.acmicpc.net/problem/4179
//불!
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int r, c;
int maxnum = 999999999;
int map[1000][1000];
queue<pair<int, int>> q1;
queue<int> q2;
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};

void bfs() {
	while (!q1.empty()) {
		int y = q1.front().first;
		int x = q1.front().second;
		int state = q2.front();
		q1.pop();
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dy >= r || dx < 0 || dx >= c) continue;
			if (map[dy][dx] == 'F' || map[dy][dx] == '#') continue;
			if (map[dy][dx] < state && map[dy][dx] != '.') continue;

			if (state == 'F') {
				map[dy][dx] = 'F';
				q2.push(state);
			}
			else {
				map[dy][dx] = state + 1;
				if (dy == 0 || dx == 0 || dy == (r - 1) || dx == (c - 1)) {
					maxnum = map[dy][dx];
					return;
				}
				q2.push(map[dy][dx]);
			}
			q1.push(make_pair(dy, dx));
			
		}
	}
}


int main() {

	cin >> r >> c;
	char temp;
	int j1, j2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> temp;
			map[i][j] = (int)temp;
			if (temp == 'J') {
				j1 = i;
				j2 = j;
			}
			if (temp == 'F') {
				q1.push(make_pair(i, j));
				q2.push('F');
			}
		}
	}
	
	q1.push(make_pair(j1, j2));
	q2.push('J');

	bfs();

	//for (int i = 0; i < r; i++) {
	//	for (int j = 0; j < c; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	if (maxnum == 999999999) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << maxnum-'J'+1 << endl;
	}

	return 0;
}

// 이문제가 왜 메모리초과가 나는지 이해할 수 없다.