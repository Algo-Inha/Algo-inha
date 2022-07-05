//나무 자르기
#include<iostream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

#define size 1000000

using namespace std;
int s, b;
int n, m;
long long h[size];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	sort(h, h+n);
	s = 0/*h[0]*/;
	b = h[n - 1];

	long long sum = 0;
	int res=0;
	int temp=0;
	while (s<=b) {
		temp = (s + b) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (h[i] > temp) {
				sum += (h[i] - temp);
			}
		}
		if (sum < m) {
			b = temp-1;
		}
		else if (sum >= m) {
			res = temp;
			s = temp+1;
		}
		
	}
	cout << res;
}