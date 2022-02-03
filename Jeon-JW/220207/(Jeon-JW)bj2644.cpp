//https://www.acmicpc.net/problem/2644
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int input1, input2;
int m;
vector<int> v[101];
int visit[101];
int answer;

void dfs(int start, int end, int num) {
	visit[start] = 1;
	if (start == end) {
		answer = num;
	}
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (!visit[next]) {
			dfs(next, end, num + 1);
		}
	}
}

int main() {

	cin >> n;
	cin >> input1 >> input2;
	cin >> m;

	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}

	dfs(input1, input2, 0);
	if (answer != 0) {
		cout << answer << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}