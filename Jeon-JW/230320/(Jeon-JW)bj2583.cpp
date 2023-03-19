//https://www.acmicpc.net/problem/2583
//영역 구하기
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M, K;
int ans_cnt;
vector<int> ans;
int map[101][101];
int nx1, ny1, nx2, ny2;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
bool visit[101][101];

void bfs(int y, int x) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = ny + dir[0][i];
			int dx = nx + dir[1][i];

			if (dy < 1 || dx < 1 || dy > M || dx > N) continue;
			if (visit[dy][dx]) continue;
			if (map[dy][dx] == 1)continue;

			visit[dy][dx] = 1;
			q.push(make_pair(dy, dx));
			cnt++;
		}
	}

	ans_cnt++;
	ans.push_back(cnt);
}

int main() {

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> nx1 >> ny1 >> nx2 >> ny2;
		for (int j = ny1 + 1; j <= ny2; j++) {
			for (int k = nx1 + 1; k <= nx2; k++) {
				map[j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && map[i][j] == 0) {
				visit[i][j] = 1;
				bfs(i, j);
			}
		}
	}

	cout << ans_cnt << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}