//https://www.acmicpc.net/problem/3019
//테트리스
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int map[101];
int C;
int P;
int ans;

int main() {

	cin >> C >> P;

	for (int i = 0; i < C; i++) {
		cin >> map[i];
	}

	if (P == 1) {
		//세로
		ans += C;
		//가로
		for (int i = 0; i < C - 3; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2] && map[i + 2] == map[i + 3]) {
				ans++;
			}
		}

	}
	else if (P == 2) {
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 3) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i+1] +1 == map[i+2]) {
				ans++;
			}
		}
		//회전
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 4) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//회전
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-1) {
				ans++;
			}
		}
	}
	else if (P == 5) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1] - 1) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]-1) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 6) {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i] + 1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] - 2 == map[i + 1]) {
				ans++;
			}
		}
	}
	else {
		//그대로
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//시계90도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-2) {
				ans++;
			}
		}
		//시계180도
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]+1) {
				ans++;
			}
		}
		//시계270도
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}