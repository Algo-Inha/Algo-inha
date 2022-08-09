#include <iostream>
#include <algorithm>
using namespace std;
int n;
int people[21][21];
int answer = 999999999;

void solution(int x, int y, int d1, int d2) {
	if (x + d1 + d2 > n || 1 > y - d1 || y + d2 > n) return;
	else {
		int label[21][21] = { 0 };
		int num[6] = { 0 };

		//5번구역 테두리 라벨링하기
		for (int i = x, j = y; i <= x + d1, j >= y - d1; i++, j--) label[j][i] = 5;
		for (int i = x, j = y; i <= x + d2, j <= y + d2; i++, j++) label[j][i] = 5;
		for (int i = x + d1, j = y - d1; i <= x + d1 + d2, j <= y - d1 + d2; i++, j++) label[j][i] = 5;
		for (int i = x + d2, j = y + d2; i <= x + d2 + d2, j >= y + d2 - d1; i++, j--) label[j][i] = 5;


		//안에 있는 구역 5로 채우기. for문으로 가능할듯.
		for (int y = 0; y <= n; y++) {
			int count = 0;
			int temp[21];
			for (int f = 0; f <= 20; f++)
				temp[f] = label[y][f];
			for (int x = 0; x <= n; x++) {
				if (label[y][x] == 5 && count == 0) {
					//                    cout<<x<<" "<<y<<"\n";
					count++;
				}
				else if (label[y][x] == 0 && count == 1) {
					label[y][x] = 5;
				}
				else if (label[y][x] == 5 && count == 1) {
					count++;
				}
				if (count == 2)
					break;
			}
			if (count == 1) {
				for (int f = 0; f <= 20; f++)
					label[y][f] = temp[f];
			}
		}



		//1,2,3,4 라벨링
		for (int i = 1; i <= n; i++) {//x
			for (int j = 1; j <= n; j++) {//y
				if (label[j][i] == 0) {
					if (1 <= i && i < x + d1 && j >= 1 && j <= y && label[j][i] != 5) label[j][i] = 1;
					else if (1 <= i && i <= x + d2 && j > y && j <= n && label[j][i] != 5) label[j][i] = 2;
					else if (i >= x + d1 && i <= n && 1 <= j && j < y - d1 + d2 && label[j][i] != 5) label[j][i] = 3;
					else if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n && label[j][i] != 5) label[j][i] = 4;
				}
			}
		}


				//배열에 넣고 최대차이 구하기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int index = 1; index <= 5; index++) {
					if (label[j][i] == index) {
						num[index] += people[j][i];
					}
				}
			}
		}

		sort(num, num + 6);
		answer = min(answer, num[5] - num[1]);


	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> people[j][i];


	for (int r = 1; r < n; r++)
		for (int c = 1; c < n; c++)
			for (int d1 = 1; d1 < n; d1++)
				for (int d2 = 1; d2 < n; d2++)
					solution(r, c, d1, d2);

	cout << answer;
}
