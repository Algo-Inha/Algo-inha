//��Ÿ����Ʈ
//https://www.acmicpc.net/problem/1495
#include<iostream>

using namespace std;

int n, s, m;
int vol	[51];
bool dp[51][1001];
int res=-1;

//void back(int sum, int cur) {
//	if (sum<0 || sum>m) {
//		return;
//	}
//	if (cur == n) {
//		res =max(res, sum);
//		return;
//	}
//	back(sum + vol[cur], cur + 1);
//	back(sum - vol[cur], cur + 1);
//}
//
//
//int main() {
//	cin >> n >> s >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vol[i];
//	}
//	back(s, 0);
//	cout << res;
//}


int main() {
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> vol[i];
	}

	dp[0][s] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j]) {
				if (j + vol[i] <= m)dp[i][j + vol[i]] = true;
				if (j - vol[i] >= 0)dp[i][j - vol[i]] = true;
			}
		}
	}
	//������ 0���� 1000���� ���ĳ��� �ش� �������� �̵������ϸ� true�ƴϸ� false;
	for (int i = 0; i <= 1000; i++)
	{
		if (dp[n][i] == true)res = i;
	}//true�� ������ �߰��� ������ �ʰ� ������ ������ �� ����.
	cout << res;
}