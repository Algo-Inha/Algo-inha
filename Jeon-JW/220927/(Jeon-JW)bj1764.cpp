//https://www.acmicpc.net/problem/1764
//µË∫∏¿‚
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int N, M;
unordered_map<string, int> m;
string str;
vector<string> ans;

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		m[str]++;
	}

	for (auto item : m) {
		if (item.second == 2) {
			ans.push_back(item.first);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}