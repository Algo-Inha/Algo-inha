//https://www.acmicpc.net/problem/19621
//회의실 배정 2
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N;
vector<int> v1;
vector<int> v2;
vector<int> v3;
int ans;

void recur(int cnt, int sum) {
	if (cnt > N - 1) {
		ans = max(ans, sum);
		return;
	}
	recur(cnt + 1, sum); // 이번 회의 건너뛰기
	recur(cnt + 2, sum + v3[cnt]); // 이번 회의 돌아가기
}

int main() {

	cin >> N;
	int temp1, temp2, temp3;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2 >> temp3;
		v1.push_back(temp1);
		v2.push_back(temp2);
		v3.push_back(temp3);
	}

	recur(0, 0);

	cout << ans;

	return 0;
}