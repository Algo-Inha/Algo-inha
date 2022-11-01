//백준 회문
//https://www.acmicpc.net/problem/17609
#include<iostream>

using namespace std;

int t;
string text;

int res() {
	int start = 0;
	int end = text.size() - 1;

	int check = 1;
	int mod = 0;
	while (start< end) {
		if (text[start] == text[end]) {
			start++; end--;
		}
		else if (text[start] == text[end - 1]) {
			start++; end -= 2;
			mod++;
			if (mod > 1) {
				check = 0;
				break;
			}
		}
		else if (text[start + 1] == text[end]) {
			start += 2; end--;
			mod++;
			if (mod > 1) {
				check = 0;
				break;
			}
		}
		else {
			return 2;
		}
	}

	if (check && mod) {
		return 1;
	}
	else if (!check)return 2;
	else return 0;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> text;
		cout << res() << endl;
	}
}