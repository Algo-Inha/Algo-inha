//https://www.acmicpc.net/problem/2504
//��ȣ�� ��
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
			if (st.empty() || st.top() != '(') { // ��ȣ�� ����� �������� ���� ���
				ans = 0;
				break;
			}
			else if (str[i - 1] == '(') { // ����� ���
				ans += temp;
				temp /= 2; // ������ �����ذ� ���ֱ�
				st.pop();
			}
			else {
				temp /= 2;
				st.pop();
			}
		}
		else {
			if (st.empty() || st.top() != '[') { // ��ȣ�� ����� �������� ���� ���
				ans = 0;
				break;
			}
			else if (str[i - 1] == '[') { // ����� ���
				ans += temp;
				temp /= 3; // ������ �����ذ� ���ֱ�.
				st.pop();
			}
			else {
				temp /= 3;
				st.pop();
			}
		}

	}

	if (!st.empty()) ans = 0; // ��ȣ�� ����� ������ ���� ���.

	cout << ans;

	return 0;
}