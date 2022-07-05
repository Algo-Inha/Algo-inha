//https://www.acmicpc.net/problem/2805
//나무 자르기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
vector<int> trees;
long long max_len = 1000000000;
int ans;

int main() {

	cin >> N >> M; // 나무의 수, 나무의 길이

	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		trees.push_back(temp);
	}

	int start = 0; // 나무길이의 최소값
	int end = *max_element(trees.begin(), trees.end()); // 나무길이의 최대값
	while (start <= end) {
		long long total = 0;
		int mid = (start + end) / 2; // 이분탐색을 통해 적정히 밸 나무의 길이를 설정.
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid) total += trees[i] - mid;
		}
		if (total < M) {
			end = mid - 1; // 기대치보다 적을 경우 좀 더 자르기위해 end를 줄여줌.
		}
		else {
			ans = mid; // 기대치를 만족했을 경우 값을 넣어두고
			start = mid + 1; // 조금 더 나은 결과를 위해서(상근이는 자연을 사랑하니까) start를 땡겨준다.
		}
	}
	cout << ans;

	return 0;
}