//BOJ2504 ��ȣ�� ��
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
			//if (pa.top() != '(' ||pa.empty()) ������ �ۼ��ϸ� ��Ÿ�� ������ �߻��ϴµ� ������ ���� �𸣰���
			{
				error = true;
				break;
			}
			if (input[i - 1] == '(') res += cal;//���� �����Ǵ� ���
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