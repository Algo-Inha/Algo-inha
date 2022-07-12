//124나라의 숫자
#include<iostream>
#include<string>
using namespace std;

string solution(int n) {
	string answer = "";
	int qoutient = n;
	int remainder = 0;

	for (;;) {
		remainder = qoutient % 3;
		qoutient = qoutient / 3;

		if (remainder == 0) {
			answer = "4" + answer;
			qoutient--; // 나머지가 0==3 일때와 같으므로 몫을 1 빼준다.
		}
		else if (remainder == 1) {
			answer = "1" + answer;
		}
		else if (remainder == 2)
		{
			answer = "2" + answer;
		}

		if (qoutient == 0)
		{
			break;
		}
	}
	return answer;
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);
}