//https://www.acmicpc.net/problem/20058
//마법사 상어와 파이어스톰
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, Q;
int A1[65][65];
int A2[65][65];
vector<int> L;
bool melt[65][65];
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
bool visited[65][65];
int max_second = 0;

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int dy = i + dir[0][k];
			int dx = j + dir[1][k];

			if (dy < 0 || dx < 0 || dy >= pow(2, N) || dx >= pow(2, N))continue;
			if (visited[dy][dx] == 1) continue;
			if (Q % 2 == 0) {
				if (A1[dy][dx] == 0) continue;
			}
			else {
				if (A2[dy][dx] == 0)continue;
			}

			visited[dy][dx] = 1;
			q.push(make_pair(dy, dx));
			cnt++;
		}
	}
	return cnt;
}


int main() {

	cin >> N >> Q;
	//int sum_num = 0;
	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			cin >> A1[i][j];
			//sum_num += A1[i][j];
		}
	}
	//cout << sum_num << endl;
	int temp;
	for (int i = 0; i < Q; i++) {
		cin >> temp;
		L.push_back(temp);
	}
	for (int q = 0; q < Q; q++) {
		//돌리기
		if (q % 2 == 0) {
			for (int i = 0; i < pow(2, N); i = i + pow(2, L[q])) {
				for (int j = 0; j < pow(2, N); j = j + pow(2, L[q])) {
					//0,0 -> 0,3 0,1 -> 1,3
					//1,0 -> 0,2 1,1 -> 1,2
					int c = i;
					int d = j;
					for (int a = j + pow(2, L[q]) - 1; a >= j; a--) {
						for (int b = i; b < i + pow(2, L[q]); b++) {
							A2[b][a] = A1[c][d];
							//cout << b << " " << a << " " << c << " " << d << endl;
							d++;
						}
						c++;
						d = j;
					}
				}
			}
			//녹이기
			int cnt = 0;
			for (int i = 0; i < pow(2, N); i++) {
				for (int j = 0; j < pow(2, N); j++) {
					cnt = 0;
					if (A2[i][j] == 0) continue;
					for (int k = 0; k < 4; k++) {
						int dy = i + dir[0][k];
						int dx = j + dir[1][k];

						if (dy < 0 || dx < 0 || dy >= pow(2, N) || dx >= pow(2, N)) {
							cnt++;
							continue;
						}
						if (A2[dy][dx] == 0) {
							cnt++;
						}
					}
					if (cnt >= 2) melt[i][j] = 1;
				}
			}
			for (int i = 0; i < pow(2, N); i++) {
				for (int j = 0; j < pow(2, N); j++) {
					if (melt[i][j] == 1) {
						A2[i][j] -= 1;
						melt[i][j] = 0;
					}
				}
			}
		}
		else {
			for (int i = 0; i < pow(2, N); i = i + pow(2, L[q])) {
				for (int j = 0; j < pow(2, N); j = j + pow(2, L[q])) {
					//0,0 -> 0,3 0,1 -> 1,3
					//1,0 -> 0,2 1,1 -> 1,2
					int c = i;
					int d = j;
					for (int a = j + pow(2, L[q]) - 1; a >= j; a--) {
						for (int b = i; b < i + pow(2, L[q]); b++) {
							A1[b][a] = A2[c][d];
							//cout << b << " " << a << " " << c << " " << d << endl;
							d++;
						}
						c++;
						d = j;
					}
				}
			}
			//녹이기
			int cnt = 0;
			for (int i = 0; i < pow(2, N); i++) {
				for (int j = 0; j < pow(2, N); j++) {
					cnt = 0;
					if (A1[i][j] == 0) continue;
					for (int k = 0; k < 4; k++) {
						int dy = i + dir[0][k];
						int dx = j + dir[1][k];

						if (dy < 0 || dx < 0 || dy >= pow(2, N) || dx >= pow(2, N)) {
							cnt++;
							continue;
						}
						if (A1[dy][dx] == 0) {
							cnt++;
						}
					}
					if (cnt >= 2) melt[i][j] = 1;
				}
			}
			for (int i = 0; i < pow(2, N); i++) {
				for (int j = 0; j < pow(2, N); j++) {
					if (melt[i][j] == 1) {
						A1[i][j] -= 1;
						melt[i][j] = 0;
					}
				}
			}
		}
	}

	//최대값 찾기
	int max_num = 0;
	if (Q % 2 == 0) { // A1
		for (int i = 0; i < pow(2, N); i++) {
			for (int j = 0; j < pow(2, N); j++) {
				max_num += A1[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < pow(2, N); i++) {
			for (int j = 0; j < pow(2, N); j++) {
				max_num += A2[i][j];
			}
		}
	}

	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			if (Q % 2 == 0 && A1[i][j] == 0) continue;
			if (Q % 2 == 1 && A2[i][j] == 0) continue;
			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				int rst = bfs(i, j);
				max_second = max(max_second, rst);
			}
		}
	}
	
	
	/*for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			cout << A1[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < pow(2, N); i++) {
		for (int j = 0; j < pow(2, N); j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << max_num << "\n";
	cout << max_second;

	


	return 0;
}