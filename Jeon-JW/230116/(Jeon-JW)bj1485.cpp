//https://www.acmicpc.net/problem/1485
//정사각형
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;
vector<pair<int, int>> v;

int main() {

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		v.clear();
		int temp1, temp2;
		for (int i = 0; i < 4; i++) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}
		sort(v.begin(), v.end());

		int len1 = abs(v[0].first - v[1].first) + abs(v[0].second - v[1].second);
		int len2 = abs(v[0].first - v[2].first) + abs(v[0].second - v[2].second);
		int len3 = abs(v[3].first - v[1].first) + abs(v[3].second - v[1].second);
		int len4 = abs(v[3].first - v[2].first) + abs(v[3].second - v[2].second);

		int len_a = abs(v[0].first - v[3].first) + abs(v[0].second - v[3].second);
		int len_b = abs(v[1].first - v[2].first) + abs(v[1].second - v[2].second);

		if (len1 == len2 && len2 == len3 && len3 == len4 && len_a == len_b) {
			cout << 1 << endl;
		}
		else cout << 0 << endl;
	}




	return 0;
}