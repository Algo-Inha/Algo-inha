//https://www.acmicpc.net/problem/14502
//연구소
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, M;
int map_copy[9][9];
int map[9][9];
//벽을 무조건 3개 둬야한다.
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;
int answer;
int whole_num; // 맵의 최대 빈칸의 개수
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};


void map_clear() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = map_copy[i][j];
}


void bfs(vector<int> permlist) {
	map_clear();
	// 벽세우기
	for (int i = 0; i < 3; i++) {
		map[blank[permlist[i]].first][blank[permlist[i]].second] = 1;
	}

	int temp_answer = whole_num;
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(make_pair(virus[i].first, virus[i].second));
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dx || 0 || dy >= N || dx >= M) continue;
			if (map[dy][dx] == 2 || map[dy][dx] == 1) continue;

			map[dy][dx] = 2;
			q.push(make_pair(dy, dx));
			temp_answer--;
		}
	}

	if (temp_answer > answer) answer = temp_answer;
}


void perm(vector<int> permlist, int num, int pivot) {
	if (num == 3) {
		bfs(permlist);
		return;
	}
	for (int i = pivot; i < whole_num + 3; i++) {
		permlist.push_back(i);
		perm(permlist, num + 1, i + 1);
		permlist.pop_back();
	}
}


int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map_copy[i][j];
			if (map_copy[i][j] == 0) blank.push_back(make_pair(i, j));
			else if (map_copy[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	whole_num = blank.size() - 3;

	vector<int> permlist;
	perm(permlist, 0, 0);


	cout << answer;

	return 0;
}