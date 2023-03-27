//https://www.acmicpc.net/problem/11055
//���� ū �����ϴ� �κ� ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long dp[1001];
long long number[1001];
int max_value;


int main() {
	int N;
	int cnt = 1;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
		dp[i] = number[i];
	}

	//��ȭ�ı����� �ƴ�����.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (number[j] < number[i] && dp[i] < dp[j] + number[i]) {
				dp[i] = dp[j] + number[i];
			}
		}
		if (max_value < dp[i]) max_value = dp[i];
	}

	
	cout << max_value;
}