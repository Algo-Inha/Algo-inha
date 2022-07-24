//https://www.acmicpc.net/problem/1010
//다리 놓기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, N, M;

int main() {
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		long long answer = 1;
		int temp = 1;
		//조합식
		for (int i = M; i > M - N; i--) {
			answer *= i;
			answer /= temp++;
		}
		cout << answer << "\n";
	}


	return 0;
}