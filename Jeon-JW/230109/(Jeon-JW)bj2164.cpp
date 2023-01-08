//https://www.acmicpc.net/problem/2164
//Ä«µå2
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


int N;
queue<int> q;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}

	if (N == 1) { // zz
		cout << 1;
		return 0;
	}

	int temp;
	while(!q.empty()) {
		q.pop();
		if (q.size() == 1) {
			temp = q.front();
			break;
		}
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << temp;

	return 0;
}