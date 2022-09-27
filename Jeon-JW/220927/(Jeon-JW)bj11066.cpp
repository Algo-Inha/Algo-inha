//https://www.acmicpc.net/problem/11066
//파일 합치기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, K;
int arr[501];
int sum[501];
int dp[501][501];


int main() {

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < K; i++) {
			for (int j = 1; j <= K - i; j++) {
				dp[j][j + i] = 999999999;

				for (int mid = j; mid < j + i; mid++) {
					// j부터 j+i까지 더한 최소값은
					// j부터 j+i의 값 또는
					// j부터 mid(j보다크고 j+i보다작음)까지 최소값 +
					// mid+1부터 j+i까지의 최소값 +
					// j+i까지 모든 더한 값 +
					// j-1의 모든 더한 값 - (두개 합치면 j부터 j+i까지 모두 더한 값) -> 합치는 비용(sum이 필요한이유)
					dp[j][j + i] = min(dp[j][j + i], dp[j][mid] + dp[mid + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}



	return 0;
}