//https://www.acmicpc.net/problem/2805
//���� �ڸ���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> trees;
long long max_len = 1000000000;
int ans;

int main() {

	cin >> N >> M; // ������ ��, ������ ����

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		trees.push_back(temp);
	}

	int start = 0; // ���������� �ּҰ�
	int end = *max_element(trees.begin(), trees.end()); // ���������� �ִ밪
	while (start <= end) {
		long long total = 0;
		int mid = (start + end) / 2; // �̺�Ž���� ���� ������ �� ������ ���̸� ����.
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid) total += trees[i] - mid;
		}
		if (total < M) {
			end = mid - 1; // ���ġ���� ���� ��� �� �� �ڸ������� end�� �ٿ���.
		}
		else {
			ans = mid; // ���ġ�� �������� ��� ���� �־�ΰ�
			start = mid + 1; // ���� �� ���� ����� ���ؼ�(����̴� �ڿ��� ����ϴϱ�) start�� �����ش�.
		}
	}
	cout << ans;

	return 0;
}