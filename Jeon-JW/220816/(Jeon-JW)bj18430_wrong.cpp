//https://www.acmicpc.net/problem/18430
//무기 공학
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, M;
int map[5][5];
int answer;
int dir[4][2][2] = {
	{{0,-1},{1,0}},
	{{0,-1},{-1,0}},
	{{-1,0},{0,1}},
	{{1,0},{0,1}}
};

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	if (N < 2 || M < 2) {
		cout << 0;
		return 0;
	}

	int temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int dy1 = dir[k][0][0];
				int dx1 = dir[k][0][1];
				int dy2 = dir[k][1][0];
				int dx2 = dir[k][1][1];

				if (dy1 < 0 || dy2 < 0 || dx1 < 0 || dx2 < 0) continue;
				if (dy1 >= N || dy2 >= N || dx1 >= M || dx2 >= M)continue;

				temp = (2 * map[i][j]) + map[dy1][dx1] + map[dy2][dx2];

				if (answer < temp) {
					cout << i << " " << j << " " << temp << endl;
					answer = temp;

				}
				//answer = max(answer, temp);
			}
		}
	}

	cout << answer;

	return 0;
}