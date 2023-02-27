//ф╫ецеД
//https://www.acmicpc.net/problem/7682

#include<iostream>

using namespace std;

string t;

char check() {
	char v='n';
	if (t[0] != '.' && t[0] == t[1] && t[0] == t[2])v = t[0];
	if (t[3] != '.' && t[3] == t[4] && t[3] == t[5]) {
		if (v != 'n')return 'd';
		v = t[3];
	}
	if (t[6] != '.' && t[6] == t[7] && t[6] == t[8]) {
		if (v != 'n')return 'd';
		v = t[6];
	}
	if (t[0] != '.' && t[0] == t[3] && t[0] == t[6]) {
		if (v != 'n')return 'd';
		v = t[0];
	}
	if (t[1] != '.' && t[1] == t[4] && t[1] == t[7]) {
		if (v != 'n')return 'd';
		v = t[1];
	}
	if (t[2] != '.' && t[2] == t[5] && t[2] == t[8]) {
		if (v != 'n')return 'd';
		v = t[2];
	}
	if (t[0] != '.' && t[0] == t[4] && t[0] == t[8]) {
		if (v != 'n')return 'd';
		v = t[0];
	}
	if (t[2] != '.' && t[2] == t[4] && t[2] == t[6]) {
		if (v != 'n')return 'd';
		v = t[2];
	}
	return v;
}


int main() {
	char v = 'n';
	int o = 0, x = 0;
	while (true) {
		v = 'n'; o = 0, x = 0;
		cin >> t;
		if (t == "end")break;
		for (int i = 0; i < 9; i++)
		{
			if (t[i] == 'X')++x;
			if (t[i] == 'O')++o;
		}
		if (abs(x - o) > 1||o>x) { cout << "invalid"<<endl; continue; }
		v = check();
		if (v!='n') {
			if (v == 'd') {
				cout << "invalid" << endl; continue;
			}
			cout << v<<" "<<x<<" "<<o << endl;
			if (v == 'O'&&x>o) {
				cout << "invalid" << endl;
			}
			else if (v == 'X' && x <= o) {
				cout << "invalid" << endl;
			}
			else cout << "valid" << endl;
		}
		else {
			if (x + o == 9) { cout << "valid" << endl; continue; }
			cout << "invalid" << endl;
		}
	}
}