//백준 주사위굴리기
//https://www.acmicpc.net/problem/14499
#include<iostream>

using namespace std;

int map[21][21];
int n, m;
int x, y;
int k;
int dice[6];
int main() {
	cin >> n >> m >> x >> y>>k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	pair<int, int>cur({ x,y });

	while (k--) {
		int ins;
		int xx, yy;
		xx = cur.first;
		yy = cur.second;

/*
				   2
				 4 1 3
				   5
				   6
*/

		cin >> ins;
		if (ins == 1) {
			if (yy < m-1) {
				cur.second++;
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 2) {
			if (yy > 0) {
				cur.second--;
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 3) {
			if (xx > 0) {
				cur.first--;
				int temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
		if (ins == 4) {
			if (xx < n - 1) {
				cur.first++;
				int temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;

				if (map[cur.first][cur.second]) {
					dice[5] = map[cur.first][cur.second];
					map[cur.first][cur.second] = 0;
				}
				else if (!map[cur.first][cur.second]) {
					map[cur.first][cur.second] = dice[5];
				}
				cout << dice[0] << endl;
			}
		}
	}

	

}