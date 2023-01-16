//N°úM
//https://www.acmicpc.net/problem/15649
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>

using namespace std;

int res[9];
int num[9];
int visit[9];
int n, m;

void back(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			res[level] = num[i];
			back(level + 1);
			visit[i] = false;
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		num[i] = i;
	}

	back(0);

}