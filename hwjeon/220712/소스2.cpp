//잃어버린 괄호
//stoi
#include<iostream>
#include<string>
using namespace std;

int main() {
	string expression;
	int minus_check = 0; //-가 한번 나온 순간 모든 부호가 -여야 최솟값을 가짐
	string number;
	int answer=0;

	cin >> expression;
	for (int i = 0; i <= expression.size(); i++)
	{

		if (expression[i] == '-' || expression[i] == '+'||i==expression.size()) { // 수식은 숫자가 마지막에 오므로 
			if (minus_check==1)                                                   // i가 가 size와 같을 때 에도 if문이 성립해야한다 
			{
				answer -= stoi(number); //stoi함수로 string을 int꼴로 표현한다.
				number = ""; //초기화 해주지 않으면 추가만 된다.
			}
			else {
				answer += stoi(number);
				number = "";
			}
		}
		else
			number += expression[i];

		if ((int)expression[i] == 45)
		{
			minus_check = 1;
		}
	}
	cout << answer;
}