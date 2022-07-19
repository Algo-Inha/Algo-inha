//괄호의 값
//스택 

#include<iostream>
#include<string>
#include<stack>

using namespace std;



int main() {
	string str;
	stack<char> s;
	cin >> str;

	int answer = 0, temp = 1;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i]==')')
		{
			if (s.empty()||s.top()!='(')
			{
				answer = 0;
				break;
			}
			if (str[i-1]=='(')
			{
				answer += temp;
				temp /= 2;
				s.pop();
			}
			else
			{
				temp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				answer = 0;
				break;
			}
			if (str[i - 1] == '[')
			{
				answer += temp;
				temp /= 3;
				s.pop();
			}
			else
			{
				temp /= 3;
				s.pop();
			}
		}
		

	}
	if (!s.empty()) answer = 0;
	cout << answer << endl;
}