//https://www.acmicpc.net/problem/1654
//랜선 자르기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, K;
vector<long> lines;
long ans;

int main() {

	cin >> K >> N;
	
	long temp;
	for (int i = 0; i < K; i++) {
		cin >> temp;
		lines.push_back(temp);
	}

	long start = 1;
	long end = *max_element(lines.begin(), lines.end());
	while (start <= end) {
		long total = 0; // 자른 랜선의 개수
		long mid = (start + end) / 2;
		for (int i = 0; i < K; i++) {
			total += lines[i] / mid;
		}
		if (total < N) {
			end = mid - 1; // 기대치보다 적을 경우 좀 더 자르기위해 end를 줄여줌.
		}
		else {
			start = mid + 1; // 조금 더 나은 결과를 위해서 start를 땡겨준다.
			ans = mid;
		}
	}

	cout << ans;

	return 0;
}