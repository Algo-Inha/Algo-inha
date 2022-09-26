//올림픽
//https://www.acmicpc.net/problem/8979
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct st {
	int num;
	int gold;
	int silver;
	int bronze;
};

int N,K;
st arr[1001];

bool cmp(st first, st second) {
	if (first.gold > second.gold) return true;
	else if (first.gold == second.gold) {
		if (first.silver > second.silver) return true;
		else if (first.silver == second.silver) {
			if (first.bronze > second.bronze) return true;
		}
	}

	return false;
}


int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].num >> arr[i].gold >> arr[i].silver >> arr[i].bronze;
	}

	sort(arr, arr + N, cmp);

	int temp; // 찾은 순위
	for (int i = 0; i < N; i++) {
		if (arr[i].num == K) {
			temp = i;
			break;
		}
	}
	int temp2 = 0; // 앞으로 갈 수 있는지 순위
	for (int i = temp - 1;i >= 0; i--) {
		if (arr[i].gold != arr[temp].gold || arr[i].silver != arr[temp].silver || arr[i].bronze != arr[temp].bronze) {
			break;
		}
		temp2++;
	}
	cout << temp - temp2 + 1 << '\n';

	return 0;
}