//BOJ11559 Puyo Puyo
//https://www.acmicpc.net/problem/11559
#include<iostream>
#include<queue>

using namespace std;

string field[12];
bool visit[12][6];
bool chain=true;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int res;

void gravity() {
	bool move = true;
	while (move) {
		move = false;
		for (int i = 11; i >= 1; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (field[i][j]=='.'&&field[i][j] != field[i - 1][j]) {
					char temp = field[i][j];
					field[i][j] = field[i - 1][j];
					field[i - 1][j] = temp;
					move = true;
				}
			}
		}
	}
	//중력 작용
}

void bfs(int num1 , int num2) {
	int cnt = 1;
	queue<pair<int, int>> q;
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
			if (xx >= 0 && yy >= 0 && xx < 12 && yy < 6 && !visit[xx][yy] && field[x][y] == field[xx][yy]) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				++cnt;
			}
		}
	}

	if (cnt >= 4) {
		for (int i = 0; i < 12; i++)
		{
			for (int j= 0; j < 6; j++)
			{
				if (visit[i][j]) {
					field[i][j] = '.';
				}
			}
		}
		chain=true;
	}
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (visit[i][j]) visit[i][j] = false;
		}
	}

}

int main() {
	for (int i = 0; i < 12; i++)
	{
		cin >> field[i];
	}
	while (chain) {
		chain = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (field[i][j] != '.') {
					bfs(i, j);
				}
			}
		}
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (visit[i][j])visit[i][j] = false;
			}
		}
		if (chain) {
			gravity();
			++res;
		}
		/*for (int i = 0; i < 12; i++)
		{
			cout << field[i] << endl;;
		}*/
	}
	cout << res;
}
/*
--반례--
......
......
......
......
......
......
......
....R.
.Y..P.
.G..PR
RRYYYR
RRGGGR
답 : 3
코드 출력 : 1
2개가 동시에 터질때 한개로 계산해야됨
*/