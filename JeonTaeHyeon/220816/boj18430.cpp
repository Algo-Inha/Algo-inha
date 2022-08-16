//무기공학
//https://www.acmicpc.net/problem/18430

#include<iostream>

using namespace std;

int map[5][5];
int visit[5][5];
int n, m;
int res;

int case1(int x, int y){
	int sum = map[x][y] * 2 + map[x][y - 1] + map[x + 1][y];
	return sum;
}
int case2(int x, int y) {
	int sum = map[x][y] * 2 + map[x][y + 1] + map[x + 1][y];

	return sum;
}
int case3(int x, int y) {
	int sum = map[x][y] * 2 + map[x-1][y] + map[x][y-1];
	return sum;
}
int case4(int x, int y) {
	int sum = map[x][y] * 2 + map[x-1][y] + map[x][y+1];
	return sum;
}

bool check1(int x, int y) {
	if (x + 1 < n && y - 1 >=0 && !visit[x + 1][y] && !visit[x][y - 1])return true;
	else return false;
}
bool check2(int x, int y) {
	if (x + 1 < n && y + 1 < m && !visit[x + 1][y] && !visit[x][y + 1])return true;
	else return false;
}
bool check3(int x, int y) {
	if (x -1 >= 0 && y - 1 >= 0 && !visit[x -1][y] && !visit[x][y - 1])return true;
	else return false;
}
bool check4(int x, int y) {
	if (x - 1 >=0 && y + 1 < m && !visit[x - 1][y] && !visit[x][y + 1])return true;
	else return false;
}


void back(int x, int y, int sum) {
	if (y == m) {
		y = 0;
		x++;
	}
	if (x == n) {
		res = max(res, sum);
		return;
	}


	if (!visit[x][y]) {
		if (check1(x,y)) {
			visit[x][y] = true;
			visit[x + 1][y] = true;
			visit[x][y - 1] = true;
			back(x, y+1, sum + case1(x, y));
			visit[x][y] = false;
			visit[x + 1][y] = false;
			visit[x][y - 1] = false;
		}
		if (check2(x, y)) {
			visit[x][y] = true;
			visit[x + 1][y] = true;
			visit[x][y + 1] = true;
			back(x, y+1, sum + case2(x, y));
			visit[x][y] = false;
			visit[x + 1][y] = false;
			visit[x][y + 1] = false;
		}
		if (check3(x, y)) {
			visit[x][y] = true;
			visit[x - 1][y] = true;
			visit[x][y - 1] = true;
			back(x, y+1, sum + case3(x, y));
			visit[x][y] = false;
			visit[x - 1][y] = false;
			visit[x][y - 1] = false;
		}
		if (check4(x, y)) {
			visit[x][y] = true;
			visit[x - 1][y] = true;
			visit[x][y + 1] = true;
			back(x, y+1, sum + case4(x, y));
			visit[x][y] = false;
			visit[x - 1][y] = false;
			visit[x][y + 1] = false;
		}
	}
	back(x, y+1, sum);
	return;
}


int main() {
	cin >> n>> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	back(0, 0, 0);
	cout<< res;
}