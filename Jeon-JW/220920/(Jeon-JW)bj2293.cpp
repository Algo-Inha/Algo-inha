//https://www.acmicpc.net/problem/2293
//동전1
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n, k;
int dp[10001];
int arr[101];

int main() {

	cin >> n >> k;


	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // 동전
	}
	dp[0] = 1;

	for (int i = 0; i < n; i++) { // 동전고르기
		for (int j = arr[i]; j <= k; j++) { // 고른동전으로 개수 넣어주기.
			dp[j] += dp[j - arr[i]];
		}
	}

	cout << dp[k];

	return 0;
}