//https://www.acmicpc.net/problem/1063
//킹
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int N;
int map[9][9];
int stone[2];
int king[2];
int dir[8][2] = {
	{0,1},{0,-1},{-1,0},{1,0},
	{1,1},{1,-1},{-1,1},{-1,-1}
};
string dir_str[8] = {
	"R", "L", "B", "T", "RT", "LT", "RB", "LB"
};

int main() {

	string str1;
	cin >> str1;
	king[0] = str1[1] - '0';
	king[1] = str1[0] - 'A' + 1;
	cin >> str1;
	stone[0] = str1[1] - '0';
	stone[1] = str1[0] - 'A' + 1;
	cin >> N;
	//cout << king[0] << king[1] << stone[0] << stone[1] << endl;

	int temp;
	for (int test_case = 0; test_case < N; test_case++) {
		cin >> str1;
		for (int i = 0; i < 8; i++) {
			if (dir_str[i] == str1) {
				temp = i;
				break;
			}
		}
		int dy = king[0] + dir[temp][0];
		int dx = king[1] + dir[temp][1];

		if (dy == stone[0] && dx == stone[1]) {
			int stone_dy = stone[0] + dir[temp][0];
			int stone_dx = stone[1] + dir[temp][1];
			if (stone_dy <= 0 || stone_dx <= 0 || stone_dy > 8 || stone_dx > 8) continue;
			stone[0] = stone_dy;
			stone[1] = stone_dx;
		}

		if (dy <= 0 || dx <= 0 || dy > 8 || dx > 8) continue;
		king[0] = dy;
		king[1] = dx;
		/*cout << king[0] << " " << king[1] << endl;
		cout << stone[0] << " " << stone[1] << endl;*/
	}

	//cout << king[0] << " " << king[1] << endl;
	//cout << stone[0] << " " << stone[1] << endl;

	cout << char(king[1] + 64) << king[0] << '\n';
	cout << char(stone[1] + 64) << stone[0] << '\n';


	return 0;
}