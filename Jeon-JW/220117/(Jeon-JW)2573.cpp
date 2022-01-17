//https://www.acmicpc.net/problem/2573
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int map[2][301][301];
int n, m; // 행 열
int dir[2][4] = {
	{-1,0,1,0}, {0,1,0,-1}
};
bool visit[301][301];

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = 1;

	while (q.empty() == 0) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int dx = x + dir[0][a];
			int dy = y + dir[1][a];

			if (dx <= 0 || dy <= 0 || dx > n || dy > m) continue;
			if (visit[dx][dy] == 1 || map[0][dx][dy] == 0) continue;

			visit[dx][dy] = 1;
			//cout <<"dxdy" << dx << " " << dy << endl;
			q.push(make_pair(dx, dy));
		}
	}
}

int main() {

	cin >> n >> m;
	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> temp;
			map[0][i][j] = temp;
		}
	}
	int ans = 0;
	int dx, dy;
	int cnt = 0;
	for (int q = 0; q < 100; q++) {
		cnt = 0;
		/*cout << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << map[0][i][j] << " ";

			}
			cout << endl;
		}*/
		//확인하기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[0][i][j] != 0 && visit[i][j] == 0) {
					bfs(i, j);
					cnt++;
					//cout << i << j << endl;
				}
			}
		}
		/*cout << "visit" << cnt << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << visit[i][j] << " ";

			}
			cout << endl;
		}*/

		if (cnt > 1) {
			cout << ans << endl;
			return 0;
		}
		else if (cnt == 0) {
			cout << 0 << endl;
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				visit[i][j] = 0;
			}
		}

		ans++;
		//얼마나 녹을지
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int cnt = 0;
				if (map[0][i][j] != 0) {
					for (int dd = 0; dd < 4; dd++) {
						dx = i + dir[0][dd];
						dy = j + dir[1][dd];

						if (map[0][dx][dy] == 0) cnt++;
					}
					map[1][i][j] = cnt;
				}
			}
		}
		//녹이기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[1][i][j] != 0) {
					map[0][i][j] -= map[1][i][j];
					if (map[0][i][j] < 0) map[0][i][j] = 0;
					map[1][i][j] = 0;
				}
			}
		}

	}

	return 0;
}