#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int arr[1001];
	vector<int> dp(1001, 1);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;
	return 0;

}
