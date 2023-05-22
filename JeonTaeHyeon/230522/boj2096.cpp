//내려가기
//https://www.acmicpc.net/problem/2096

#include <iostream>
#include <algorithm>
using namespace std;

int map[100000][3];
int maximum[2][3];
int minimum[2][3];
bool odd = false;

int n;

int main() {
	cin >> n;
	int num1, num2, num3;

	for (int i = 0; i < n; i++)
	{
		cin >> num1 >> num2 >> num3;
		map[i][0] = num1;
		map[i][1] = num2;
		map[i][2] = num3;
		if (!i) {
			maximum[0][0] = num1;
			maximum[0][1] = num2;
			maximum[0][2] = num3;

			minimum[0][0] = num1;
			minimum[0][1] = num2;
			minimum[0][2] = num3;
		}
		if (i >= 1) {
			odd = !odd;
			maximum[odd][0] = max(maximum[!odd][0] + map[i][0], maximum[!odd][1] + map[i][0]);
			maximum[odd][1] = max(maximum[!odd][0] + map[i][1], max(maximum[!odd][2] + map[i][1], map[i][1] + maximum[!odd][1]));
			maximum[odd][2] = max(maximum[!odd][1] + map[i][2], maximum[!odd][2] + map[i][2]);

			minimum[odd][0] = min(minimum[!odd][0] + map[i][0], minimum[!odd][1] + map[i][0]);
			minimum[odd][1] = min(minimum[!odd][0] + map[i][1], min(minimum[!odd][2] + map[i][1], map[i][1] + minimum[!odd][1]));
			minimum[odd][2] = min(minimum[!odd][1] + map[i][2], minimum[!odd][2] + map[i][2]);

		}
	}

	/*
	res[0][0] = map[0][0];
	res[0][1] = map[0][1];
	res[0][2] = map[0][2];

	for (int i = 1; i < n; i++)
	{
		res[i][0] = max(res[i - 1][0]+map[i][0], res[i - 1][1]+map[i][0]);
		res[i][1] = max(res[i - 1][0] + map[i][1], max(res[i - 1][2]+map[i][1], map[i][1]+res[i - 1][1]));
		res[i][2] = max(res[i - 1][1]+map[i][2], res[i - 1][2]+map[i][2]);
	}
	int maximum = max(res[n - 1][1], max(res[n - 1][0], res[n - 1][2]));

	for (int i = 1; i < n; i++)
	{
		res[i][0] = min(res[i - 1][0] + map[i][0], res[i - 1][1] + map[i][0]);
		res[i][1] = min(res[i - 1][0] + map[i][1], max(res[i - 1][2] + map[i][1], map[i][1] + res[i - 1][1]));
		res[i][2] = min(res[i - 1][1] + map[i][2], res[i - 1][2] + map[i][2]);
	}
	*/

	cout << max(maximum[odd][1], max(maximum[odd][0], maximum[odd][2])) << " " << min(minimum[odd][1], min(minimum[odd][0], minimum[odd][2]));
}