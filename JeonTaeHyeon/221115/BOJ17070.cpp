//백준 파이프옮기기1
//https://www.acmicpc.net/problem/17070
#include<iostream>
#include<queue>

using namespace std;

int house[17][17];
int dp[17][17];
int n;

int dx[] = {0,1,1};
int dy[] = {1,1,0};
int res;

void dfs(int num1, int num2) {
	queue<pair<int, pair<int, int>>>q;
	q.push({ num1, { num2,0 } });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int type = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			++res;
			return;
		}

		for (int i = 0; i <3 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			int ttype = i;
			if (abs(type - ttype < 2)) {
				if (xx >= 0 && yy >= 1&&xx<n&&yy<n&&!house[xx][yy]) {



					q.push({ xx,{yy,ttype} });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> house[i][j];
		}
	}

	dfs(0, 1);
	cout << res;
}