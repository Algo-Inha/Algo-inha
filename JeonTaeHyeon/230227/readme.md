
﻿# 문제풀이
## 용액

https://www.acmicpc.net/problem/2467

```c++
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
 ```
그동안 투포인터 문제를 여러번 풀어봐서 그런지 문제를 보자마자 투포인터로 접근해야 겠다는 생각을 했습니다. 답이 여러개일 수 있다는 사실을 나중에 확인해서 코드를 계속 수정하다가 시간을 많이 잡아먹었습니다.


##  틱택토(실패)
https://www.acmicpc.net/problem/7682
```c++
#include<iostream>

using namespace std;

string t;

char check() {
	char v='n';
	if (t[0] != '.' && t[0] == t[1] && t[0] == t[2])v = t[0];
	if (t[3] != '.' && t[3] == t[4] && t[3] == t[5]) {
		if (v != 'n')return 'd';
		v = t[3];
	}
	if (t[6] != '.' && t[6] == t[7] && t[6] == t[8]) {
		if (v != 'n')return 'd';
		v = t[6];
	}
	if (t[0] != '.' && t[0] == t[3] && t[0] == t[6]) {
		if (v != 'n')return 'd';
		v = t[0];
	}
	if (t[1] != '.' && t[1] == t[4] && t[1] == t[7]) {
		if (v != 'n')return 'd';
		v = t[1];
	}
	if (t[2] != '.' && t[2] == t[5] && t[2] == t[8]) {
		if (v != 'n')return 'd';
		v = t[2];
	}
	if (t[0] != '.' && t[0] == t[4] && t[0] == t[8]) {
		if (v != 'n')return 'd';
		v = t[0];
	}
	if (t[2] != '.' && t[2] == t[4] && t[2] == t[6]) {
		if (v != 'n')return 'd';
		v = t[2];
	}
	return v;
}


int main() {
	char v = 'n';
	int o = 0, x = 0;
	while (true) {
		v = 'n'; o = 0, x = 0;
		cin >> t;
		if (t == "end")break;
		for (int i = 0; i < 9; i++)
		{
			if (t[i] == 'X')++x;
			if (t[i] == 'O')++o;
		}
		if (abs(x - o) > 1||o>x) { cout << "invalid"<<endl; continue; }
		v = check();
		if (v!='n') {
			if (v == 'd') {
				cout << "invalid" << endl; continue;
			}
			cout << v<<" "<<x<<" "<<o << endl;
			if (v == 'O'&&x>o) {
				cout << "invalid" << endl;
			}
			else if (v == 'X' && x <= o) {
				cout << "invalid" << endl;
			}
			else cout << "valid" << endl;
		}
		else {
			if (x + o == 9) { cout << "valid" << endl; continue; }
			cout << "invalid" << endl;
		}
	}
}
```
모든 예외처리를 하나하나 손으로 해주다가 생각보다 예외가 너무 많아서 다른 방식으로 다시 풀어야 할 것 같습니다.
## 수 묶기

https://www.acmicpc.net/problem/14620
```c++
int main() {
	int n;
	int s[50];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int sum=0;
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
		else if ((i + 1) < n && s[i] > 1 && s[i + 1] > 1 ) {
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
```
두 수가 음수일 때, 0이 섞어있을 때, 둘다 양수일 때를 나눠서 처리를 해주었습니다. 특히 둘 다 양수일 때 다시 한 번 정렬을 해주어서 큰 수끼리 곱해질 수 있도록 하는 것이 중요했습니다.

