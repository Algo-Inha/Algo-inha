//시그널
//https://www.acmicpc.net/problem/16113
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int N;
string str;
//string str0, str1, str2, str3, str4;
char map[5][20001];
string ans = "";

int main() {

	cin >> N;
	cin >> str;
	int divN = N / 5;
	
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < divN; j++) {
			map[i][j] = str[(i * divN) + j];
		}
	}
	for (int i = 0; i < 5; i++) {
		map[i][divN] = 'a';
	}

	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < divN; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < divN;) {
		if (map[0][i] == '#') { // 문자
			//0 1 6 8
			if (map[1][i] == '#' && map[2][i] == '#' && map[3][i] == '#' && map[4][i] == '#') {
				if (map[0][i + 1] == '.' || map[0][i+1] == 'a') {//1
					ans += "1";
					i += 2;
				}
				else if (map[2][i + 1] == '.') { // 0
					ans += "0";
					i += 4;
				}
				else if (map[1][i + 2] == '.') { // 6
					ans += "6";
					i += 4;
				}
				else {
					ans += "8";
					i += 4;
				}
			}
			//3 4 7 9
			else if(map[0][i+2] == '#' && map[1][i + 2] == '#'&& map[2][i + 2] == '#'&& map[3][i + 2] == '#'
				&& map[4][i + 2] == '#') {
				if (map[1][i] == '.') { // 3, 7
					if (map[2][i] == '#') {
						ans += "3";
					}
					else {
						ans += "7";
					}
				}
				else { // 4, 9
					if (map[0][i + 1] == '#') {
						ans += "9";
					}
					else {
						ans += "4";
					}
				}
				i += 4;
			}
			else { // 2 5
				if (map[1][i] == '#') {
					ans += "5";
				}
				else {
					ans += "2";
				}
				i += 4;
			}
		}
		else { // 공백
			i++;
		}
	}

	cout << ans;


	return 0;
}