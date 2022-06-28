//입국 심사
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());

	long long min = 1;// n * (long long)times.front();
	long long max = n * (long long)times.back();

	while (min <= max) {

		long long avg = (max + min) / 2;
		long long tmp = 0;

		for (int i = 0; i < times.size(); i++) {
			tmp += (avg / (long long)times[i]);
		}

		if (tmp >= n) {
			max = avg - 1;
			answer = avg;
		}
		else min = avg + 1;
	}
	return answer;
}
