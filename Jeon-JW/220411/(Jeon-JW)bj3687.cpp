//https://www.acmicpc.net/problem/3687
//���ɰ���
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int test_case;

//int sung[10] = {
//	6,2,5,5,4,5,6,4,7,6
//};
int arr1[9] = {
	0,0, //0�� 1�δ� ���� �� �ִ� ���� ����. ������ ��
	1,7,4,2,0,8,10 // �� ���ڷ� ���� �� �ִ� �ּ� ��
};
vector<int> input_data;

long long dp[101]; // �ּҰ��� �����ϴ� �迭 ������ �ڷ���

void func() {
	for (int i = 0; i < 9; i++) {
		dp[i] = arr1[i];
	}
	dp[6] = 6;// ù ���ڷ� 0�� �������Ƿ� ����
	for (int i = 9; i <= 100; i++) {
		dp[i] = (dp[i - 2] * 10) + arr1[2];

		for (int j = 3; j < 8; j++) {
			dp[i] = min(dp[i], (dp[i - j] * 10) + arr1[j]);
		}
	}
}

int main() {

	func();
	cin >> test_case;

	int temp;
	for (int i = 0; i < test_case; i++) {
		cin >> temp;
		input_data.push_back(temp);
	}
	//ū ����7�� 1�� �ذᰡ��
	//���� �� ����.
	for (int i = 0; i < test_case; i++) {
		cout << dp[input_data[i]] << " ";

		for (;;) {
			if (input_data[i] % 2 != 0) {
				cout << 7;
				input_data[i] -= 3;
			}
			else {
				cout << 1;
				input_data[i] -= 2;
			}
			if (input_data[i] <= 0) break;
		}
		cout << "\n";
	}



	return 0;
}