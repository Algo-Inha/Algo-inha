#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;
int n, m;
string s[50];
int map[50][50];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool visit[50][50];
int time[50][50];
int temp;

bool possible(int num1, int num2) {
	if (!map[num1][num2])return false;
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		if (x >= 0 && y >= 0 && x < n && y < m && map[x][y]) {
			cnt++;
		}
	}
	if (cnt > 1)return false;
	else return true;
}

void undo() {
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			time[i][j] = false;
		}
	}
}

void cal(int num1, int num2) {
	visit[num1][num2] = true;
	queue<pair<int, int>>q;
	q.push({ num1,num2 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= 0 && yy >= 0 && xx < n && yy < m && map[xx][yy] && !visit[xx][yy]) {
				visit[xx][yy] = true;
				q.push({ xx,yy });
				time[xx][yy] = time[x][y] + 1;
				temp = max(temp, time[xx][yy]);
			}
		}
	}
	undo();
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];

		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == 'L')map[i][j] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j]) {
				cal(i, j);
			}
		}
	}
	cout << temp;
}