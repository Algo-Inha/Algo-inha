// https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int n = citations.size();
	sort(citations.rbegin(), citations.rend());//인용된 횟수 내림차순
	for (int i = 0; i < n; i++) {
		if (citations[i] > i) {// 가장 컸을 때 부터 센 논문인용횟수가 논문 개수보다 클 때
			answer = i + 1;
		}
	}
	return answer;
}