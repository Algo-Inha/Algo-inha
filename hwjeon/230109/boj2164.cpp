#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int n;
	queue<int> q;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << endl;

	return 0;
}