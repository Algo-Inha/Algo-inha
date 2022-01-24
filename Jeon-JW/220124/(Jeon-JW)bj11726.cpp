// https://www.acmicpc.net/problem/11726
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n;
int limit = 10007;
int dp[1001];

int main() {

	cin >> n;
	// �켱 ���� �𸣰ڴµ� �Ǻ���ġ��?
	// �����غ��� ��������� ����
	// i-1�� 1x2�ϳ� ���̴°��
	// i-2�� 2x1�� �ΰ� �ٴ� ���
	// �ΰ����� ���ϴ� ����� ����
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % limit;
	}

	cout << dp[n] << endl;

	return 0;
}