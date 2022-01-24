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

//���ÿ� �� �������� �丶�� �������� �����ؼ� �ϳ��� �÷�����
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

//���� �丶�� 1, ������ 0, ����-1
int main() {

	cin >> m >> n;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) { // queue�� �̸� �־�α�(���ÿ� Ȯ���ϱ� ���ؼ�)keypoint
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
			//��� ���� ���ϴ� ��Ȳ
			if (map[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			// �ּ� ��¥ ���
			if (map[i][j] > maxn) {
				maxn = map[i][j];
			}
		}
	}

	cout << maxn - 1 << endl;

	return 0;
}