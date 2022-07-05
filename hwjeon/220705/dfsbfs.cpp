#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<int> e[1001];
bool check[1001];

void dfs(int v) {
	check[v] = true;
	cout << v << " ";
	for (int i = 0; i < e[v].size(); i++) {
		int next = e[v][i];
		if (!check[next])
			dfs(next);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < e[cur].size(); i++) {
			int next = e[cur][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V, from, to;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		e[from].push_back(to);
		e[to].push_back(from);
	}

	for (int i = 1; i <= N; i++)
		sort(e[i].begin(), e[i].end());
	dfs(V);
	cout << '\n';
	memset(check, false, sizeof(check));
	bfs(V);

	return 0;
}