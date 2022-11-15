//백준 사탕게임
//https://www.acmicpc.net/problem/3085
#include<iostream>
#include<algorithm>
using namespace std;

char map[51][51];
int res;
int n;

void candycounter() {
	int counter = 0;
	int index = 1;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{

			while (map[x][y] == map[x][y + index]) {
				++counter;
				++index;
			}
			res = max(counter+1, res);
			counter = 0; index = 1;
			while (map[x][y] == map[x + index][y]) {
				++counter;
				++index;
			}
			res = max(counter+1, res);
			counter = 0; index = 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != map[i][j + 1] && map[i + 1][j] != 0) {
				swap(map[i][j],map[i][j + 1]);
				candycounter();
				swap(map[i][j], map[i][j + 1]);
			}

			if (map[i][j] != map[i+1][j]&& map[i + 1][j]!=0) {
				swap(map[i][j], map[i+1][j]);
				candycounter();
				swap(map[i][j], map[i+1][j]);
			}
		}
	}
	cout << res;
}