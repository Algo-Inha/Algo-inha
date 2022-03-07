// https://www.acmicpc.net/problem/2206
// �� �μ��� �̵��ϱ�
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int map[1000][1000];
int N, M;
int answer = -1;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
int visited[1000][1000][2];

void bfs() {
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int di = q.front().first.first;
		int dj = q.front().first.second;
		int state = q.front().second;
		q.pop();

		if (di == N - 1 && dj == M - 1) {
			//������ bfs���� ���� ���� ������ ���� ���� ���� ����̴�.
			answer = visited[di][dj][state];
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = di + dir[0][i];
			int nx = dj + dir[1][i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			// ���̰�, ���� �� ���� ��
			if (map[ny][nx] == 1 && state == 1) {
				q.push(make_pair(make_pair(ny, nx), 0));
				visited[ny][nx][0] = visited[di][dj][1] + 1;
			}
			// ���̾ƴϰ� ������ ���� �ʾ��� ��
			else if (map[ny][nx] == 0 && visited[ny][nx][state] == 0) {
				q.push(make_pair(make_pair(ny, nx), state));
				visited[ny][nx][state] = visited[di][dj][state] + 1;
			}
		}
	}
}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			/*cin >> map[i][j];*/
			scanf_s("%1d", &map[i][j]);
		}
	}

	bfs();

	cout << answer;

	return 0;
}