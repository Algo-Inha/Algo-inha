//https://www.acmicpc.net/problem/15649
// N°ú M(1)
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, M;
bool visit[9];
int arr[9];

void recur (int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			arr[cnt] = i;
			recur(cnt + 1);
			visit[i] = 0;
		}
	}
}


int main() {

	cin >> N >> M;

	recur(0);

	return 0;
}