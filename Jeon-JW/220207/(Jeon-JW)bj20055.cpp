//https://www.acmicpc.net/problem/20055
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

int n, k;
deque<int> a; // ������
deque<bool> robot; // �κ� ��ġ 1:�ִ�,0:����


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
		//��Ʈ�� ��Ʈ���� �κ��� �����δ�.
		// �κ��� ��ġ �����̱�
		robot.push_front(robot.back());
		robot.pop_back();
		// ��Ʈ�� ��ġ �����̱�
		a.push_front(a.back());
		a.pop_back();
		robot[n - 1] = 0; // �κ��� �ִ� ���� N(n-1)��ġ�� �κ��� ���ֹ�����.

		//�κ� �����̱�
		//(�κ��� 0~n-1���������� �����Ѵ�. ��� n-1�� ���� ���� ���� �κ�)
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

		//�κ� �ø���
		if (a[0] != 0) {
			a[0]--;
			robot[0] = 1;
		}

		// ���� Ȯ�� �� K�� �̻��̶�� ������ ����
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