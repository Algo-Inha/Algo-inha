//외계인의 기타 연주
//https://www.acmicpc.net/problem/2841

#include<iostream>
#include<stack>

using namespace std;

stack<int>guitar[7];
int n, p;
int s, l;
int res;

int  main() {
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> l;
		if (guitar[s].empty()) {
			guitar[s].push(l);
			res++;
		}
		else if (!guitar[s].empty() && guitar[s].top() == l) continue;
		else if (!guitar[s].empty() && guitar[s].top() < l) {
			guitar[s].push(l);
			res++;
		}
		else if (!guitar[s].empty() && guitar[s].top() > l) {
			while (!guitar[s].empty() && guitar[s].top() > l) {
				guitar[s].pop();
				res++;
			}
			if (!guitar[s].empty() && guitar[s].top() == l)continue;
			else {
				guitar[s].push(l);
				res++;
			}
		}
	}
	cout << res;
}