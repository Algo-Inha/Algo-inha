//https://www.acmicpc.net/problem/2565
//전깃줄
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


vector<pair<int, int>> arr;
int dp[101];
int N;

bool cmp(pair<int, int> a, pair<int, int> b) {
	/*if (a.first < b.first) return true;
	else false;*/
	return a.first < b.first;
}

int main() {

	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		arr.push_back(make_pair(temp1, temp2));
	}

	sort(arr.begin(), arr.end(), cmp);

	int temp_line = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		//이런걸 어떻게 생각하지. -- 연결할 수 있는 가장 많은 전깃줄의 갯수
		for (int j = 0; j < i; j ++ ) {
			if (arr[i].second > arr[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		temp_line = max(temp_line, dp[i]);
	}
	cout << N - temp_line ;


	return 0;
}