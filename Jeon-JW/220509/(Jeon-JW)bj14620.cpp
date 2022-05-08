//https://www.acmicpc.net/problem/14620
//²É±æ
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dir[2][4] = {
	{-1,0,1,0},
	{0,1,0,-1}
};
vector<pair<int, int>> v;
int N;
int map[11][11];
int map2[11][11];
int answer = 3000;

bool check(int y, int x) {

	for (int i = 0; i < v.size(); i++) {
		int dy = v[i].first;
		int dx = v[i].second;

		if (abs(dy - y) < 2 && abs(dx - x) < 2) return true;
		if (abs(dy - y) == 0 && abs(dx - x) == 2) return true;
		if (abs(dy - y) == 2 && abs(dx - x) == 0) return true;
	}
	return false;
}

void func(int cnt, int y, int x) {
	for (int i = y; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (i == y && j <= x) j = x + 1;
			if (check(i, j)) continue;

			v.push_back(make_pair(i, j));
			if (cnt == 2) {
				int temp = 0;
				for (int i = 0; i < 3; i++) {
					temp += map2[v[i].first][v[i].second];
				}
				if (answer > temp) {
					/*for(int i=0;i<3;i++){
						cout << v[i].first << " " << v[i].second << " value = " << map2[v[i].first][v[i].second] << endl;
					}*/
					answer = temp;
					//cout << "renew answer = " << answer << endl;
				}
			}
			else func(cnt + 1, i, j);
			v.pop_back();
		}
	}
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	//¹Ì¸® ²ÉµéÀÇ °ª °è»ê
	int temp;
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			temp = map[i][j];
			for (int k = 0; k < 4; k++) {
				int dy = i + dir[0][k];
				int dx = j + dir[1][k];

				temp += map[dy][dx];
			}
			map2[i][j] = temp;
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			v.push_back(make_pair(i, j));
			func(1, i, j);
			v.clear();
		}
	}

	cout << answer;

	return 0;
}