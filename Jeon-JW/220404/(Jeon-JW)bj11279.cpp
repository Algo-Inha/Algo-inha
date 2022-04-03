//https://www.acmicpc.net/problem/11279
//�ִ���
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N, x;

priority_queue<int> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			//x�� 0�̶�� �迭���� ���� ū ���� ����ϰ� �� ���� �迭���� �����ϴ� ���
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}