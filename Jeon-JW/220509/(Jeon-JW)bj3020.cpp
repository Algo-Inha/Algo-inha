//https://www.acmicpc.net/problem/3020
//���˹���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, H;

int main() {

	cin >> N >> H;
	vector<int> bottom(N / 2);
	vector<int> top(N / 2);
	for (int i = 0; i < N / 2; i++) {
		cin >> bottom[i] >> top[i];
	}

	// lower_bound, upper_bound�� ����ϱ� ���ؼ��� �������� ������ �Ǿ��־���Ѵ�.
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());


	int answer = 999999999;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {
		//�ش� ���̿� ��ġ�� ����
		//lower_bound(bottom.begin(), bottom.end(), i) - bottom���ο��� i���� ���ų� ū���ڰ� ���°�� ó�� �����ϴ���
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		//�ش� ���̿� ��ġ�� ������
		//upper_bound(top.begin(), top.end(), H - i) - top���ο��� H-i���� ���ų� ���� ���ڰ� ���°�� ó�� �����ϴ���
		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		//temp���� �ᱹ �ش� ���̿� ��ġ�� ������ �������� ����ǰ� �ȴ�.

		if (answer == temp)// �� ó������ �ȵȴ�.
			cnt++;
		else if (answer > temp) { // temp��� ���̿� ��� cnt�� ���̰� �Ǵ��� 
			answer = temp;
			cnt = 1;
		}
	}
	cout << answer << " " << cnt;

	return 0;
}