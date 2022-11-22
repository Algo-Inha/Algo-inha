//https://www.acmicpc.net/problem/1911
//흙길 보수하기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, L;
vector<pair<int, int>> v;
int ans;


int main() {

	cin >> N >> L;

	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		v.push_back(make_pair(temp1, temp2));
	}

	sort(v.begin(), v.end());

	int pivot = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (pivot >= v[i].second) {
			continue;
		}

		pivot = max(pivot, v[i].first);

		cnt = (v[i].second - pivot - 1) / L + 1;
		ans += cnt;
		pivot += L * cnt;
	}

	cout << ans;

	return 0;
}