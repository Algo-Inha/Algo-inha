//น้มุ 1747น๘
//https://www.acmicpc.net/problem/1747

#include<iostream>
#include<string>
#include<cmath>
#define _size 1111111
using namespace std;


int prime[1111112];
int n;

int main() {
	for (int i = 1; i <= _size; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(_size); i++)
	{
		if (prime[i] == 0)continue;
		for (int j = i * i; j <= _size; j += i)
		{
			prime[j] = 0;
		}
	}

	cin >> n;
	if (n == 1) {
		cout << "2";
	}
	else {
		for (int i = n; i <= _size; i++)
		{
			int flag = true;
			if (prime[i]) {
				string temp = to_string(prime[i]);
				for (int i = 0; i < temp.size() / 2; i++)
				{
					if (temp[i] != temp[temp.size() - (i + 1)]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cout << prime[i];
					break;
				}
			}
		}
	}
}