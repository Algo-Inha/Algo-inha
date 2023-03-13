//https://www.acmicpc.net/problem/2240
//�ڵγ���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int T, W;
int dp[1001][31][3]; // [�ð�][�ٲ�ȸ��][�ش� �ð��� ��ġ������ ���� �ε���]
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
			// �ڵΰ� �ð� t�� 1�� ������ ������ 
			// ���� ��ġ�� 2���� ���� �����ٰ� j+1 �� �ε��� 
			if (ztime.at(i) == 1) {
				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][1] = max({ dp[i][j + 1][1], dp[i - 1][j][2] + 1 });

				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] });
			}
			// 2���� ������ 
			else {
				dp[i][j][2] = max({ dp[i][j][2], dp[i - 1][j][2] + 1 });
				if (j < W && j < i - 1)
					dp[i][j + 1][2] = max({ dp[i][j + 1][2], dp[i - 1][j][1] + 1 });

				dp[i][j][1] = max({ dp[i][j][1], dp[i - 1][j][1] });
			}
		}
	}

	int ans = 0;

	//dp���� �ð��� T �϶��� �ִ밪�� �˻�
	for (int i = 0; i <= W; i++) {
		ans = max(dp[T][i][1], max(dp[T][i][2], ans));
	}
	cout << ans;

	return 0;
}

