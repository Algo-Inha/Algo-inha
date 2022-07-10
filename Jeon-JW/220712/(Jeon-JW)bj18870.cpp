//https://www.acmicpc.net/problem/18870
//좌표압축
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int main() {

	cin >> N;
	long temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v1.push_back(make_pair(temp, i));
	}
	//첫번째 원소기준으로 sort
	sort(v1.begin(), v1.end());
	//v2에는 넣은 순서로 sort하기 위해서 앞으로 땡겨오기.
	v2.push_back(make_pair(v1[0].second, 0));
	int pivot = 0;
	for (int i = 1; i < N; i++) {
		if (v1[i - 1].first == v1[i].first) { // 같은 수일 경우.
			v2.push_back(make_pair(v1[i].second, pivot));
		}
		else { // 다른 수일 경우.
			pivot++;
			v2.push_back(make_pair(v1[i].second, pivot));
		}
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i < N; i++) {
		cout << v2[i].second << " ";
	}
	

	return 0;
}