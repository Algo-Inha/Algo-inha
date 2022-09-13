#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[1025][1025] = { 0 };
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2 + 1; i++)
		{
			for (int j = y1; j < y2 + 1; j++)
			{
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}
}