// https://www.acmicpc.net/problem/11051
// 이항 계수 2

#include <iostream>
using namespace std;

int main()
{
	int n, k, ans;
	int nn=1, kk=1;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		nn *= (n - i);
		kk *= (k - i);	
	}
	ans = (nn / kk) % 10007;
	cout << ans << '\n';
}