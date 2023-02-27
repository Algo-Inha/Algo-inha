//ฟ๋พื
//https://www.acmicpc.net/problem/2467


#include<iostream>

using namespace std;

int li[100001];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	int start = 0;
	int end = n - 1;

	int tstart=start;
	int tend=end;

	while (abs(li[start] + li[end]) != 0 && start<end) {
		int temp = (li[start] + li[end]);
		if (abs(temp) < abs((li[tstart] + li[tend]))) {
			tstart=start;
			tend=end;
		}
		if (abs(start - end) == 1)break;
		if (temp > 0) {
			--end;
		}
		else if(temp < 0) ++start;
	}


	if (abs(li[start] + li[end]) < abs((li[tstart] + li[tend]))) {
		cout << li[start] << " " << li[end];
	}
	else {
		cout << li[tstart] << " " << li[tend];
	}
}