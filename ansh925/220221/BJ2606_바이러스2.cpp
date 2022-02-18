//https://www.acmicpc.net/problem/2606
#include <iostream>
using namespace std;

int map[101][101] = { 0 };
int check[101] = { 0 };
int n, cnt = 0;

void DFS(int x)
{	
	cnt++;
	check[x] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (map[x][i] && !check[i])
			DFS(i);
	}
}

int main()
{
	int k, a, b;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	DFS(1);
	cout << cnt-1 << endl;
}