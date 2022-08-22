//https://www.acmicpc.net/problem/1697
//¼û¹Ù²ÀÁú
#include<iostream>
#include<queue>

using namespace std;

int answer;
int N, K;
bool visit[100001];
void bfs(int n) {
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		int fir = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (fir == K) {
			answer = cnt;
			return;
		}
		if (fir + 1 < 100001 && !visit[fir +1]) {
			visit[fir + 1] = 1;
			q.push(make_pair(fir + 1, cnt + 1));
		}
		if (fir - 1 >= 0 && !visit[fir - 1]) {
			visit[fir - 1] = 1;
			q.push(make_pair(fir - 1, cnt + 1));
		}
		if (2 * fir < 100001 && !visit[2 * fir]) {
			visit[2 * fir] = 1;
			q.push(make_pair(2 * fir, cnt + 1));
		}
	}
}

int main() {

	cin >> N >> K;
	visit[N] = 1;
	bfs(N);
	cout << answer;

	return 0;
}