//https://www.acmicpc.net/problem/17142
// 연구소 3
// 조건을 너무많이탄다...
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int map_re[51][51];
int map[51][51];
vector<pair<int, int>> virus;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
int answer = 999999999;
bool flag0 = 0; // 못찾았을 경우

void map_clear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = map_re[i][j];
		}
	}
}

void check(vector<pair<int, int>> select) {
	map_clear();
	int ans = 0;
	bool flag0_1 = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push(select[i]);
		map[select[i].first][select[i].second] = 90000;
	}

	/*while (!q.empty()) {
		cout << q.front().first << " " << q.front().second << endl;
		q.pop();
	}*/

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir[0][i];
			int nx = x + dir[1][i];

			if (ny >= n || nx >= n || ny < 0 || nx < 0) continue;
			if (map[ny][nx] == 1 || map[ny][nx] > 2) continue;
			if (map[ny][nx] == 2) {
				q.push(make_pair(ny, nx));
				map[ny][nx] = map[y][x] + 1;
				continue;
			}

			map[ny][nx] = map[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < map[i][j] && map_re[i][j] != 2) ans = map[i][j];
			if (map[i][j] == 0) /*flag0 = 1;*/ flag0_1 = 1;
		}
	}

	/*cout << "asdfasdf" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
	
	if (flag0_1) {
		//cout << "wrong" << endl;
		return;
	}
	//cout << endl;

	if (answer > ans) answer = ans;
}

void comb(int start, vector<pair<int, int>> select) {
	if (select.size() == m) {
		/*cout << "select finish" << endl;
		for (int i = 0; i < select.size(); i++) {
			cout << select[i].first << " " << select[i].second << endl;
		}*/
		check(select);
	}
	for (int i = start; i < virus.size(); i++) {
		select.push_back(virus[i]);
		comb(i + 1, select);
		select.pop_back();
	}
}


int main() {

	cin >> n >> m;

	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			map_re[i][j] = temp;
			if (temp == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	vector<pair<int, int>> select;
	comb(0, select);

	/*if (flag0 && answer == 2) {
		cout << -1;
		return 0;
	}*/
	if (answer == 999999999) {
		cout << -1;
		return 0;
	}
	if (answer == 1) {
		cout << 0;
		return 0;
	}

	cout << answer- 90000;

	return 0;
}