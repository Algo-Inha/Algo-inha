//https://www.acmicpc.net/problem/2240
//자두나무
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int T, W;
int dp[1001][31][3]; // [시간][바꾼회수][해당 시간과 위치에서의 나무 인덱스]
vector<int> ztime;

int main() {

	cin >> T >> W;
	ztime.resize(T + 1, 0);
	for (int i = 1; i <= T; i++) {
		cin >> ztime[i];
	}

	if (ztime[1] == 2) dp[1][1][ztime[1]] = 1;
	else dp[1][0][ztime[1]] = 1;

	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= W && j < i; j++) {
			// 자두가 시간 t에 1번 나무에 있으면 
			// 이전 위치가 2번일 때의 값에다가 j+1 인 인덱스 
			if (ztime.at(i) == 1) {
				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][1] = max({ dp[i][j + 1][1], dp[i - 1][j][2] + 1 });

				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] });
			}
			// 2번에 있으면 
			else {
				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][2] = max({ dp[i][j + 1][2], dp[i - 1][j][1] + 1 });

				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] });
			}
		}
	}

	int ans = 0;

	//dp에서 시간이 T 일때의 최대값을 검색
	for (int i = 0; i <= W; i++) {
		ans = max(dp[T][i][1], max(dp[T][i][2], ans));
	}
	cout << ans;

	return 0;
}

