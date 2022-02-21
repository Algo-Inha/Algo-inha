//https://www.acmicpc.net/problem/2606
#include <iostream>
#include <vector>
using namespace std;

vector <int> v[101];
bool check[101];
int cnt = 0;

void DFS(int x)
{
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (check[y] != true)
		{
			DFS(y);
			cnt++;
		}
	}
}

int main()
{
	int n, k, a, b;

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	cout << cnt << endl;
}