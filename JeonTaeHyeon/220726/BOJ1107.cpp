#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;
bool btn[10];
int use[10];
int broken;  
int m,n;
int res = INT_MAX;
int s;
//리모컨
//https://www.acmicpc.net/problem/1107
int main() {
	cin >> n >> m;
	for (int i = 0; i < 10; i++)
	{
		btn[i] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> broken;
		btn[broken] = false;
	}
	res = abs(100 - n);//시작이 100
	for (int i = 0; i <= 999999; i++)
	{
		int possible = true;
		string str = to_string(i);
		int size = str.size();
		for (int j = 0; j < size; j++)
		{
			if (!btn[str[j]-'0']) {//고장난 숫자있으면 건너뛰기
				possible = false;
				break;
			}
		}
		if (possible) {
			int temp = abs(n - i);
			res = min(res, temp + size);
		}
	}
	cout << res;
}