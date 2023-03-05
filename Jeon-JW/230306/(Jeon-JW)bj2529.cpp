//https://www.acmicpc.net/problem/2529
//∫ŒµÓ»£
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int K;
char C[10];
bool checkarr[10];
vector<string> ans;

bool check(string num) {
	for (int i = 0; i < K; i++) {
		if (C[i] == '>') {
			if (num[i] < num[i + 1])return false;
		}
		else if (C[i] == '<') {
			if (num[i] > num[i + 1]) return false;
		}
	}
	return true;
}

void recur(int idx, string num) {
	if (idx == K + 1) {
		if (check(num))ans.push_back(num);
		return;
	}
	
	for (int i = 0; i <= 9; i++) {
		if (checkarr[i]) continue;
		checkarr[i] = true;
		recur(idx + 1, num + to_string(i));
		checkarr[i] = false;

	}
}

int main() {

	cin >> K;
	for (int i = 0; i < K; i++) cin >> C[i];
	recur(0, "");
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << endl; 
	cout << ans[0] << endl;



	return 0;
}