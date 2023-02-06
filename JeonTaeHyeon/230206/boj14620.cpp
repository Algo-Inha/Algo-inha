//²É±æ
//https://www.acmicpc.net/problem/14620

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int map[11][11];
bool visit[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int flower;
int money;
int min_ = 123123123;
int n;

void revisit(int num1, int num2) {
	visit[num1][num2] = false;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = false;
	}
}

void makevisit(int num1, int num2) {
	visit[num1][num2] = true;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = true;
	}
}

int bfs(int num1, int num2) {
	int sum = map[num1][num2];

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];
		if (x >= 1 && y >= 1 && x <= n && y <= n && !visit[x][y]) {
			sum += map[x][y];
		}
		else {
			sum = -1;
			return sum;
		}
	}
	makevisit(num1, num2);
	return sum;
}

void res() {
	if (flower == 3) {
		min_ = min(min_, money);
		return;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j < n; j++)
		{
			if (!visit[i][j]) {
				int m = bfs(i, j);
				if (m >= 0) {
					money += m;
					flower++;
					res();
					money -= m;
					flower--;
					revisit(i, j);
				}
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	res();

	cout << min_;
}