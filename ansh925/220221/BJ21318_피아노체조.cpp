//https://www.acmicpc.net/problem/21318
#include <iostream>
using namespace std;

int N, Q, x, y, cnt = 0;
int difficulty[100001] = { 0 };
int miss[100001] = { 0 };

int main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> difficulty[i];

	for (int i = 1; i <= N; i++)
	{
		if (difficulty[i] > difficulty[i + 1])
			cnt++;
		miss[i + 1] = cnt;
	}

	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		cout << miss[y] - miss[x] << '\n';
	}	
}