//https://www.acmicpc.net/problem/1449
//¼ö¸®°ø Ç×½Â
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, L;
vector<int> v;
int ans;

int main() {

	cin >> N >> L;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int pivot = v[0];

	for (int i = 1; i < N; i++) {
		if (v[i] - pivot + 1 > L) {
			ans++;
			pivot = v[i];
		}
	}

	cout << ans + 1;

	return 0;
}