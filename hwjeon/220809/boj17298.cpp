#include<iostream>
#include <stack>
using namespace std;

int a[1000001];
int nge[1000001];
stack<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			nge[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) cout << nge[i] << " ";

	return 0;
}