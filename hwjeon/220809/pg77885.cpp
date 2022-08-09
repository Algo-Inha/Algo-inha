#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (long long i = 0; i < numbers.size(); i++) {
		long long num = numbers[i];
		long long temp = num;
		int pos = 0;

		//¦���� ��� +1
		if (num % 2 == 0) {
			answer.push_back(num + 1);
			continue;
		}

		//�� ���� 0�� �ڸ� ã��
		while ((temp & 1) == 1) {
			temp = temp >> 1;
			pos++;
		}

		//Ȧ���� ��� �� ���ڸ� 0�� 1��, �� ���� ������ �ڸ� 1�� 0���� �ٲ���
		num += pow(2, pos) - pow(2, pos - 1);

		answer.push_back(num);
	}
	return answer;
}