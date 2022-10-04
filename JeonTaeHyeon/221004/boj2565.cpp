//น้มุ ภüฑ๊มู
//https://www.acmicpc.net/problem/2565
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n;
pair<int, int>l[101];
int num1, num2;
int dp[101];
int res;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num1>> num2;
		l[i]={num1,num2};
	}
	sort(l, l + n);
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (l[i].second > l[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		res = max(res, dp[i]);
	}
	cout << n-res;

}