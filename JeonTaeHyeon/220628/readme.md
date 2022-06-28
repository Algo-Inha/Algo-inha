
# 문제풀이
## 입국 심사
https://programmers.co.kr/learn/courses/30/lessons/43238
<!--line-->
 ```c++
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

 ```
이분 탐색 문제를 많이 접해보지 않아 처음에 DP로 풀려고 했으나 숫자가 너무 커서 DP로 풀 수 없다고 생각해 풀이를 참고해서 이분 탐색으로 해결했습니다. 최소시간 min과 최대시간 max를 사용하여 푼다는 생각을 할 수 있다면 어렵지 않게 풀 수 있을 것 같습니다.

## 절댓값 힙
https://www.acmicpc.net/problem/11286
```c++
//절댓값 힙
priority_queue <int> po;
priority_queue <int> ne;
int n; int number;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		if (number > 0) {
			po.push(-number);
		}//
		else if (number < 0){
			ne.push(number);
		}
		else {
			if (po.empty() && ne.empty())cout << "0\n";
			else if (po.empty()) {
				cout << ne.top()<<endl;
				ne.pop();
			}
			else if (ne.empty()) {
				cout << -po.top() << endl;
				po.pop();
			}
			else {
				if (po.top() > ne.top()) {
					cout << -po.top() << endl;
					po.pop();
				}
				else {
					cout << ne.top() << endl;
					ne.pop();
				}
			}
			
		}
	}
}
```
2개의 pq를 선언하여 양수는 -를 사용하여 오름차순으로 정렬 이후에 문제의 조건에 맞게 pop해주면 해결할 수 있는 문제였습니다.

## 줄서는 방법
https://programmers.co.kr/learn/courses/30/lessons/12936
```c++
//줄 서는 방법
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
```
처음에는 next_permutation함수를 사용하여 해결하려헀지만 효율성 테스트에서 0점을 맞고 풀이를 참조해서 풀었습니다. k의 크기에 따라 각 자릿수에 무엇이 올지 factorial를 사용하여 유추하여 답을 만들면 훨씬 더 optimal한 시간에 답을 얻을 수 있었습니다.
## 튜플
https://programmers.co.kr/learn/courses/30/lessons/64065
```c++
// 튜플
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int num = 0;
	vector<int> temp;
	vector<pair<int, vector<int>>> current;
	for (int i = 2; i < s.size() - 1; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
			num *= 10;
			num += (s[i] - '0');
		}
		else if (s[i] == ',') {
			if (s[i - 1] == '}') {
				continue;
			}
			temp.push_back(num);
			num = 0;
		}
		else if (s[i] == '}') {
			temp.push_back(num);
			current.push_back({temp.size(), temp });
			num = 0;
			temp.clear();
		}
	}
	sort(current.begin(), current.end());

	set<int> res;
	for (pair<int, vector<int>> p : current) {
		for (int num : p.second) {
			if (res.find(num) == res.end()) {
				res.insert(num);
				answer.push_back(num);
			}
		}
	}
	return answer;
}
```
s에 저장된 값을 분리하고 sort한 후, 중복을 제거하기 위해 하나씩 push_back해주는 방법으로 해결했습니다.  
