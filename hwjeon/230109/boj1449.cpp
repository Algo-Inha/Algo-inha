#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i, j;
	int ans = 1;
	int N, L;
	int list[1001];
	cin >> N >> L;
	for (i = 0; i < N; i++)
		cin >> list[i];
	
	sort(list, list + N);

	int st = list[0];
	for (i = 1; i < N; i++)
	{
		if (list[i] - st + 1 > L)
		{
			ans++;
			st = list[i];
		}
	}

	cout << ans;


	return 0;
}