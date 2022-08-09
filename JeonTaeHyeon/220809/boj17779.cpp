//게리멘더링 2
//https://www.acmicpc.net/problem/17779
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

const int INF = INT_MAX;
int N;
int map[21][21];

int diff(int x, int y, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0] += map[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1] += map[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += map[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += map[r][c];
			}
			//5번 선거구
			else {
				population[4] += map[r][c];
			}
		}
	}

	sort(population.begin(), population.end());

	return population[4] - population[0];
}

int minDiff() {
	int res = INF;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					res = min(res, diff(x, y, d1, d2));
				}
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}

	cout << minDiff() << endl;
}