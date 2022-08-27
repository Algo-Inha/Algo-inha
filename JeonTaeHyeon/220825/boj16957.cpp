#include<iostream>

using namespace std;

int dx[] = { 1,1,1,0,0,-1,-1,-1,0 };
int dy[] = { -1,0,1,1,-1,-1,0,1,0 };

int map[501][501];
int res[501][501];

int r, c;

pair<int, int> cord[501][501];

pair<int, int> makedis(int x, int y) {
	if (cord[x][y].first != 0) {
		return cord[x][y];
	}

	int comp = 999999;
	int cur;

	for (int i = 0; i < 9; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx > 0 && yy > 0 && xx <= r && yy <= c) {
			
			if (comp > map[xx][yy]) {
				comp = map[xx][yy];
				cur = i;
			}
		}
	}

	if (cur == 8) {
		cord[x][y].first = x;
		cord[x][y].second = y;
		return cord[x][y];
	}
	else {
		return cord[x][y] = makedis(x + dx[cur], y + dy[cur]);
	}
}


int main() {
	cin >> r >> c;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cord[i][j] = { 0,0 };
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			makedis(i, j);
			res[cord[i][j].first][cord[i][j].second]++;
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}