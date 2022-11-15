#include<iostream>
#include<algorithm>
using namespace std;

int n, strong[21], pleasure[21], dp[101];
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> strong[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> pleasure[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 100; j >= strong[i]; j--) {
			dp[j] = max(dp[j], dp[j - strong[i]] + pleasure[i]);
		}
	}

	cout << dp[99];

}