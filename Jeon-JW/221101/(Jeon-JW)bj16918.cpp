//https://www.acmicpc.net/problem/16918
//º½¹ö¸Ç
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int map[201][201];
int R, C, N;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};


int main() {

	cin >> R >> C >> N;
	int temp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> temp;
			if (temp == '0') map[i][j] = 0;
			else map[i][j] = -1;
		}
	}

	//1ÃÊ
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j]++;
		}
	}
	if (N == 1) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] == -1) {
					cout << ".";
				}
				else {
					cout << "O";
				}
			}
			cout << '\n';
		}
		return 0;
	}
	//2ÃÊ
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j]++;
		}
	}
	if (N == 2) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] == -1) {
					cout << ".";
				}
				else {
					cout << "O";
				}
			}
			cout << '\n';
		}
		return 0;
	}

	//ÆøÅº ÅÍÆ®¸®±â
	int dy, dx;
	for (int t = 3; t <= N;) {
		t++;
		vector<pair<int, int>> v;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] >= 0) {
					map[i][j]++;
				}
				if (map[i][j] == 3) {
					v.push_back(make_pair(i, j));
				}
			}
		}

		//ÆøÅº Áö¿ì±â
		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = -1;
			for (int j = 0; j < 4; j++) {
				dy = v[i].first + dir[0][j];
				dx = v[i].first + dir[1][j];

				if (dy < 1 || dy >R || dx < 1 || dx > C)continue;
				map[dy][dx] = -1;
			}
		}

		v.clear();
		if (t == N) break;

		t++;

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				map[i][j]++;
				if (map[i][j] == 3)v.push_back(make_pair(i, j));
			}
		}

		for (int i = 0; i < v.size(); i++) {
			map[v[i].first][v[i].second] = -1;
			for (int j = 0; j < 4; j++) {
				dy = v[i].first + dir[0][j];
				dx = v[i].second + dir[1][j];
				if (dy < 1 || dy >R || dx < 1 || dx > C)continue;
				map[dy][dx] = -1;
			}
		}

	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == -1) {
				cout << ".";
			}
			else {
				cout << "O";
			}
		}
		cout << '\n';
	}


	return 0;
}