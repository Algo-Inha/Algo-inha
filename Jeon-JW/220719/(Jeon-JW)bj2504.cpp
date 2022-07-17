//https://www.acmicpc.net/problem/2504
//괄호의 값
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>

using namespace std;


string str;
stack<char> st;
int ans;

int main() {

	cin >> str;

	int temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push('(');
			temp *= 2;
		}
		else if (str[i] == '[') {
			st.push('[');
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') { // 괄호가 제대로 생성되지 않은 경우
				ans = 0;
				break;
			}
			else if (str[i - 1] == '(') { // 상수인 경우
				ans += temp;
				temp /= 2; // 이전에 곱해준거 빼주기
				st.pop();
			}
			else {
				temp /= 2;
				st.pop();
			}
		}
		else {
			if (st.empty() || st.top() != '[') { // 괄호가 제대로 생성되지 않은 경우
				ans = 0;
				break;
			}
			else if (str[i - 1] == '[') { // 상수인 경우
				ans += temp;
				temp /= 3; // 이전에 곱해준거 빼주기.
				st.pop();
			}
			else {
				temp /= 3;
				st.pop();
			}
		}

	}

	if (!st.empty()) ans = 0; // 괄호가 제대로 닫히지 않은 경우.

	cout << ans;

	return 0;
}