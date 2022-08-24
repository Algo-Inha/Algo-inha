#include<iostream>
#include<stack>
#include<string>
using namespace std;

string input;

int cur;
int res;

int main() {
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ')') {
			if (input[i - 1] == '(') {
				cur--;
				res--;
				res += cur;
			}
			else {
				cur--;
			}
		}
		if (input[i] == '(') {
			++cur;
			++res;
		}
	}
	cout << res;
}