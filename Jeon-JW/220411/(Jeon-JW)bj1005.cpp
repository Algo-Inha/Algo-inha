//https://www.acmicpc.net/problem/1005
//ACM Craft
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int T, N, K, dest;
int time_cost[1001];
int temp1, temp2;
vector<int> v[1001];
int cnt[1001];
int dp[1001];

void init() {
	memset(cnt, 0, sizeof(cnt));
	memset(time_cost, 0, sizeof(time_cost));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 1001; i++) {
		v[i].clear();
	}
}

void func() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) {
			dp[i] = time_cost[i];
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int fr = q.front();
		q.pop();

		for (int j = 0; j < v[fr].size(); j++) {
			int next = v[fr][j];

			cnt[next]--;

			dp[next] = max(dp[next], dp[fr] + time_cost[next]);

			if (cnt[next] == 0) q.push(next);
		}

	}

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		init();

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> time_cost[i];
		}
		for (int i = 1; i <= K; i++) {
			cin >> temp1 >> temp2;
			v[temp1].push_back(temp2);
			cnt[temp2]++;
		}

		cin >> dest;

		func();
		cout << dp[dest] << "\n";
	}

	return 0;
}