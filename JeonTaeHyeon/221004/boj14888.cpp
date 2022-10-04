//백준 연산자 끼워넣기
//https://www.acmicpc.net/problem/14888
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
using namespace std;

int oper[4];
int num[11];
int n;
int res;
int temp[11];
int Max = INT_MIN;
int Min = INT_MAX;

void calc(int cal) {
	Max = max(Max, cal);
	Min = min(Min, cal);
}


void dfs(int x) {
	if (x == n) {
		calc(res);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0 && oper[0]) {
			temp[x] = res;
			oper[i]--;
			res += num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 1 && oper[1]) {
			temp[x] = res;
			oper[i]--;
			res -= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 2 && oper[2]) {
			temp[x] = res;
			oper[i]--;
			res *= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
		if (i == 3 && oper[3]) {
			temp[x] = res;
			oper[i]--;
			res /= num[x];
			dfs(x + 1);
			res = temp[x];
			oper[i]++;
		}
	}


}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	res = num[0];
	dfs(1);

	cout << Max << "\n" << Min;
}