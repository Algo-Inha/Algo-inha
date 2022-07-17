//https://www.acmicpc.net/problem/11559
//»Ñ¿ä»Ñ¿ä
#include<iostream>
#include<algorithm>
#include<queue>


using namespace std;

int map[12][6];
int visit[12][6];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs(int i, int j, int value) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	visit[i][j] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		cnt = cnt + 1;
		for (int k = 0; k < 4; k++) {
			int nextx = x + dx[k];
			int nexty = y + dy[k];
			if (nextx >= 0 && nexty >= 0 && nextx < 12 && nexty < 6) {
				if (value == map[nextx][nexty] && visit[nextx][nexty] == 0) {
					visit[nextx][nexty] = 1;
					q.push({ nextx,nexty });
				}
			}
		}
	}
	return cnt;
}

void falling() {
	for (int i = 0; i < 6; i++) {
		int startx2 = 11;
		while (startx2 > 0) {
			if (map[startx2][i] == 0) {
				int startx1 = startx2;
				while (map[startx2][i] == 0 && startx2 > 0)
					startx2 = startx2 - 1;
				map[startx1][i] = map[startx2][i];
				map[startx2][i] = 0;
				startx2 = startx1;
			}
			startx2 = startx2 - 1;
		}
	}
}

int main() {

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char color;
			cin >> color;
			if (color == '.')
				map[i][j] = 0;
			else if (color == 'R')
				map[i][j] = 1;
			else if (color == 'G')
				map[i][j] = 2;
			else if (color == 'B')
				map[i][j] = 3;
			else if (color == 'P')
				map[i][j] = 4;
			else if (color == 'Y')
				map[i][j] = 5;
		}
	}

	int cnt = 0;
	while (1) {
		bool flag = true;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] > 0) {
					for (int k = 0; k < 12; k++)
						for (int l = 0; l < 6; l++)
							visit[k][l] = 0;
					int count = bfs(i, j, map[i][j]);
					if (count >= 4) {
						for (int k = 0; k < 12; k++) {
							for (int l = 0; l < 6; l++) {
								if (visit[k][l] == 1)
									map[k][l] = 0;
							}
						}
						flag = false;
					}
				}
			}
		}
		if (flag == false) {
			cnt = cnt + 1;
			falling();
		}
		else
			break;
	}

	cout << cnt << endl;

	return 0;

}