//πÈ¡ÿ æ»≥Á
//https://www.acmicpc.net/problem/1535
#include<iostream>

using namespace std;

int n;
int hp[21];
int p[21];
int res;

void hi(int curhp,int curp,int cur) {
	if (curhp <= 0)return;
	if (cur == n) {
		res = max(res, curp);
		return;
	}

	hi(curhp - hp[cur], curp + p[cur], cur + 1);
	hi(curhp, curp, cur+1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> hp[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	hi(100, 0, 0);
	cout << res;
}