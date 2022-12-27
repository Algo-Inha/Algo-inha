//흙길 보수하기
//https://www.acmicpc.net/problem/1911
#include<iostream>
#include<algorithm>
using namespace std;

int n, l;
int cover ;
int cnt;
pair<int, int>puddle[10001];

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		cin >> puddle[i].first >> puddle[i].second;
	}
	sort(puddle, puddle + n);

	for (int i = 0; i < n; i++)
	{
		if (cover < puddle[i].first) {
			cover = puddle[i].first-1;
		}
		else if (cover >= puddle[i].second-1) {
			continue;
		}

		while (cover < puddle[i].second-1) {
			cover += l;
			cnt++;
		}
	}
	cout << cnt;
}