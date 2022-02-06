//https://www.acmicpc.net/problem/2644 - ÃÌ¼ö°è»ê
#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int n, a, b;
int arr[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };
int depth[MAX] = { 0, };
queue<int> q;

void BFS(int x)
{
	q.push(x);
	visited[x] = true;

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for(int i = 1; i <= n; i++)
		{
			if (arr[x][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
				depth[i] = depth[x] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> a >> b;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	BFS(a);

	if (depth[b] == 0)
		cout << -1;
	else
		cout << depth[b];

	return 0;
}