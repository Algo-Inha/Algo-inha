//https://www.acmicpc.net/problem/11066
//���� ��ġ��
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, K;
int arr[501];
int sum[501];
int dp[501][501];


int main() {

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < K; i++) {
			for (int j = 1; j <= K - i; j++) {
				dp[j][j + i] = 999999999;

				for (int mid = j; mid < j + i; mid++) {
					// j���� j+i���� ���� �ּҰ���
					// j���� j+i�� �� �Ǵ�
					// j���� mid(j����ũ�� j+i��������)���� �ּҰ� +
					// mid+1���� j+i������ �ּҰ� +
					// j+i���� ��� ���� �� +
					// j-1�� ��� ���� �� - (�ΰ� ��ġ�� j���� j+i���� ��� ���� ��) -> ��ġ�� ���(sum�� �ʿ�������)
					dp[j][j + i] = min(dp[j][j + i], dp[j][mid] + dp[mid + 1][j + i] + sum[j + i] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << '\n';
	}



	return 0;
}