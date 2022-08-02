//안전영역
//https://www.acmicpc.net/problem/2468
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int h = 0;
int cnt = 0;
queue<pair<int, int>> q;
int map[101][101];
int visit[101][101];


void bfs() {
	cnt = cnt + 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!visit[xx][yy] && xx > 0 && yy > 0 && xx <= n && yy <= n && map[xx][yy] >= h) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
			}
		}


	}
}

int main() {
	int res = 0;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (; h < 101; h++)
	{


		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] >= h && !visit[i][j]) {
					q.push({ i,j });
					visit[i][j] = true;
					bfs();
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				visit[i][j] = NULL;
			}
		}
		res = max(res, cnt);
		cnt = 0;
	}

	cout << res;
}