//https://www.acmicpc.net/problem/10799
//�踷���
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>

using namespace std;

stack<char> s;
string str;
int ans;

int main() {

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else if (str[i] == ')' && str[i - 1] == '(') { // ������
			s.pop();
			ans += s.size();
		}
		else { // ) ������
			ans++;
			s.pop();
		}
	}

	cout << ans;

	return 0;
}