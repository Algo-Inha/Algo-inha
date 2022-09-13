//https://www.acmicpc.net/problem/11660
//구간 합 구하기 5
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int n, m;
int x1, y1;
int x2, y2;
int ans;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}


	return 0;
}