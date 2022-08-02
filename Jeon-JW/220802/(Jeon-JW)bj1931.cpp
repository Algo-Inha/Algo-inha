//https://www.acmicpc.net/problem/1931
//회의실 배정
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N;
vector<pair<int, int>> I;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

//회의의 최대 개수 -> 빨리끝나는게 장땡
int main() {

	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		I.push_back(make_pair(temp1, temp2));
	}

	sort(I.begin(), I.end(), cmp);
	
	int pivot = I[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (pivot <= I[i].first) {
			cnt++;
			pivot = I[i].second;
		}
	}

	cout << cnt;

	return 0;
}