//https://www.acmicpc.net/problem/3020
//개똥벌레
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, H;

int main() {

	cin >> N >> H;
	vector<int> bottom(N / 2);
	vector<int> top(N / 2);
	for (int i = 0; i < N / 2; i++) {
		cin >> bottom[i] >> top[i];
	}

	// lower_bound, upper_bound를 사용하기 위해서는 오름차순 정렬이 되어있어야한다.
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());


	int answer = 999999999;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {
		//해당 높이에 겹치는 석순
		//lower_bound(bottom.begin(), bottom.end(), i) - bottom내부에서 i보다 같거나 큰숫자가 몇번째에 처음 등장하는지
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		//해당 높이에 겹치는 종유석
		//upper_bound(top.begin(), top.end(), H - i) - top내부에서 H-i보다 같거나 작은 숫자가 몇번째에 처음 등장하는지
		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		//temp에는 결국 해당 높이에 겹치는 석순과 종유석이 저장되게 된다.

		if (answer == temp)// 맨 처음에는 안된다.
			cnt++;
		else if (answer > temp) { // temp라는 높이에 몇개의 cnt가 쌓이게 되는지 
			answer = temp;
			cnt = 1;
		}
	}
	cout << answer << " " << cnt;

	return 0;
}