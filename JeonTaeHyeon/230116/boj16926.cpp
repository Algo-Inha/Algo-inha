//배열돌리기
//https://www.acmicpc.net/problem/16926
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>
#define size 301
using namespace std;

int map[size][size];
int n, m;
int r;

void spin(int start, int xend, int yend) {

	for (int i = start; i < xend; i++)
	{
		int temp = map[start][start];
		map[start][start] = map[i + 1][start];
		map[i + 1][start] = temp;
	}
	for (int i = start; i < yend; i++)
	{
		int temp = map[start][start];
		map[start][start] = map[xend][i + 1];
		map[xend][i + 1] = temp;
	}
	for (int i = xend; i > start; i--)
	{
		int temp = map[start][start];
		map[start][start] = map[i - 1][yend];
		map[i - 1][yend] = temp;
	}
	for (int i = yend; i > start; i--)
	{
		int temp = map[start][start];
		map[start][start] = map[start][i - 1];
		map[start][i - 1] = temp;
	}

}


int main() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	while (r--) {
		int comp = min(n, m);

		for (int i = 1; i <= comp - i; i++)
		{
			spin(i, n + 1 - i, m + 1 - i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}