//백준 테트리스
//https://www.acmicpc.net/problem/3019
#include<iostream>
#include<string.h>
using namespace std;

int c, p;
int map[105];
int res;
int main() {
	memset(map, 101, sizeof(map));
	cin >> c >> p;
	for (int i = 1; i <= c; i++)
	{
		cin >> map[i];
	}
	for (int i = 1; i <= c; i++)
	{
		if (p == 1) {
			++res;
			if (map[i] == map[i + 1] &&map[i+1] == map[i + 2]&&map[i+2] == map[i + 3])++res;
		}
		if (p == 2) {
			if (map[i] == map[i + 1])++res;
		}
		if (p == 3) {
			if (map[i] == map[i + 1] && map[i + 2] == map[i + 1] + 1)++res;
			if (map[i] == map[i + 1] + 1)++res;
		}
		if (p == 4) {
			if (map[i] == map[i + 1]+1 && map[i + 2] == map[i + 1])++res;
			if (map[i]+1 == map[i + 1])++res;
		}
		if (p == 5) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] + 1 == map[i + 1])++res;
			if (map[i] == map[i + 1] + 1 && map[i + 2] == map[i + 1] + 1)++res;
			if (map[i] == map[i + 1] + 1)++res;
		}
		if (p == 6) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] == map[i + 1])++res;
			if (map[i] + 1 == map[i + 1] && map[i + 1] == map[i + 2])++res;
			if (map[i] == map[i + 1]+2)++res;
		}
		if (p == 7) {
			if (map[i] == map[i + 1] && map[i] == map[i + 2])++res;
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2] + 1)++res;
			if (map[i] + 2 == map[i + 1])++res;
			if (map[i] == map[i + 1])++res;
		}
	}
	cout << res;
}