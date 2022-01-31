//https://programmers.co.kr/learn/courses/30/lessons/87390s
#include <string>
#include <vector>

using namespace std;

//숫자 상 직접 만드는 건 절~대아님
vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;
	int temp;
	for (long long i = left; i <= right; i++) {
		if (i%n <= i / n) {
			answer.push_back(i / n + 1);
		}
		else {
			answer.push_back(i%n + 1);
		}
	}

	return answer;
}