#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>
#define size 8

using namespace std;

int saw[4][size];
string input;
int k;

void spin(int num, int dir, int l, int r) {
	if (dir == 1) {
		int left = num - 1;
		int right = num + 1;
		int leftcmp1;
		int leftcmp2;
		int rightcmp1;
		int rightcmp2;
		if (left >= 0) {
			leftcmp1 = saw[num][6];
			leftcmp2 = saw[left][2];
		}
		if (right < 4) {
			rightcmp1 = saw[num][2];
			rightcmp2 = saw[right][6];
		}

		rotate(saw[num], saw[num] + 7, saw[num] + 8);

		if (left >= 0 && leftcmp1 != leftcmp2 && !l) {
			spin(left, -1, 0, 1);
		}
		if (right < 4 && rightcmp1 != rightcmp2 && !r) {
			spin(right, -1, 1, 0);
		}

	}
	if (dir == -1) {
		int left = num - 1;
		int right = num + 1;
		int leftcmp1;
		int leftcmp2;
		int rightcmp1;
		int rightcmp2;
		if (left >= 0) {
			leftcmp1 = saw[num][6];
			leftcmp2 = saw[left][2];
		}
		if (right < 4) {
			rightcmp1 = saw[num][2];
			rightcmp2 = saw[right][6];
		}

		rotate(saw[num], saw[num] + 1, saw[num] + 8);

		if (left >= 0 && leftcmp1 != leftcmp2 && !l) {
			spin(left, 1, 0, 1);
		}
		if (right < 4 && rightcmp1 != rightcmp2 && !r) {
			spin(right, 1, 1, 0);
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++)
	{
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			saw[i][j] = input[j] - '0';
		}
	}

	cin >> k;
	int num, dir;
	while (k--) {
		cin >> num >> dir;
		spin(num - 1, dir, 0, 0);
	}
	int score = 0;
	for (int i = 0; i < 4; i++)
	{
		if (saw[i][0] == 1) {
			if (i == 0) {
				score++;
			}
			if (i == 1) {
				score += 2;
			}
			if (i == 2) {
				score += 4;
			}
			if (i == 3) {
				score += 8;
			}
		}
	}
	cout << score;
}