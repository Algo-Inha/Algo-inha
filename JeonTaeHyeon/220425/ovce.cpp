#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#include<string>

#define size 250

using namespace std;

string s[size];
bool visit[size][size];
int r, c;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int res[2];

void bfs(int row,int col) {
	int v = 0;
	int o = 0;
	queue<pair<int, int>>q;
	q.push({ row, col });
	visit[row][col]=true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (s[x][y] == 'v')++v;
		if (s[x][y] == 'o')++o;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && yy >= 0 && xx < r && yy < c && !visit[xx][yy] && s[xx][yy] != '#') {
				visit[xx][yy]=true;
				q.push({ xx,yy });
			}
		}

	}

	if (v >= o) {
		o = 0;
	}
	else {
		v = 0;
	}
	res[0] += o;
	res[1] += v;

}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> s[i];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (s[i][j] == 'v' || s[i][j] == 'o') {
				if (!visit[i][j]) {
					bfs(i, j);
				}
			}
		}
	}

	cout << res[0] << " " << res[1];
	
}