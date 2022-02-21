//https://www.acmicpc.net/problem/20057
//마법사 상어와 토네이도
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int map[501][501];
int tor[3];
int dir[2][4] = { // 북동남서
	{-1,0,1,0},{0,1,0,-1}
};
int ans = 0;

/*float north1[9][3] = {
	{0, -2, 0.02},{-1,-1,0.1},{0,-1,0.07},{1,-1,0.01},
	{-2,0,0.05},
	{-1,1,0.1},{0,1,0.07},{1,1,0.01},{0,2,0.02}
}; */float north1[9][3] = {
	{0, -2, 2},{-1,-1,10},{0,-1,7},{1,-1,1},
	{-2,0,5},
	{-1,1,10},{0,1,7},{1,1,1},{0,2,2}
};
void north(int dy, int dx) {
	int whole = map[dy][dx];
	for (int i = 0; i < 9; i++) {
		int y = dy + north1[i][0];
		int x = dx + north1[i][1];
		int result = (map[dy][dx] * north1[i][2]) / 100;

		whole -= result;
		if (x < 1 || y < 1 || x > n || y > n) {
			ans += result;
			
		}
		else {
			map[y][x] += result;
		}
	}
	if (dy - 1 < 1) {
		ans += whole;
	}
	else {
		map[dy-1][dx] += whole;
	}
	map[dy][dx] = 0;
}

float east1[9][3] = {
	{-2,0,2},{-1,-1,1},{-1,0,7},{-1,1,10},
	{0,2,5},
	{1,-1,1},{1,0,7},{1,1,10},{2,0,2}
};
void east(int dy, int dx) {
	int whole = map[dy][dx];
	for (int i = 0; i < 9; i++) {
		int y = dy + east1[i][0];
		int x = dx + east1[i][1];
		int result = (map[dy][dx] * east1[i][2]) / 100;

		whole -= result;
		if (x < 1 || y < 1 || x > n || y > n) {
			ans += result;
			continue;
		}
		else {
			map[y][x] += result;
		}
	}
	if (dx + 1 > n) {
		ans += whole;
	}
	else {
		map[dy][dx + 1] += whole;
	}
	map[dy][dx] = 0;
}
float south1[9][3] = {
	{0,-2,2},{-1,-1,1},{0,-1,7},{1,-1,10},
	{2,0,5},
	{-1,1,1},{0,1,7},{1,1,10},{0,2,2}
};
void south(int dy, int dx) {
	int whole = map[dy][dx];
	for (int i = 0; i < 9; i++) {
		int y = dy + south1[i][0];
		int x = dx + south1[i][1];
		int result = (map[dy][dx] * south1[i][2]) / 100;

		whole -= result;
		if (x < 1 || y < 1 || x > n || y > n) {
			ans += result;
			continue;
		}
		else {
			map[y][x] += result;
		}
	}
	if (dy + 1 > n) {
		ans += whole;
	}
	else {
		map[dy+1][dx] += whole;
	}
	map[dy][dx] = 0;

}
float west1[9][3] = {
	{-2,0,2},{-1,-1,10},{-1,0,7},{-1,1,1},
	{0,-2,5},
	{1,-1,10},{1,0,7},{1,1,1},{2,0,2}
};
void west(int dy, int dx) {
	int whole = map[dy][dx];
	for (int i = 0; i < 9; i++) {
		int y = dy + west1[i][0];
		int x = dx + west1[i][1];
		int result = (map[dy][dx] * west1[i][2]) / 100;
		
		whole -= result;
		if (x < 1 || y < 1 || x > n || y > n) {
			ans += result;
			continue;
		}
		else {
			map[y][x] += result;
		}
	}
	if (dx - 1 < 1) {
		ans += whole;
	}
	else{
		map[dy][dx-1] += whole;
	}
	map[dy][dx] = 0;
}

//토네이도가 x에서 y로 이동하면, y의 모든 모래가 비율과 a가 적혀있는 칸으로 이동한다.
int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	tor[0] = (n / 2) + 1;
	tor[1] = (n / 2) + 1;
	tor[2] = 3;

	int range = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			//마지막 한번만 빼주기
			if (i == n - 1 && j == 1) break;
			for (int k = 0; k < range; k++) {
				int dy = tor[0] + dir[0][tor[2]];
				int dx = tor[1] + dir[1][tor[2]];
				//cout << "dy,dx : " << dy << " " << dx << " " << tor[2] << endl;
				//계산해주기

				if (tor[2] == 0) {
					north(dy, dx);
				}
				else if (tor[2] == 1) {
					east(dy, dx);
				}
				else if (tor[2] == 2) {
					south(dy, dx);
				}
				else if (tor[2] == 3) {
					west(dy, dx);
				}

				tor[0] = dy; tor[1] = dx;

				/*for (int a = 1; a <= n; a++) {
					for (int b = 1; b <= n; b++) {
						cout << map[a][b] << " ";
					}
					cout << endl;
				}
				cout << "ans = " << ans << endl;*/

				//마지막 한번만 빼주기
				if (dy == 1 && dx == 1) break;

			}
			//방향 전환해주기
			tor[2] = tor[2] - 1;
			if (tor[2] < 0) tor[2] = 3;
		}
		range++; // 두개씩 거리 늘려주기
	}

	cout << ans;

	return 0;
}