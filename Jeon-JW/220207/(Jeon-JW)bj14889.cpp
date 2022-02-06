// https://www.acmicpc.net/problem/14889
// ��ŸƮ�� ��ũ
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int map[21][21];
int ans = 999999999;
bool visit[21]; // 1�϶� ��ŸƮ�� / 0�϶� ��ũ��

void comb(int start, int num) {
	if (num == n/2) {
		int start_team_score = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1) {
				for (int j = i + 1; j <= n; j++) {
					if (visit[j] == 1) {
						start_team_score = start_team_score + map[i][j];
					}
				}
			}
		}
		int link_team_score = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				for (int j = i + 1; j <= n; j++) {
					if (visit[j] == 0) {
						link_team_score = link_team_score + map[i][j];
					}
				}
			}
		}
		int abs_sum = abs(start_team_score - link_team_score);

		/*cout << "visit = ";
		for (int i = 1; i <= n; i++) {
			cout << visit[i] << " ";
		}cout << endl;
		cout << "sts = " << start_team_score << ", lts = " << link_team_score << endl;*/

		if (abs_sum < ans) {
			ans = abs_sum;
		}
	}

	for (int i = start + 1; i <= n; i++) {
		visit[i] = 1;
		comb(i, num + 1);
		visit[i] = 0;
	}
}


int main() {

	cin >> n;

	int temp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			map[i][j] = temp;
		}
	}
	//����� �� ���ϰ� �ϱ����ؼ� // ���� �ݸ� ����Ѵ�.
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			map[i][j] = map[i][j] + map[j][i];
		}
	}
	
	/*cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	comb(0, 0);

	cout << ans << endl;

	return 0;
}