//https://www.acmicpc.net/problem/3019
//��Ʈ����
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
		//����
		ans += C;
		//����
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
		//�״��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i+1] +1 == map[i+2]) {
				ans++;
			}
		}
		//ȸ��
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 4) {
		//�״��
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//ȸ��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-1) {
				ans++;
			}
		}
	}
	else if (P == 5) {
		//�״��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//�ð�90��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1] - 1) {
				ans++;
			}
		}
		//�ð�180��
		for (int i = 0; i < C - 2; i++) {
			if (map[i]-1 == map[i + 1] && map[i + 1] == map[i + 2]-1) {
				ans++;
			}
		}
		//�ð�270��
		for (int i = 0; i < C - 1; i++) {
			if (map[i]-1 == map[i + 1]) {
				ans++;
			}
		}
	}
	else if (P == 6) {
		//�״��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//�ð�90��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
		//�ð�180��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] + 1 == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//�ð�270��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] - 2 == map[i + 1]) {
				ans++;
			}
		}
	}
	else {
		//�״��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]) {
				ans++;
			}
		}
		//�ð�90��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]-2) {
				ans++;
			}
		}
		//�ð�180��
		for (int i = 0; i < C - 2; i++) {
			if (map[i] == map[i + 1] && map[i + 1] == map[i + 2]+1) {
				ans++;
			}
		}
		//�ð�270��
		for (int i = 0; i < C - 1; i++) {
			if (map[i] == map[i + 1]) {
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}