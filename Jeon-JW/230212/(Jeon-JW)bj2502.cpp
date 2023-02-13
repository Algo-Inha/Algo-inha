//https://www.acmicpc.net/problem/2502
//떡 먹는 호랑이
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int D, K;
int A, B;
int a, b; // A,B의 계수

/*
A
B
A+B
A+2B
2A+3B
3A+5B
5A+8B
8A+13B
결국 피보나치
*/
int dp[31];

int main() {

	cin >> D >> K;

	//피보나치 구하기
	dp[1] = 1; dp[2] = 1;
	for (int i = 3; i < 31; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	//if (D == 3) {} 3일때는 1과 2를 구할 수 없다.
	a = dp[D - 2];
	b = dp[D - 1];
	
	//이런 미개한...
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