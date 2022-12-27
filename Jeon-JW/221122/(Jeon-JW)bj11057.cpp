//https://www.acmicpc.net/problem/11057
//오르막 수
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int N;
int dp[1001][10];
int ans;

int main() {

	cin >> N;
	//dp[0] = 0;
	//dp[1] = 10;
	//dp[2] = 55;
	//// 개수
	////0 1 2 3 4 5 6 7 8 9
	////0 9 8 7 6 5 4 3 2 1
	////// 끝나는개수
	////0 1 2 3 4 5 6 7 8 9 = 45
	////9+16+21+24+25+24+21+16+9 = 165
	//dp[3] = 220;
	///*dp[n] = dp[n-1]*/

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
	}
	cout << ans % 10007;





	return 0;
}