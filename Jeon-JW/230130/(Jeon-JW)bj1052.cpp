//https://www.acmicpc.net/problem/1052
//¹°º´
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, K;
int ans;

int main() {

	cin >> N >> K;
	if (K >= N) {
		cout << 0;
		return 0;
	}
	
	for (;;) {
		int cnt = 0;
		int temp = N;
		while (temp > 0) {
			if (temp % 2 == 0) temp /= 2;
			else { temp /= 2; cnt++; }
		}
		if (K >= cnt) break;

		N++;
		ans++;
	}
	cout << ans;



	return 0;
}