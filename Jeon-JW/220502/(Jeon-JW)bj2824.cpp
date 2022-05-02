//https://www.acmicpc.net/problem/2824
//최대공약수
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
int Narr[1000];
int Marr[1000];

long long temp;
long long answer = 1;

long long gcd(long long a, long long b) {
	int temp;
	while (true) {
		if (b == 0) return a;
		else {
			temp = b;
			b = a % b;
			a = temp;
		}
	}

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Narr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> Marr[i];
	}

	bool flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp = gcd(Narr[i], Marr[j]); // 최대공약수 구하기

			answer = answer * temp;
			Narr[i] = Narr[i] / temp;
			Marr[j] = Marr[j] / temp;
			if (answer >= 1000000000) {
				answer = answer % 1000000000;
				flag = 1;
			}
		}
	}

	if (flag) {
		printf("%09lld", answer);
	}
	else cout << answer;

	return 0;
}