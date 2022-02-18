//https://www.acmicpc.net/problem/14719
#include <iostream>
#include <vector>
using namespace std;

int main()
{		
	int h, w, ans = 0;
	cin >> h >> w;
	vector<int> v(w);

	for (int i = 0; i < w; i++)
		cin >> v[i];

	for (int i = 1; i < w - 1; i++)
	{
		int left = 0, right = 0;

		for (int j = 0; j < i; j++)
			left = max(left, v[j]);
		for (int j = w - 1; j > i; j--)
			right = max(right, v[j]);

		ans += max(0, min(left, right) - v[i]);
	}

	cout << ans << '\n';
	return 0;
}