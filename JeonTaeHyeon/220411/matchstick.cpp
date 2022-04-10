#include<iostream>
#include<string>
#include<algorithm>
#define _size 101
using namespace std;
string maxdp[_size];
string mindp[_size];
int n;

void max() {
	int matchstick = n;
	maxdp[2] = "1";
	maxdp[3] = "7";
	if (n > 3) {
		if (!(matchstick % 2)) {
			while (matchstick) {
				maxdp[n] += maxdp[2];
				matchstick -= 2;
			}
		}
		else {
			maxdp[n] += maxdp[3];
			matchstick -= 3;
			while (matchstick) {
				maxdp[n] += maxdp[2];
				matchstick -= 2;
			}
		}
	}
}

void min() {
	for (int i = 0; i <= 100; i++)
	{
		mindp[i] = "99999999999999999";
	}
	mindp[2] = "1";
	mindp[3] = "7";	
	mindp[4] = "4";
	mindp[5] = "2";
	mindp[6] = "6";
	mindp[7] = "8";
	mindp[8] = "10";
	mindp[9] = "18";
	string save[9];
	for (int i = 2; i < 9; i++)
	{
		save[i] = mindp[i];
	}
	save[6] = "0";
	if (n > 9) {
		for (int i = 9; i <= 100; i++)
		{
			for (int j = 2; j < 8; j++)
			{
				if (stoll(mindp[i]) > stoll(mindp[i - j] + save[j])) {
					mindp[i] = mindp[i - j] + save[j];
				}
			}
		}
	}
}


int  main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		min();
		max();
		cout << mindp[n] << " " << maxdp[n] << "\n";
	}
}