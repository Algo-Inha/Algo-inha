//bfs¿Í dfs
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>

using namespace std;

int n, m, v;
vector<int> vec[1001];
int visit[1001];
queue<pair<int, int>> q;


void dfs(int x) {
	visit[x] = true;

	sort(vec[x].begin(), vec[x].end());
	cout << x << " ";
	for (int i = 0; i < vec[x].size(); i++) {
		if (!visit[vec[x][i]]) {
			visit[vec[x][i]] = true;
			dfs(vec[x][i]);
		}
	}

}

void bfs(int x) {
	visit[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int xx = q.front();
		q.pop();
		cout << xx << " ";
		for (int i = 0; i < vec[xx].size(); i++) {
			if (!visit[vec[xx][i]]) {
				visit[vec[xx][i]] = true;
				q.push(vec[xx][i]);
			}
		}
	}

}

int main() {
	cin >> n >> m >> v;
	int num1, num2;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}

	dfs(v);

	memset(visit, NULL, sizeof(visit));
	cout << endl;
	bfs(v);
}