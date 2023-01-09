#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ar;
int res, n;

void dfs(int cnt, int sum) {
	if (cnt > n - 1) {
		res = max(res, sum);
		return;
	}
	dfs(cnt + 1, sum);
	dfs(cnt + 2, sum + ar[cnt]);
}

int main() {
	cin >> n;
	ar.resize(n);
	for (int i = 0; i < n; i++) cin >> ar[i] >> ar[i] >> ar[i];
	dfs(0, 0);

	cout << res << endl;

	return 0;
}