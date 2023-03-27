//신입사원
//https://www.acmicpc.net/problem/1946
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int t;
	cin >> t;

	while (t--) {
		vector <pair<int, int>>v;
		int n;
		cin >> n;
		int x, y;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back({ x,y });
		}
		int cnt = 1;
		sort(v.begin(), v.end());
		int temp = v.front().second;
		for (int i = 1; i < n; i++)
		{
			if (v[i].second < temp) {
				cnt++;
				temp = v[i].second;
			}
		}
		cout << cnt << endl;
		cnt = 0;
		v.clear();
	}
}