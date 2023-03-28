//영역구하기
//https://www.acmicpc.net/problem/2583

#include<iostream>
#include<string>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;
using ll = long long;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int MAP[101][101];
int visit[101][101];
int M, N, K;

multiset<int>res;

void bfs(int num1, int num2) {
	queue<pair<int, int>>q;
	q.push({ num1,num2 });
	visit[num1][num2] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!visit[xx][yy] && !MAP[xx][yy] && xx >= 0 && yy >= 0 && xx < M && yy < N) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				++cnt;
			}
		}
	}
	res.insert(cnt);
}

int main() {
	cin >> M >> N >> K;
	int x, xx;
	int y, yy;
	int cnt = 0;
	for (int k = 0; k < K; k++)
	{
		cin >> x >> y >> xx >> yy;

		for (int i = y; i < yy; i++)
		{
			for (int j = x; j < xx; j++)
			{
				MAP[i][j] = true;
			}
		}
	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!MAP[i][j] && !visit[i][j]) {
				bfs(i, j);
				++cnt;
			}
		}
	}

	cout << cnt << endl;
	for (auto a : res) {
		cout << a << " ";
	}
}
