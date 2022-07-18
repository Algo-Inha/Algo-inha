//BOJ4948 베르트랑 공준
//https://www.acmicpc.net/problem/4948
#include <iostream>
#include<cmath>
#define size 2*123456
using namespace std;
int num = size;
int arr[size];
int n,cnt;
int main() {
	for (int i = 2; i < size; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < sqrt(num); i++)
	{
		if (!arr[i])continue;
		for (int j = 2*i; j <= num; j+=i)
		{
			arr[j] = 0;
		}
	}

	while (1) {
		cnt = 0;
		cin >> n;
		if (!n)break;
		for (int i = n+1; i <= n*2; i++)
		{
			if (arr[i] != 0)++cnt;
		}
		cout << cnt << "\n";
	}

}