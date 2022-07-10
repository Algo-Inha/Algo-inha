//https://www.acmicpc.net/problem/1654
//���� �ڸ���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, K;
vector<long> lines;
long ans;

int main() {

	cin >> K >> N;
	
	long temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		lines.push_back(temp);
	}

	long start = 1;
	long end = *max_element(lines.begin(), lines.end());
	while (start <= end) {
		long total = 0; // �ڸ� ������ ����
		long mid = (start + end) / 2;
		for (int i = 0; i < K; i++) {
			total += lines[i] / mid;
		}
		if (total < N) {
			end = mid - 1; // ���ġ���� ���� ��� �� �� �ڸ������� end�� �ٿ���.
		}
		else {
			start = mid + 1; // ���� �� ���� ����� ���ؼ� start�� �����ش�.
			ans = mid;
		}
	}

	cout << ans;

	return 0;
}