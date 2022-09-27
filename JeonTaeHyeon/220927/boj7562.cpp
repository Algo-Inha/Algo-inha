//나이트의 이동
// https://www.acmicpc.net/problem/7562
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
using namespace std;

int n;

int dx[] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[] = { -1,1,-2,2,-2,2,-1,1 };
vector<int> v;
queue<pair<int, int>> q;
int visit[300][300];
int cnt[300][300];
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (!visit[xx][yy] && xx >= 0 && yy >= 0 && xx < n && yy < n) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				cnt[xx][yy] = cnt[x][y] + 1;
			}
		}

	}

}



int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n;
		int i, j;
		cin >> i >> j;
		q.push({ i,j });
		visit[i][j] = true;
		bfs();
		cin >> i >> j;
		cout << cnt[i][j] << endl;

		for (int hh = 0; hh < n; hh++)
		{
			memset(visit[hh], NULL, sizeof(visit[hh]));
			memset(cnt[hh], NULL, sizeof(visit[hh]));
		}

	}

}