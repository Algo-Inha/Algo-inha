//https://www.acmicpc.net/problem/20056
//마법사 상어와 파이어볼
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct f_b {
	int r; // 행
	int c; // 렬
	int m; // 질량
	int s; // 속력
	int d; // 방향
};

int N, M, K;
vector<f_b> map[51][51];
vector<f_b> fb;
vector<f_b> new_fb;

int dir[2][8] = {
	{-1, -1, 0, 1, 1, 1, 0, -1},
	{0, 1, 1, 1, 0, -1, -1, -1}
};

int main() {

	cin >> N >> M >> K;

	f_b temp;
	for (int i = 0; i < M; i++) {
		cin >> temp.r >> temp.c >> temp.m >> temp.s >> temp.d;
		fb.push_back({ temp.r, temp.c, temp.m, temp.s, temp.d });
		map[temp.r][temp.c].push_back({ temp.r, temp.c, temp.m, temp.s, temp.d });
	}

	for (int i = 0; i < K; i++) {
		//초기화
		new_fb.clear();

		//움직이기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				map[j][k].clear();
			}
		}
		for (int j = 0; j < fb.size(); j++) {
			int nr = fb[j].r + ((dir[0][fb[j].d] * fb[j].s) % N);
			int nc = fb[j].c + ((dir[1][fb[j].d] * fb[j].s) % N);;

			if (nr > N) nr -= N;
			if (nc > N) nc -= N;
			if (nr < 1) nr += N;
			if (nc < 1) nc += N;

			map[nr][nc].push_back({ nr, nc, fb[j].m, fb[j].s, fb[j].d });
		}

		// 더하기
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (map[j][k].size() == 0) continue;
				if (map[j][k].size() == 1) {
					new_fb.push_back(map[j][k][0]);
					continue;
				}
				//2개이상일 경우
				//질량, 속력, 홀짝 확인
				int mass = 0;
				int speed = 0;
				bool flag1 = 0; //짝수
				bool flag2 = 0; // 홀수
				for (int a = 0; a < map[j][k].size(); a++) {
					mass += map[j][k][a].m;
					speed += map[j][k][a].s;
					if (map[j][k][a].d % 2 == 0) { // 짝수
						flag2 = 1;
					}
					else { // 홀수
						flag1 = 1;
					}
				}
				mass = mass / 5;
				speed = speed / map[j][k].size();

				//질량이 0인 파이어볼은 소멸
				if (mass == 0) continue;

				// 합쳐보자
				if (flag1 && flag2) { // 모두 홀수or짝수가 아니다.
					for (int a = 1; a <= 7; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
				else {
					for (int a = 0; a <= 6; a = a + 2) {
						new_fb.push_back({ j, k, mass, speed, a });
					}
				}
			}
		}

		fb = new_fb;
	}

	int answer = 0;
	for (int i = 0; i < fb.size(); i++) {
		answer += fb[i].m;
	}
	cout << answer;

	return 0;
}