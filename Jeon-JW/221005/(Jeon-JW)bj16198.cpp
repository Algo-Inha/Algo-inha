//https://www.acmicpc.net/problem/16198
//에너지모으기
#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;



int N;
vector<int> W;
int ans;

void re(int sum) {
	if (W.size() == 2) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i < W.size() - 1; i++) {
		int temp = W[i];
		int temp2 = W[i - 1] * W[i + 1];

		W.erase(W.begin() + i); // 참싫은데.
		re(sum + temp2);
		W.insert(W.begin() + i, temp);
	}
}



int main() {
	
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		W.push_back(temp);
	}

	re(0);

	cout << ans;

	return 0;
}