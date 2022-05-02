//BOJ2824번 최대공약수
//https://www.acmicpc.net/problem/2824

#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>
#define size 1000
#define over 1000000000
using namespace std;

int nsize, msize;
int n[size];
int m[size];
long long res = 1;
bool check;

int gcd(int num1, int num2) {
	while (num2) {
		int temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	return num1;
}

void cal() {
	for (int i = 0; i < nsize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			int temp = gcd(n[i], m[j]);
			res = res * temp;
			n[i] /= temp;
			m[j] /= temp;
			if (res >= over) {
				res %= over;
				check = true;
			}
		}
	}
}

int main() {
	cin >> nsize;
	for (int i = 0; i < nsize; i++)
	{
		cin >> n[i];
	}
	cin >> msize;
	for (int i = 0; i < msize; i++)
	{
		cin >> m[i];
	}
	cal();
	if (check) {
		res %= over;
		cout.width(9);
		cout.fill('0');
		cout << res << '\n';
	}
	else {
		cout << res;
	}

}