//https://www.acmicpc.net/problem/16987
//계란으로 계란치기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N;
int ans;
vector<pair<int, int>> eggs;
int pivot;

void recur(int cnt) {
	if (cnt == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (eggs[i].first <= 0)temp++;
		}
		ans = max(ans, temp);
		return;
	}
	
	//계란이 이미 깨져있을 때 다음으로 넘김.
	if (eggs[cnt].first <= 0) {
		recur(cnt + 1);
		return;
	}

	//못 깰경우
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		if (i == cnt) continue;
		if (eggs[i].first > 0) {
			flag = 1;
			eggs[cnt].first -= eggs[i].second;
			eggs[i].first -= eggs[cnt].second;

			recur(cnt + 1);

			eggs[cnt].first += eggs[i].second;
			eggs[i].first += eggs[cnt].second;
		}
	}

	if (!flag) recur(cnt + 1);
}


int main() {
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		eggs.push_back(make_pair(temp1, temp2));
	}

	recur(0);

	cout << ans;

	return 0;
}