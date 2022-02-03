//https://www.acmicpc.net/problem/20055
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

int n, k;
deque<int> a; // 내구도
deque<bool> robot; // 로봇 위치 1:있다,0:없다


int main() {

	cin >> n >> k;
	int temp;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> temp;
		a.push_back(temp);
		robot.push_back(0);
	}

	int step = 1;
	for (;;) {
		//벨트와 벨트위의 로봇이 움직인다.
		// 로봇의 위치 움직이기
		robot.push_front(robot.back());
		robot.pop_back();
		// 벨트의 위치 움직이기
		a.push_front(a.back());
		a.pop_back();
		robot[n - 1] = 0; // 로봇이 있던 없던 N(n-1)위치의 로봇을 없애버린다.

		//로봇 움직이기
		//(로봇은 0~n-1까지에서만 동작한다. 고로 n-1이 가장 먼저 들어온 로봇)
		for (int i = n - 2; i >= 0; i--) {
			if (robot[i] == 1) {
				if (a[i + 1] != 0 && robot[i + 1] == 0) {
					robot[i + 1] = 1;
					robot[i] = 0;
					a[i + 1]--;
				}
			}
		}
		robot[n - 1] = 0;

		//로봇 올리기
		if (a[0] != 0) {
			a[0]--;
			robot[0] = 1;
		}

		// 개수 확인 후 K개 이상이라면 과정을 종료
		int cnt = 0;
		for (int i = 0; i < (2 * n); i++) {
			if (a[i] == 0) {
				cnt++;
			}
		}
		if (cnt >= k) {
			cout << step << endl;
			return 0;
		}

		step++;
	}

	return 0;
}