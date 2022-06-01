//https://www.acmicpc.net/problem/14500
//테트로미노
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


vector<vector<int>> map(501, vector<int>(501, 0));
int row, col; // 세로, 가로 row, col

int dfs2(int r, int c) { // ㅗ모양 커버
	int answer = 0;

	int val1 = 0; int val2 = 0; int val3 = 0; int val4 = 0; int temp = 0;
	for (int i = 2; i <= row; i++) { // 북
		for (int j = 2; j < col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i][j + 1];
			if (temp > val1) val1 = temp;
		}
	}
	for (int i = 2; i < row; i++) { // 동
		for (int j = 1; j < col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i + 1][j] + map[i][j + 1];
			if (temp > val2) val2 = temp;
		}
	}
	for (int i = 2; i < row; i++) { // 서
		for (int j = 2; j <= col; j++) {
			temp = map[i][j] + map[i - 1][j] + map[i - 1][j] + map[i][j + 1];
			if (temp > val3) val3 = temp;
		}
	}
	for (int i = 1; i < row; i++) { // 남
		for (int j = 2; j < col; j++) {
			temp = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
			if (temp > val4) val4 = temp;
		}
	}
	answer = max(val1, max(val2, max(val3, val4)));
	return answer;
}


int dfs1(int num, vector<vector<int>> check, int r, int c) {
	if (num == 4) return map[r][c];
	int answer = 0;
	int val1 = 0; int val2 = 0; int val3 = 0; int val4 = 0;
	if (r - 1 > 0 && !check[r - 1][c]) {
		check[r - 1][c] = 1;
		val1 = dfs1(num + 1, check, r - 1, c);
		check[r - 1][c] = 0;
	}
	if (c + 1 <= col && !check[r][c + 1]) {
		check[r][c + 1] = 1;
		val2 = dfs1(num + 1, check, r, c + 1);
		check[r][c + 1] = 0;
	}
	if (r + 1 <= row && !check[r + 1][c]) {
		check[r + 1][c] = 1;
		val3 = dfs1(num + 1, check, r + 1, c);
		check[r + 1][c] = 0;
	}
	if (c - 1 > 0 && !check[r][c - 1]) {
		check[r][c - 1] = 1;
		val4 = dfs1(num + 1, check, r, c - 1);
		check[r][c - 1] = 0;
	}

	answer = max(val1, max(val2, max(val3, val4))) + map[r][c];

	return answer;
}


int solution() {
	int answer = 0;
	vector<vector<int>> check(501, vector<int>(501, 0)); // 확인했는지.
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			check[i][j] = 1;
			temp1 = dfs1(1, check, i, j);
			check[i][j] = 0;
			if (temp1 > answer) answer = temp1;
		}
	}
	temp2 = dfs2(1, 1);
	answer = max(temp2, answer);
	return answer;
}



int main() {
	cin >> row >> col;

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}

	cout << solution() << endl;

	return 0;
}