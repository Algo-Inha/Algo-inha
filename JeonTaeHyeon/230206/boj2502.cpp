//¶±¸Ô´Â È£¶ûÀÌ
//https://www.acmicpc.net/problem/2502

#include<iostream>

using namespace std;

int a, b;
int dp[31];
int d, k;

int fibo(int num) {
	if (dp[num]) {
		return dp[num];
	}
	else if (num <= 2) {
		return dp[num] = 1;
	}
	else return dp[num] = fibo(num - 1) + fibo(num - 2);
}

int main() {
	cin >> d >> k;
	int f1, f2;
	f1 = fibo(d - 2); f2 = fibo(d - 1);
	for (int i = 100000; i > 1; i--)
	{
		if (f2 * i >= k)continue;
		else {
			for (int j = i; j > 1; j--)
			{
				if ((f2 * i + f1 * j) > k)continue;
				else if ((f2 * i + f1 * j) == k) {
					f1 = j; f2 = i;
					goto res;
				}
			}
		}
	}
res:
	cout << f1 << "\n" << f2;
}