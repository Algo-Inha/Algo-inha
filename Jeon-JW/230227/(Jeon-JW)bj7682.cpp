//https://www.acmicpc.net/problem/7682
//∆Ω≈√≈‰
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string str;
int numo, numx;
bool O, X;


bool Owin() {
	bool flag = 0;
	if (str[0] == 'O' && str[3] == 'O' && str[6] == 'O') flag = 1;
	else if (str[1] == 'O' && str[4] == 'O' && str[7] == 'O') flag = 1;
	else if (str[2] == 'O' && str[5] == 'O' && str[8] == 'O') flag = 1;
	
	else if (str[0] == 'O' && str[1] == 'O' && str[2] == 'O') flag = 1;
	else if (str[3] == 'O' && str[4] == 'O' && str[5] == 'O') flag = 1;
	else if (str[6] == 'O' && str[7] == 'O' && str[8] == 'O') flag = 1;

	else if (str[0] == 'O' && str[4] == 'O' && str[8] == 'O') flag = 1;
	else if (str[2] == 'O' && str[4] == 'O' && str[6] == 'O') flag = 1;

	return flag;
}
bool Xwin() {
	bool flag = 0;
	if (str[0] == 'X' && str[3] == 'X' && str[6] == 'X') flag = 1;
	else if (str[1] == 'X' && str[4] == 'X' && str[7] == 'X') flag = 1;
	else if (str[2] == 'X' && str[5] == 'X' && str[8] == 'X') flag = 1;

	else if (str[0] == 'X' && str[1] == 'X' && str[2] == 'X') flag = 1;
	else if (str[3] == 'X' && str[4] == 'X' && str[5] == 'X') flag = 1;
	else if (str[6] == 'X' && str[7] == 'X' && str[8] == 'X') flag = 1;

	else if (str[0] == 'X' && str[4] == 'X' && str[8] == 'X') flag = 1;
	else if (str[2] == 'X' && str[4] == 'X' && str[6] == 'X') flag = 1;

	return flag;
}


int main() {

	
	for (;;) {
		cin >> str;
		if (str == "end") break;
		numo = 0; numx = 0;
		O = 0; X = 0;

		for (int i = 0; i < 9; i++) {
			if (str[i] == 'O') numo++;
			if (str[i] == 'X') numx++;
		}

		O = Owin();
		X = Xwin();

		if (O && !X && numo == numx) cout << "valid" << endl;
		else if (!O && X && numx - numo == 1) cout << "valid" << endl;
		else if (!O && !X && numx == 5 && numo == 4) cout << "valid" << endl;
		else cout << "invalid" << endl;

	}


	return 0;
}