//9020¹ø °ñµå¹ÙÈåÀÇ ÃßÃø
//https://www.acmicpc.net/problem/9020
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int prime[10001];
int t,n;

int main() {
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (prime[i] == 0) {
			continue;
		}
		for (int j =i*i; j <= 10000; j=j+i)
		{
			prime[j] = 0;
		}
	}

	cin >> t;
	while (t--) {
		int dif = 10001;
		int cur = 0;
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			if (prime[i]) {
				if (prime[n - i]) {
					if (dif > abs(2 * i - n)) {
						dif = abs(2 * i - n);
						cur = i;
					}
				}
			}
		}
		if (cur < n - cur)cout << cur << " " << n - cur<<"\n";
		else { cout << n - cur <<" " << cur<<"\n"; }
	}
}