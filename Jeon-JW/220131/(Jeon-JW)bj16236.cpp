// https://www.acmicpc.net/problem/16236
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

queue<pair<int, int>> q;
int answer = 0;
struct bshark {
	int size = 2; // ũ��
	int in = 0; // ���� ��
	int x, y; // ��� ��ġ
};
bshark bs;

int n;
int map[21][21];
int dist[21][21]; // bfs�� ���ؼ� �ִܰ�� Ȯ���ϱ�
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

bool solution() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			dist[i][j] = -1;
		}
	}
	q.push(make_pair(bs.x, bs.y));
	dist[bs.x][bs.y] = 0;
	//bfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		// �̹� �ּ��� ��� ����
		if (map[x][y] != 9 && map[x][y] != 0 && map[x][y] < bs.size) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[0][i];
			int ny = y + dir[1][i];
			// ���� ��
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			// ������ ���� �ʾҰ�, ���� ���� ������� ��� ���
			if (dist[nx][ny] == -1 && map[nx][ny] <= bs.size) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/

	//�ּ����� �Ÿ� ã��
	int mx = 22;
	int my = 22;
	int md = 401; // �ִ밪���� ū ã�� ���� ���� ���� ����
	// ���� ������ Ȯ��
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (map[i][j] != 0 && map[i][j] != 9 && map[i][j] < bs.size && dist[i][j] != -1 && dist[i][j] <= md) {
				md = dist[i][j];
				mx = i;
				my = j;
			}
		}
	}
	if (md == 401) return 0;
	else {
		map[bs.x][bs.y] = 0;
		bs.x = mx;
		bs.y = my;
		bs.in++;
		if (bs.in == bs.size) {
			bs.in = 0;
			bs.size++;
		}
		map[mx][my] = 9;
		answer = answer + dist[mx][my];
		return 1;
	}
}


int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				bs.x = i;
				bs.y = j;
				/*bs.size = 2;
				bs.in = 0;*/
			}
		}
	}
	for (;;) {
		//queue clear
		while (!q.empty()) {
			q.pop();
		}
		if(!solution()) break;
	}
	cout << answer << endl;
	return 0;
}