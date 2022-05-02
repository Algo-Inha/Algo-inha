//BOJ1700 멀티탭 스케줄링
//https://www.acmicpc.net/problem/1700

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<cstring>
#include<math.h>

using namespace std;

int order[101];
int outlet[101];
int n, k;
int cnt;

int main() {
	cin >>n>> k;
	for (int i = 0; i < k; i++)
	{
		cin >> order[i];
	}
	for (int i = 0; i < k; i++)
	{

		int check = true;
		for (int j = 0; j < n; j++)
		{
			if (outlet[j] == order[i]) {
				check = false;
				break;
			}
		}
		if (!check)continue;
		for (int j = 0; j < n; j++)
		{
			if (outlet[j] == 0) {
				outlet[j] = order[i];
				check = false;
				break;
			}
		}
		if (!check)continue;

		int cur=-123456789;
		int next=-123456789;

		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			for (int l = i+1; l < k; l++)
			{
				if (outlet[j] == order[l])break;
				++temp;
			}
			if (temp > next) {
				next = temp;
				cur = j;
			}
		}
		outlet[cur] = order[i];
		cnt++;
	}
	cout << cnt;
}