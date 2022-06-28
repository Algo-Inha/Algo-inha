//줄 서는 방법
/*#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<int> test(n);
	for (int i = 1; i <= n; i++) {
		test[i-1] = i;
	}
	int cnt = 1;
	do {
		if (cnt == k) {
			for (auto a = test.begin();a!=test.end();a++) {
				answer.push_back(*a);
			}
			break;
		}
		cnt++;
	} while (next_permutation(test.begin(), test.end()));
	return answer;
}*/ //틀린풀이

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long fact(int n)
{
	if (n == 0) return 1;
	return n * fact(n - 1);
}

void func(vector<int>& v, vector<int>& answer, long long k)
{
	if (v.size() == 1) {
		answer.push_back(v[0]);
		return;
	}

	long long f = fact(v.size() - 1);
	for (int i = 1; i <= v.size(); ++i) {
		if (i * f >= k) {
			answer.push_back(v[i - 1]);
			v.erase(v.begin() + i - 1);
			k = k - (i - 1) * f;
			func(v, answer, k);
		}
	}
}

vector<int> solution(int n, long long k)
{
	vector<int> answer;

	vector<int> v(n);
	for (int i = 1; i <= n; ++i)
		v[i - 1] = i;

	func(v, answer, k);

	return answer;
}