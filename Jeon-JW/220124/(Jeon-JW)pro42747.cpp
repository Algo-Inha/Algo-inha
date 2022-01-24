// https://programmers.co.kr/learn/courses/30/lessons/42747
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int n = citations.size();
	sort(citations.rbegin(), citations.rend());//�ο�� Ƚ�� ��������
	for (int i = 0; i < n; i++) {
		if (citations[i] > i) {// ���� ���� �� ���� �� ���ο�Ƚ���� �� �������� Ŭ ��
			answer = i + 1;
		}
	}
	return answer;
}