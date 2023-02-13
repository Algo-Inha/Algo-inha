//https://www.acmicpc.net/problem/2502
//�� �Դ� ȣ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int D, K;
int A, B;
int a, b; // A,B�� ���

/*
A
B
A+B
A+2B
2A+3B
3A+5B
5A+8B
8A+13B
�ᱹ �Ǻ���ġ
*/
int dp[31];

int main() {

	cin >> D >> K;

	//�Ǻ���ġ ���ϱ�
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i < 31; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	//if (D == 3) {} 3�϶��� 1�� 2�� ���� �� ����.
	a = dp[D - 2];
	b = dp[D - 1];
	
	//�̷� �̰���...
	int temp;
	for (int i = 1; i <= K; i++) {
		temp = K - (a * i);
		if (temp % b == 0) {
			A = i; B = temp / b;
			break;
		}
	}

	cout << A << endl;
	cout << B;

	return 0;
}