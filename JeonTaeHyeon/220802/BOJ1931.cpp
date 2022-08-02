//회의실 배정
//https://www.acmicpc.net/problem/1931
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
using namespace std;


int s[1001];
int DP[1001];
int n;


int main() {
	vector<pair<int, int>>v;

	int n, start, end;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		v.push_back({ end,start });
	}

	sort(v.begin(), v.end());

	int time = v.front().first;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i].second >= time) {
			cnt++;
			time = v[i].first;
		}
	}

	cout << cnt;


}