//https://www.acmicpc.net/problem/2589
//보물섬
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int N, M;
char map[51][51];
int ans;
int calc[51][51];
bool visit[51][51];
int dir[2][4] = {
	{-1,0,1,0},{0,1,-1,0}
};
int bfs(int i, int j) {
	calc[i][j] = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	int temp = 0;

	while (!q.empty()) {
		int dy = q.front().first;
		int dx = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++) {
			int yy = dy + dir[0][a];
			int xx = dx + dir[1][a];

			if (yy < 0 || xx < 0 || yy >= N || xx >= M) continue;
			if (map[yy][xx] == 'W') continue;
			if (visit[yy][xx]) continue;

			visit[yy][xx] = 1;
			q.push(make_pair(yy, xx));
			calc[yy][xx] = calc[dy][dx] + 1;
			if (temp < calc[yy][xx]) temp = calc[yy][xx];
		}
	}

	return temp - 1;
}

//보물은 가장 긴 시간이 걸리는 육지 두곳에 나뉘어 묻혀있다.
int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		//scanf("%s", map[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				visit[i][j] = 1;
				int temp = bfs(i, j);
				if (ans < temp) ans = temp;
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						calc[k][l] = 0;
						visit[k][l] = 0;
					}
				}
			}
		}
	}


	cout << ans;



	//for(int i=0;i<N;i++){
	//	for(int j=0;j<M;j++){
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}



	return 0;
}