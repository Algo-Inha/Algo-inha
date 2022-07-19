//BOJ14500 테트로미노
//https://www.acmicpc.net/problem/14500

#include<iostream>
using namespace std;

int map[502][502];
int visit[502][502];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int res;

void dfs(int num1, int num2,int size,int sum) {
	if (size == 4) {
		res = max(res, sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];
		if (x > 0 && y > 0 && x <= n && y <= m && !visit[x][y]) {
			visit[num1][num2] = true;
			dfs(x, y, size + 1, sum + map[x][y]);
			visit[num1][num2] = false;
		}
	}
}

void except(int x, int y) {
	res = max(res, map[x][y] + map[x - 1][y] + map[x][y - 1] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x + 1][y] + map[x][y - 1] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y + 1]);
	res = max(res, map[x][y] + map[x - 1][y] + map[x + 1][y] + map[x][y - 1]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dfs(i, j,1,map[i][j]);
			except(i, j);
		}
	}

	cout << res;
	
}