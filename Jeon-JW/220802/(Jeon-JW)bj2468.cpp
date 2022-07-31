//https://www.acmicpc.net/problem/2468
//��������
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//���� ����� �ʴ� ������ �����̶� ���� 
//���� ����� �ʴ� �������� 
//��, �Ʒ�, ������ Ȥ�� �������� ������ ������ 
//�� ũ�Ⱑ �ִ��� ������ ���Ѵ�. -> 

int N;
int map[101][101];
int visit[101][101];
int ans = 1;
int cnt;
int max_num;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

void reset_visit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

void dfs(int i, int j, int rain) {
	
	for (int a = 0; a < 4; a++) {
		int dy = i + dir[0][a];
		int dx = j + dir[1][a];

		if (dy < 0 || dx < 0 || dy >= N || dx >= N) continue;
		if (map[dy][dx] <= rain || visit[dy][dx]) continue;

		visit[dy][dx] = 1;
		dfs(dy, dx, rain);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			max_num = max(max_num, map[i][j]);
		}
	}

	for (int rain = 1; rain < max_num; rain++) {
		cnt = 0;
		reset_visit();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > rain && !visit[i][j]) {
					cnt++;
					visit[i][j] = 1;
					dfs(i, j, rain);
				}
			}
		}
		ans = max(ans, cnt);
	}

	cout << ans;

	return 0;
}