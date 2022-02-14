// https://www.acmicpc.net/problem/2624
// 동전 바꿔주기
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t; // 지폐의 금액
int k; // 동전의 가지 수
vector<pair<int, int>> pn; // 동전의 금액, 개수
int dp[10001]; // 경우의 수
int main() {

	cin >> t;
	cin >> k;

	int temp1, temp2;
	for (int i = 0; i < k; i++) {
		cin >> temp1 >> temp2;
		pn.push_back(make_pair(temp1, temp2));
	}
	sort(pn.begin(), pn.end()); // 동전 오름차순 정렬

	/*for (int i = 0; i < pn.size(); i++) {
		cout << pn[i].first << " " << pn[i].second << endl;
	}*/
	dp[0] = 1;
	//n원일 때 계산하고 있는 동전의 가치를 v, 그 갯수를 c라 한다면 dp[n] += dp[n - v * c]
	//오름차순으로 채우면 이미 해당 동전으로 이전에 계산이 된 테이블에 대해 중복으로 계산이 되므로 큰 금액부터 내림차순으로 테이블을 채워가도록 한다.
	for (int i = 0; i < k; i++) {
		for (int j = t; j >= 0; j--) {
			for (int k = 1; k <= pn[i].second && j - pn[i].first * k >= 0; k++) {
				dp[j] += dp[j - pn[i].first * k];
			}
		}
	}



	cout << dp[t];

	return 0;
}