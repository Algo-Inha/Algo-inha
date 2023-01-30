#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int arr[10];
int num[10];

void seq(int x, int len) {
	if (len == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << endl;
		return;
	}

	int last = 0;

	for (int i = x; i < n; i++) {
		if (num[i] != last) {
			arr[len] = num[i];
			last = arr[len];
			seq(i, len + 1);
		}
	}

	return;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	seq(0, 0);

	return 0;
}