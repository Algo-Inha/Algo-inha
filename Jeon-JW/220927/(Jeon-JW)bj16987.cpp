//https://www.acmicpc.net/problem/16987
//������� ���ġ��
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N;
int ans;
vector<pair<int, int>> eggs;
int pivot;

void recur(int cnt) {
	if (cnt == N) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (eggs[i].first <= 0)temp++;
		}
		ans = max(ans, temp);
		return;
	}
	
	//����� �̹� �������� �� �������� �ѱ�.
	if (eggs[cnt].first <= 0) {
		recur(cnt + 1);
		return;
	}

	//�� �����
	bool flag = 0;
	for (int i = 0; i < N; i++) {
		if (i == cnt) continue;
		if (eggs[i].first > 0) {
			flag = 1;
			eggs[cnt].first -= eggs[i].second;
			eggs[i].first -= eggs[cnt].second;

			recur(cnt + 1);

			eggs[cnt].first += eggs[i].second;
			eggs[i].first += eggs[cnt].second;
		}
	}

	if (!flag) recur(cnt + 1);
}


int main() {
	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		eggs.push_back(make_pair(temp1, temp2));
	}

	recur(0);

	cout << ans;

	return 0;
}