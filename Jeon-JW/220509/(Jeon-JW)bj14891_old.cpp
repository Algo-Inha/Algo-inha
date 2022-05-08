//https://www.acmicpc.net/problem/14891
//톱니바퀴
#include<iostream>
#include<vector>

using namespace std;

bool gear[5][8];
int K;
int spin[100][2]; // 번호 방향
int state[5]; // 12시 방향이 있는 값을 저장

// 왼쪽과 오른쪽에 맞닿는 기어의 번호를 return
int findLeft(int gearNum) {
	int left = 0;
	left = (state[gearNum] - 2);
	if (left < 0) left = 8 + left;
	return left;
}
int findRight(int gearNum) {
	int right;
	right = (state[gearNum] + 2) % 8;
	return right;
}

void spinMove(int num, int spinDirection) {
	if (spinDirection == 1) { //시계
		state[num] -= 1;
		if (state[num] < 0) state[num] += 8;
	}
	else {//반시계
		state[num] = (state[num] + 1) % 8;
	}
}

// 1 시계 -1 반시계
// direction 왼0 오1 // flag는 자기자신이 돌지말지.
void chain(int me, int you, int direction, int spinDirection, bool flag) {
	if (you != 0 && you != 5) { // 비교범위 외 제외
		if (!direction) { // 왼비교
			int meLeft = findLeft(me);
			int youRight = findRight(you);
			if (gear[me][meLeft] != gear[you][youRight]) { // 다를경우만
				chain(me - 1, you - 1, 0, -1 * spinDirection, 1);
			}
		}
		else { // 오비교
			int meRight = findRight(me);
			int youLeft = findLeft(you);
			if (gear[me][meRight] != gear[you][youLeft]) { // 다를경우만
				chain(me + 1, you + 1, 1, -1 * spinDirection, 1);
			}
		}
	}
	if (flag)spinMove(me, spinDirection); // 자기자신 움직여주기
}

void go(int num) { // 돌아버려
	int gearNum = spin[num][0]; int spinDir = spin[num][1];

	if (gearNum == 1) {
		chain(1, 2, 1, spinDir, 1); // 오른쪽으로
	}
	else if (gearNum == 2 || gearNum == 3) {
		chain(gearNum, gearNum + 1, 1, spinDir, 0); // 오른
		chain(gearNum, gearNum - 1, 0, spinDir, 1); // 왼
	}
	else if (gearNum == 4) {
		chain(4, 3, 0, spinDir, 1); // 왼
	}
}


int main() {
	/*int a[5];

	for (int i = 1; i <= 4; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < 5; i++) {
		for (int j = 7; j >= 0; j--) {
			gear[i][j] = a[i]%10;
			a[i] /= 10;
		}
	}*/
	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &gear[i][j]);
		}
	}

	/*for (int i = 1; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			cout << gear[i][j] << " ";
		}
		cout << endl;
	}*/

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> spin[i][0];
		cin >> spin[i][1];
	}
	for (int i = 1; i <= 4; i++) {
		state[i] = 0; // 초기는 모두 0이 12시방향임.
	}

	for (int i = 0; i < K; i++) {
		//cout << spin[i][0] << " " << spin[i][1] << endl;
		go(i);
		/*for (int j = 1; j < 5; j++) {
			cout << state[j] << " ";
		}
		cout << endl;*/
	}

	int answer = 0;
	if (gear[1][state[1]] == 1) answer += 1;
	if (gear[2][state[2]] == 1) answer += 2;
	if (gear[3][state[3]] == 1) answer += 4;
	if (gear[4][state[4]] == 1) answer += 8;
	cout << answer << endl;

	return 0;
}