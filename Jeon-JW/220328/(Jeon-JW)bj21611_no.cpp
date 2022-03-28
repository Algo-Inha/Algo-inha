//https://www.acmicpc.net/problem/21611
//마법사 상어와 블리자드
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int map[50][50];
int marble[3]; // 폭발한 구슬의 개수 저장
int dir_shark[2][5] = {
	{0,-1,1,0,0},{0,0,0,-1,1}
};
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};
int shark[2];

void marble_move() {
	int y = shark[0];
	int x = shark[1] - 1;
	int d = 2;
	// 이전 값 가지고 있기.
	int dy = y;
	int dx = x;
	
	
	
	
	int range = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			// 마지막 한번만 빼주기
			if (i == N - 1 && j == 1) break;
			for (int k = 0; k < range; k++) {
				
				
				
				/*int y = y + dir[0][d];
				int x = x + dir[1][d];*/





				//마지막 한번만 빼주기
				if (dy == 1 && dx == 1)break;
			}
			d -= 1;
			if (d < 0)d = 3;
		}
		range++;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	shark[2] = {(N+1)/2, (N+1)/2};

	int di, si;
	for (int m = 0; m < M; m++) {
		cin >> di >> si;

		//1. 구슬 파괴
		for (int d = 1; d <= si; d++) {
			int dy = shark[0] + (d * dir_shark[0][di-1]);
			int dx = shark[1] + (d * dir_shark[1][di-1]);

			marble[map[dy][dx] - 1]++;
			map[dy][dx] = 0;
		}
		//2. 이동하기
		marble_move();





	}




	cout << marble[0] + (marble[1] * 2) + (marble[2] * 3);

	return 0;
}