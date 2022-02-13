// https://www.acmicpc.net/problem/2624
// ���� �ٲ��ֱ�
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t; // ������ �ݾ�
int k; // ������ ���� ��
vector<pair<int, int>> pn; // ������ �ݾ�, ����
int dp[10001]; // ����� ��
int main() {

	cin >> t;
	cin >> k;

	int temp1, temp2;
	for (int i = 0; i < k; i++) {
		cin >> temp1 >> temp2;
		pn.push_back(make_pair(temp1, temp2));
	}
	sort(pn.begin(), pn.end()); // ���� �������� ����

	/*for (int i = 0; i < pn.size(); i++) {
		cout << pn[i].first << " " << pn[i].second << endl;
	}*/
	dp[0] = 1;
	//n���� �� ����ϰ� �ִ� ������ ��ġ�� v, �� ������ c�� �Ѵٸ� dp[n] += dp[n - v * c]
	//������������ ä��� �̹� �ش� �������� ������ ����� �� ���̺� ���� �ߺ����� ����� �ǹǷ� ū �ݾ׺��� ������������ ���̺��� ä�������� �Ѵ�.
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