//https://www.acmicpc.net/problem/20006
//랭킹전 대기열
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int p, m, l;
string n;
vector<pair<string,int>> v[300]; // 방


int main() {

	cin >> p >> m;

	for (int i = 0; i < p; i++) {

		cin >> l >> n;

		for (int j = 0; j < p; j++) {// 방찾아가기
			if (v[j].size() == m) continue; // 정원초과
			if (v[j].size() == 0) { v[j].push_back(make_pair(n, l)); break; } // 빈방
			if (v[j][0].second + 10 >= l && v[j][0].second - 10 <= l) {v[j].push_back(make_pair(n, l)); break;} // 들어갈 수 있는 방
		}
	}
	
	int pivot = 0;
	while (v[pivot].size() != 0) {
		if (v[pivot].size() == m) cout << "Started!" << '\n';
		else cout << "Waiting!" << '\n';

		sort(v[pivot].begin(), v[pivot].end());
		for (int i = 0; i < v[pivot].size(); i++) {
			cout << v[pivot][i].second << " " << v[pivot][i].first << '\n';
		}
		pivot++;
	}

	return 0;
}