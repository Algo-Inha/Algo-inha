//https://www.acmicpc.net/problem/16234
//인구 이동
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, L, R;
int map[50][50];
int answer;
bool flag1;
bool visit[50][50];
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
vector<pair<int, int>> v;


void visit_clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	v.clear();
	v.push_back(make_pair(i, j));
	//cout << v.size() << endl;

	q.push(make_pair(i, j));
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[0][i];
			int dx = x + dir[1][i];

			if (dy < 0 || dx < 0 || dy >= N || dx >= N)continue;
			if (map[dy][dx] < L || map[dy][dx] > R) continue;
			if (visit[dy][dx] == 1) continue;
			//cout << dy << " " << dx << endl;
			/*for (int a = 0; a < N; a++) {
				for (int b = 0; b < N; b++) {
					cout << visit[a][b] << " ";
				}
				cout << endl;
			}*/

			flag1 = 1;
			q.push(make_pair(dy, dx));
			visit[dy][dx] = 1;
			v.push_back(make_pair(dy, dx));
		}
	}
	if (v.size() == 1) {
		//cout << "return" << endl;
		return;
	}


	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += map[v[i].first][v[i].second];
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	sum = sum / v.size();

	//for (int i = 0; i < v.size(); i++) {
	//	cout << i << " " << v[i].first << " " << v[i].second << endl;
	//}
	//cout << "sum : " << sum << endl;

	for (int i = 0; i < v.size(); i++) {
		map[v[i].first][v[i].second] = sum;
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/
}


int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (;;) {
		flag1 = 0;
		visit_clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j] == 0) {
					visit[i][j] = 1;
					//cout << i << j << endl;
					bfs(i, j);

				}
			}
		}

		if (check()) {
			break;
		}

		if (!flag1) {
			break;
		}

		answer++;
	}


	cout << answer;

	return 0;
}


/*
인구이동 안되는 경우를 처리하지 못함.
*/