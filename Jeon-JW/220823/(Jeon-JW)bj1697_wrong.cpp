//https://www.acmicpc.net/problem/1697
//숨바꼭질
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//dfs같은 풀이.

int N, K;
int answer = 999999;
bool visit[100001];
void recur(int n, int k, int cnt) {
	if (n == k) {
		answer = min(answer, cnt);
	}
	visit[n] = 1;
	//cout << n << " " << cnt << endl;
	
	if(2*n<100001 && !visit[2*n])recur(2 * n, k, cnt + 1);
	if(n+1 < 100001 &&!visit[n+1]) recur(n + 1, k, cnt + 1);
	if(n-1 > 0 && !visit[n-1]) recur(n - 1, k, cnt + 1);
}

int main() {

	cin >> N >> K;
	visit[N] = 1;
	recur(N, K, 0);

	cout << answer;

	return 0;
}