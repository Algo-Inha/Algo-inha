#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
using namespace std;


int s[1001];
int DP[1001];
int n;


int main() {
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (s[i] > s[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
			res = max(DP[i], res);
		}
	}
	cout << res;
}