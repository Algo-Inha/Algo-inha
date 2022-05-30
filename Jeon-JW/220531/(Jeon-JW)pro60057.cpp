//https://programmers.co.kr/learn/courses/30/lessons/60057
//���ڿ� ����
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.size(); // s���ڿ��� ����
	for (int i = 1; i <= s.size() / 2; i++) { // i�� ������ ����
		string str1, str2; // str1�� �ٲ� ���ڿ�, str2�� ������ ���ڿ�
		int count = 1; // �ݺ��Ǵ� ������ ���ڿ��� �־��� ����
		str2 = s.substr(0, i); // 0���� i������ �������� ����
		for (int j = i; j < s.size(); j += i) { // j�� ���� Ȯ��
			if (str2 == s.substr(j, i)) count++; // ������ ������ count ++
			else { // ������ ������ ��
				if (count > 1) str1 += to_string(count); // count�� 1�̻��̸� ���ڸ� �־���
				// �ٽ� ���� �ʱ�ȭ
				str1 += str2;
				str2 = s.substr(j, i);
				count = 1;
			}
		}
		if (count > 1) str1 += to_string(count);
		str1 += str2;
		if (answer > str1.size()) answer = str1.size();
	}
	return answer;
}