#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

int visit[100001];
int cnt[100001];
void bfs(int num) {
	queue<int> q;
	q.push(num);
	visit[num] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (!visit[x + 1] && x + 1 <= 100000) {
			q.push(x + 1);
			visit[x + 1] = true;
			cnt[x + 1] = cnt[x] + 1;
		}
		if (!visit[x - 1] && x - 1 >= 0) {
			q.push(x - 1);
			visit[x - 1] = true;
			cnt[x - 1] = cnt[x] + 1;
		}
		if ((2 * x) <= 100000 && !visit[(2 * x)]) {
			q.push(2 * x);
			visit[2 * x] = true;
			cnt[2 * x] = cnt[x] + 1;
		}

	}


}

int main() {
	int N, M;

	cin >> N >> M;

	bfs(N);

	cout << cnt[M];

}