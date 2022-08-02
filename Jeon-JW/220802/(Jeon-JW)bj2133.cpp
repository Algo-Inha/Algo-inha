//https://www.acmicpc.net/problem/2133
//타일 채우기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[31];
int N;

int main() {

	cin >> N;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 3; 
	dp[3] = 0;
	dp[4] = 11; // 2+2{3x3}(9) or{+} 4{2}
	dp[5] = 0; // 홀수는 아예 만들어지지않는다.
	dp[6] = 41; //  2+2+2(3x3x3){27} or(+) 4+2(2*3*2){12} or(+) 6{2} = (dp[4] * dp[2]){33} + (dp[2] * 2){6} + 2
	dp[7] = 0;
	//dp[8] = (dp[6]*dp[2]) + (dp[4] * 2) + (dp[2]*2) + 2

	if (N % 2 == 1) cout << 0;
	else {
		for (int i = 8; i <= N; i+= 2) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = 4; j < i; j += 2) {
				dp[i] += dp[i - j] * 2;
			}
			dp[i] += 2;
		}
		cout << dp[N];
	}

	return 0;
}

