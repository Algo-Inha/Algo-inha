#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;

void res(int size, int cur, int sum, int target, vector<int>v) {
	if (cur == size) {
		if (sum == target) {
			++ans;
		}
		return;
	}
	int temp = v[cur];

	res(size, cur + 1, sum + temp, target, v);
	res(size, cur + 1, sum - temp, target, v);
}

int solution(vector<int> numbers, int target) {
	res(numbers.size(), 0, 0, target, numbers);
	int answer = ans;
	return answer;
}