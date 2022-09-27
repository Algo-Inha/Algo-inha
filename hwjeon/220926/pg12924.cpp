#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int num = (n + 1) / 2;

	int sum = 0, answer = 1, j = 1;



	for (int i = 1; i <= num; i++) {

		sum += i;

		if (sum >= n) {

			while (sum > n) sum -= j++;

			if (sum == n) answer++;

		}

	}

	return n != 1 ? answer : 1;
}