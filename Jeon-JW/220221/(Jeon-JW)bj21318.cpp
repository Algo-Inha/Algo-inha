//https://www.acmicpc.net/problem/21318
//피아노 체조
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n;
vector<int> a;
int q;
//vector<pair<int, int>> b;
//vector<int> cnt; //런타임 에러
int cnt[100001];
vector<int> ans;

int main() {
	// make async (istream & ostream)
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int temp, temp1;

	/*cin >> temp;
	a.push_back(temp);
	cnt.push_back(0);*/
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
		if (i == 0) continue;
		if (a[i - 1] > temp) cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> temp >> temp1;
		/*b.push_back(make_pair(temp, temp1));*/
		//ans.push_back(cnt[temp1-1] - cnt[temp-1]);
		cout << cnt[temp1 - 1] - cnt[temp - 1] << '\n'; // 매우 나쁜 endl
	}


	//완전탐색 불가
	/*for (int i = 0; i < q; i++) {
		int answer = 0;
		int x = b[i].first;
		int y = b[i].second;

		int max_num = 0;
		for (int j = x - 1; j < y-1; j++) {
			if (a[j] > max_num) max_num = a[j];
			if (a[j] < max_num) answer++;
		}
		if(a[x-1] < max_num) answer++;
		if (a[x - 1] < a[x]) answer++;


		ans.push_back(answer);
	}*/

	/*for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}*/

	return 0;
}