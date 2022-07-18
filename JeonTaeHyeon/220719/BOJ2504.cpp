//BOJ2504 괄호의 값
//https://www.acmicpc.net/problem/2504
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

string input;
stack<char> pa;
int res;
int cal;
bool error;

int main() {
	cin >> input;
	cal = 1;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(') {
			cal *= 2;
			pa.push(input[i]);
		}
		else if (input[i] == '[') {
			cal *= 3;
			pa.push(input[i]);
		}

		else if (input[i] == ')') {
			if (pa.empty()||pa.top() != '(' )
			//if (pa.top() != '(' ||pa.empty()) 순서로 작성하면 런타임 에러가 발생하는데 이유가 뭔지 모르겠음
			{
				error = true;
				break;
			}
			if (input[i - 1] == '(') res += cal;//값이 결정되는 경우
			cal /= 2;
			pa.pop();
		}

		else if (input[i] == ']') {
			if (pa.empty()||pa.top() != '[' ) {
				error = true;
				break;
			}
			if (input[i - 1] == '[') res += cal;
			cal /= 3;
			pa.pop();
		}

	}

	if (error||pa.size())cout << "0";
	else cout << res;

}