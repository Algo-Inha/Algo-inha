//https://www.acmicpc.net/problem/14503
//로봇 청소기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int N, M;
int dir[2][4] = {
	{-1,0,1,0},{0,1,0,-1}
};

//반시계에 청소하지 않은 빈 공간이 존재한다면, 회전-전진 (청소로) or 반시계로 회전
//후진하지 않고 2a번 단계가 4번 실행됐을 때 / 바로 뒤가 벽이라면 작동을 멈춘다. 그렇지 않다면 후진한다.
int r, c, d;
int map[51][51];
int answer;
int cnt; //4번 카운트

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//시뮬
	for (;;) {
		if (cnt == 4) {
			//바로 뒤가 벽이다(1-3, 0-2)
			if (map[r + dir[0][(d + 2) % 4]][c + dir[1][(d + 2) % 4]] == 1) {
				break;
			}
			else {
				r = r + dir[0][(d + 2) % 4];
				c = c + dir[1][(d + 2) % 4];
				cnt = 0;
			}
		}
		//현재 위치를 청소한다.
		if(map[r][c] == 0) answer++;
		map[r][c] = -1;

		//현재 위치에서 인접한 칸 탐색
		//a
		int temp_dir = d - 1;
		if (temp_dir < 0) temp_dir = 3;
		int dy = r + dir[0][temp_dir];
		int dx = c + dir[1][temp_dir];

		if (map[dy][dx] == 0) {
			r = dy;
			c = dx;
			d = temp_dir;
			cnt = 0;
		}
		else {
			d = temp_dir;
			cnt++;
		}
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	cout << answer;

	return 0;
}