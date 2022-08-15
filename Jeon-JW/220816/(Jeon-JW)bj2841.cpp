//https://www.acmicpc.net/problem/2841
//�ܰ����� ��Ÿ ����
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int N, P;

stack<int> st[7]; // ��Ÿ��
int cnt;

int main() {

	cin >> N >> P;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;

		while (!st[a].empty()) {
			if (st[a].top() > b) { // ������ �ϰ������ ������.
				cnt++; // ����������.
				st[a].pop();
			}
			else break;
		}

		//�̹� ������ �ְ�, �װ� b��
		if (!st[a].empty()) {
			if (st[a].top() == b) continue;
		}

		st[a].push(b);
		cnt++;

	}

	cout << cnt;

	return 0;
}