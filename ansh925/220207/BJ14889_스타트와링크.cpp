//https://www.acmicpc.net/problem/14889 - 스타트와 링크
#include <iostream>
#include <math.h>

using namespace std;

int N;
int ans = 1000000000;
int arr[21][21];
bool check[21];

void DFS(int x, int y)
{
	if (x == N / 2)
	{
		int start=0, link=0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true)
					start += arr[i][j];
				if (check[i] == false && check[j] == false)
					link += arr[i][j];
			}
		}
		int temp = abs(start - link);
		if (ans > temp)
			ans = temp;

		return;
	}

	for (int i = y; i < N; i++)
	{
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	DFS(0, 1);
	cout << ans << endl;
}