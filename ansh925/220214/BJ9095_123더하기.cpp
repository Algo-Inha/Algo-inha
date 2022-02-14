// https://www.acmicpc.net/problem/9095
#include<iostream>
using namespace std;

int n, N;
int cnt = 0;
int num[12] = { 0, };

int main()
{
	num[1] = 1;		// 1
	num[2] = 2;		// 1+1, 2
	num[3] = 4;		// 1+1+1, 1+2, 2+1, 3
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		cin >> N;

		for (int i = 4; i <= N; i++)
		{
			num[i] = num[i - 1] + num[i - 2] + num[i - 3];		// Á¡È­½Ä
		}
		cout << num[N] << endl;
	}
	return 0;
}