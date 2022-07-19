//Επ»η 2
//dp
#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int N;
	int T[1500001];
	int P[1500001];
	int DP[1500001] = { 0, };

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	DP[1] = 0;
	int ans = 0;
	for (int i = 1; i <= N + 1; i++) {
		ans = max(ans, DP[i]);
		if (i + T[i] > N + 1)
			continue;
		else {
			DP[i + T[i]] = max(DP[i + T[i]], ans + P[i]);
		}
	}

	cout << ans << '\n';
	return 0;
}