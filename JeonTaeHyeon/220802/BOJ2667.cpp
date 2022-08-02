//단지번호 붙이기
//https://www.acmicpc.net/problem/2667
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>
using namespace std;

int dp[91];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int MAP[26][26];
int visit[26][26];
string input[26];
multiset<int> s;

void bfs(int num1, int num2) {
	queue < pair<int, int>>q;
	int cnt = 1;
	q.push({ num1,num2 });
	visit[num1][num2] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!visit[xx][yy] && MAP[xx][yy] && xx >= 0 && yy >= 0 && xx < n && yy < n) {
				visit[xx][yy] = true;
				q.push({ xx,yy });
				++cnt;
			}
		}
	}

	s.insert(cnt);
	cnt = 0;


}


int main() {
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		for (int j = 0; j < n; j++)
		{
			MAP[i][j] = input[i][j] - '0';
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j] && MAP[i][j]) {
				bfs(i, j);
				++cnt;
			}
		}
	}
	cout << cnt << endl;
	for (auto a : s) {
		cout << a << endl;
	}
}
