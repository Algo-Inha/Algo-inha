#include<iostream>
#include<algorithm>
#include<queue>
#define _size 51
using namespace std;

int map[_size][_size];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, l, r;
int open[_size][_size];
int visit[_size][_size];
queue<pair<int, int>> q;
int day;

void bfs(int num1, int num2) {
	int cnt = 1;
	int sum = map[num1][num2];
	visit[num1][num2] = true;
	q.push({ num1,num2 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && yy > 0 && xx <= n && yy <= n && abs((map[x][y] - map[xx][yy])) >= l && abs((map[x][y] - map[xx][yy])) <= r && !visit[xx][yy]) {
				visit[xx][yy] = true;
				open[xx][yy] = true;
				cnt++;
				sum += map[xx][yy];
				q.push({ xx,yy });
			}
		}
	}
	sum /= cnt;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (open[i][j]) {
				map[i][j] = sum;
				open[i][j] = false;
			}
		}
	}

}


int openwall() {
	int check = false;
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
				for (int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];
					if (!visit[i][j]){
						if (x > 0 && y > 0 && x <= n && y <= n && abs((map[i][j] - map[x][y])) >= l && abs((map[i][j] - map[x][y])) <= r)
						{
							open[i][j] = true;
							bfs(i, j);
							check = true;
						}
					}
					
				}
		}
	}
	for (int i = 1; i <=n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			visit[i][j] = false;
		}
	}
	++day;
	return check;
}



int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}


	while (openwall()) {

	}

	cout << day-1;
}
