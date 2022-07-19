//https://www.acmicpc.net/problem/4948
//����Ʈ�� ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
//�Ҽ��� �����佺�׳׽��� ü
int arr[246913]; // n�� ���� 123456


int main() {

	//�����۾�
	for (int i = 0; i < 246914; i++) {
		arr[i] = i;
	}

	//�����佺�׳׽��� ü
	for (int i = 2; i <= 246913; i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 246913; j += i) {
			arr[j] = 0;
		}
	}

	for (;;) {
		cin >> n;
		if (n == 0) return 0;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}