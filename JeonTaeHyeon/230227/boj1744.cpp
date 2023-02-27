//¼ö¹­±â
//https://www.acmicpc.net/problem/1744

#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;


int main() {
	int n;
	int s[50];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int sum = 0;
	sort(s, s + n);

	for (int i = 0; i < n; i++)
	{
		if ((i + 1) < n && s[i] < 0 && s[i + 1] < 0) {
			sum += s[i] * s[i + 1];
			i++;
		}
		else if ((i + 1) < n && s[i] < 0 && s[i + 1] == 0) {
			i++;
		}
		else if ((i + 1) < n && s[i] > 1 && s[i + 1] > 1) {
			if (s[i] <= s[i + 1]) {
				sort(s + i, s + n, greater<int>());
			}
			sum += s[i] * s[i + 1];
			i++;
		}
		else {
			sum += s[i];
		}
	}
	cout << sum;
}