// https://www.acmicpc.net/problem/11726
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n;
int limit = 10007;
int dp[1001];

int main() {

	cin >> n;
	// 우선 왠지 모르겠는데 피보나치네?
	// 생각해보니 이전경우의 수에
	// i-1은 1x2하나 붙이는경우
	// i-2은 2x1이 두개 붙는 경우
	// 두가지를 더하는 결과와 동일
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % limit;
	}

	cout << dp[n] << endl;

	return 0;
}