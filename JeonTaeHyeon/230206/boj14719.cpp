//ºø¹°
//https://www.acmicpc.net/problem/14719

#include<iostream>
#include<stack>
using namespace std;

pair<int, int>block;
bool map[501][501];
int rain;
int height;
int h, w;
int main() {
	cin >> h >> w;
	int prev;
	for (int i = 1; i <= w; i++)
	{
		cin >> height;
		for (int j = 500; j >= 500 - height; j--)
		{
			map[j][i] = true;
		}
	}

	for (int i = 500 - h; i <= 500; i++)
	{
		for (int j = 1; j <= w; j++) {
			cout << map[i][j];
		}
		cout << endl;

	}

	for (int i = 500 - h; i <= 500; i++)
	{
		bool block = false;
		int temp = 0;
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j]) {
				if (block) {
					rain += temp;
					temp = 0;
				}
				else block = true;
			}
			else {
				if (block) {
					++temp;
				}
			}
		}
	}
	cout << rain;
}