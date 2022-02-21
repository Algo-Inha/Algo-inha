//https://www.acmicpc.net/problem/21318
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int cnt[100001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	int N, n, Q;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);

		if (i == 0)
			continue;
		if (v[i - 1] > n)
			cnt[i] = cnt[i - 1] + 1;
		else
			cnt[i] = cnt[i - 1];
	}

	cin >> Q;
	while (Q--)
	{
		int x, y, ans = 0;
		cin >> x >> y;
		ans = cnt[y - 1] - cnt[x - 1];
		cout << ans << '\n';
	}
	return 0;
}