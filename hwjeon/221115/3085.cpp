#include <iostream>
#include <algorithm>
using namespace std;

int N, maxnum = -1;
string board[52];

void check() {
	int cnt = 1, cnt2 = 1;
	for (int k = 0; k < N; k++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[k][j] == board[k][j + 1]) cnt++;
			else cnt = 1;
			maxnum = max(maxnum, cnt);
		}
		cnt = 1;
	}
	for (int p = 0; p < N; p++) {
		for (int j = 0; j < N - 1; j++) {
			if (board[j][p] == board[j + 1][p])cnt2++;
			else cnt2 = 1;
			maxnum = max(maxnum, cnt2);
		}
		cnt2 = 1;
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (i < N - 1 && j < N - 1) {
				swap(board[i][j], board[i + 1][j]);
				check();
				swap(board[i][j], board[i + 1][j]);
				swap(board[i][j], board[i][j + 1]);
				check();
				swap(board[i][j], board[i][j + 1]);
			}
			else if (i == N - 1 && j != N - 1) {
				swap(board[i][j], board[i][j + 1]);
				check();
				swap(board[i][j], board[i][j + 1]);
			}
			else if (j == N - 1 && i != N - 1) {
				swap(board[i][j], board[i + 1][j]);
				check();
				swap(board[i][j], board[i + 1][j]);
			}
	}
	cout << maxnum << "\n";
}
