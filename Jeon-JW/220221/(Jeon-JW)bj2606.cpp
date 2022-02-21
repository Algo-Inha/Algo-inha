//https://www.acmicpc.net/problem/2606
//바이러스
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;

vector<int> com[101];
bool check[101];

int ans;

void recur(int num) {
	check[num] = 1;
	ans++;
	//cout << num << endl;
	for (int i = 0; i < com[num].size(); i++) {
		if (check[com[num][i]] == 0) {
			recur(com[num][i]);
		}
	}
}

int main() {

	cin >> n >> m;
	int temp1, temp2;
	for (int i = 0; i < m; i++) {
		cin >> temp1 >> temp2;
		com[temp1].push_back(temp2);
		com[temp2].push_back(temp1);
	}

	recur(1);

	cout << ans-1;

	return 0;
}