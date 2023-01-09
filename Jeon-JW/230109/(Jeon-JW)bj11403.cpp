//https://www.acmicpc.net/problem/11403
//경로 찾기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int map[101][101];


int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) map[i][j] = 99999999;
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 99999999) cout << 0 << ' ';
			else cout << 1 << ' ';
		}
		cout << endl;
	}


	return 0;
}