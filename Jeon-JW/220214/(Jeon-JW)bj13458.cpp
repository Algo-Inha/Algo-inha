//https://www.acmicpc.net/problem/13458
//���� ����
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long n;
vector<long long> a;
long long b, c; // �Ѱ�����(�Ѹ�), �ΰ�����(������)


int main() {

	cin >> n;
	long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}

	cin >> b >> c;
	
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		answer++;
		if (a[i] <= 0) continue;
		else {
			answer = answer + (a[i] / c) ;
			if (a[i] % c != 0) {
				answer++;
			}
		}
	}
	

	cout << answer;

	return 0;
}