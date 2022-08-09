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

		//짝수인 경우 +1
		if (num % 2 == 0) {
			answer.push_back(num + 1);
			continue;
		}

		//맨 앞이 0인 자리 찾기
		while ((temp & 1) == 1) {
			temp = temp >> 1;
			pos++;
		}

		//홀수인 경우 맨 앞자리 0을 1로, 그 다음 오른쪽 자리 1을 0으로 바꿔줌
		num += pow(2, pos) - pow(2, pos - 1);

		answer.push_back(num);
	}
	return answer;
}