//https://www.acmicpc.net/problem/3190
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n; // 2~100 // 보드의 크기
int k; // 0~100 // 사과 개수
bool map[101][101];
int l; // 뱀의 방향 변환 정보
int dir[2][100];

int snake[3] = {1, 1, 1}; // 뱀의 머리 위치, 머리의 방향 d[2][4]의 위치를 따른다.
int d[2][4] = {
	{-1,0,1,0},{0,1,0,-1} // 북 동 남 서
};
queue<pair<int, int>> snakeBody;

int main() {

	//snakeBody에 뱀의 위치 넣어두기
	snakeBody.push(make_pair(1, 1));
	//cout << snakeBody.front().first << endl;
	//cout << snakeBody.front().second << endl;

	cin >> n >> k;

	int a1, a2;
	for (int i = 0; i < k; i++) {
		cin >> a1 >> a2;
		map[a1][a2] = 1;
	}

	cin >> l;
	int dir1, dir2;
	char dirChar;
	for (int i = 0; i < l; i++) {
		cin >> dir1 >> dirChar;
		if (dirChar == 'D') { // 오른쪽 90도회전
			dir2 = 0;
		}
		else { // 왼쪽 90도 회전
			dir2 = 1;
		}
		dir[0][i] = dir1;
		dir[1][i] = dir2;
	}

	////snakeBody에 뱀의 위치 넣어두기
	//snakeBody.push(make_pair(1, 1));

	int t=0; // 시간
	int nx, ny; // 움직이고자 하는 곳.
	int lflag = 0; // 회전 확인
	int snakeL = 1; // 뱀의 길이
	int temp1, temp2;
	for (;;) {
		t++;
		//움직이기(머리 움직이기->꼬리 당기기)
		nx = snake[0] + d[0][snake[2]];
		ny = snake[1] + d[1][snake[2]];

		//	이동한 칸이 n의 범위를 넘을 경우
		if (nx > n || ny > n || nx < 1 || ny < 1) {
			/*cout << "pattern1" << endl;
			cout << nx << " " << ny << endl;*/
			cout << t;
			return 0;
		}
		//cout << snakeBody.front().first<<" "<< snakeBody.front().second << endl;
		
		//	이동한 칸이 뱀의 몸을 만났을 경우
		for (int i = 0; i < snakeL; i++) {
			//cout << t << " " << i << " "  << snakeBody.front().first << " " << snakeBody.front().second << endl;
			temp1 = snakeBody.front().first;
			temp2 = snakeBody.front().second;
			if (nx == temp1 && ny == temp2) {
				/*cout << "pattern2" << endl;
				cout << temp1 << " " << temp2 << endl;
				cout << nx << " " << ny << endl;*/
				cout << t;
				return 0;
			}
			snakeBody.pop();
			snakeBody.push(make_pair(temp1, temp2));
		}

		//사과 확인하기
		if (map[nx][ny] == 0) {//사과가 없을 경우
			snakeBody.pop();
			snakeBody.push(make_pair(nx, ny));
		}
		else {//사과가 있을 경우
			snakeL++;
			snakeBody.push(make_pair(nx, ny));
			map[nx][ny] = 0;
		}

		//머리 위치 옮겨주기
		snake[0] = nx;
		snake[1] = ny;

		//머리방향 확인하기
		if (dir[0][lflag] == t) {
			if (dir[1][lflag] == 0) { // 오른쪽 회전
				snake[2]++;
			}
			else { // 왼쪽 회전
				snake[2]--;
			}
			if (snake[2] < 0) {
				snake[2] = 3;
			}
			if (snake[2] > 3) {
				snake[2] = 0;
			}
			
			lflag++;
			
		}

	}



	return 0;
}