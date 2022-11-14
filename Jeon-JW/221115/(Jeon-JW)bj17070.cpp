//https://www.acmicpc.net/problem/17070
//파이프 옮기기 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


int map[17][17];
int N, ans;
int dy[3] = {
	0,1,1
};
int dx[3] = {
	1,1,0
};

struct st {
	int y;
	int x;
	int dir;
};

queue<st> q;

void move(int y, int x, int dir, int i){
	int ny = y + dy[i];
	int nx = x + dx[i];
	int ndir = i;
	if (map[ny][nx] == 0 && ny > 0 && ny <= N && nx > 0 && nx <= N) {
		if (i == 1) {
			if (map[ny - 1][nx] == 1 || map[ny][nx - 1] == 1) return;
		}
		q.push({ ny,nx,ndir });
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	q.push({ 1,2,0 });
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		q.pop();
		if (y == N && x == N) ans++;
		if (dir == 0) { // 가로
			for (int i = 0; i < 2; i++) {
				move(y, x, dir, i);
			}
		}
		else if (dir == 1) { // 대각선
			for (int i = 0; i < 3; i++) {
				move(y, x, dir, i);
			}
		}
		else {
			for (int i = 1; i < 3; i++) {
				move(y, x, dir, i);
			}
		}


	}
	cout << ans;



	return 0;
}