//https://www.acmicpc.net/problem/2841
//외계인의 기타 연주
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int N, P;

stack<int> st[7]; // 기타줄
int cnt;

int main() {

	cin >> N >> P;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		while (!st[a].empty()) {
			if (st[a].top() > b) { // 낮은걸 하고싶으면 떼야함.
				cnt++; // 움직여야함.
				st[a].pop();
			}
			else break;
		}

		//이미 누른게 있고, 그게 b면
		if (!st[a].empty()) {
			if (st[a].top() == b) continue;
		}

		st[a].push(b);
		cnt++;

	}

	cout << cnt;

	return 0;
}