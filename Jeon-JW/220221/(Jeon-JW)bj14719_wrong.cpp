//https://www.acmicpc.net/problem/14719
//빗물
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int h, w;
int wh[500];

int cal_wh[500];
vector<int> cal; // 오른쪽이 더 낮을 수 있기 때문에


int main() {

	cin >> h >> w;
	int temp;
	for (int i = 0; i < w; i++) {
		cin >> wh[i];
	}
	
	int temp1 = wh[0];
	cal.push_back(wh[0]);
	int cnt = 0;
	cal_wh[0] = cnt;
	for (int i = 1; i < w; i++) {
		if (wh[i] >= temp1) { // 큰 기둥에서 오른쪽이 왼쪽보다 크거나 같으면
			cal[cnt] = temp1;
			temp1 = wh[i];
			cal.push_back(wh[i]);
			cnt++;
		}
		else { // 큰 기둥에서 왼쪽이 오른쪽보다 크면
			cal[cnt] = wh[i];
		}
		cal_wh[i] = cnt;

		cout << i << " : temp1 : " << temp1 << endl;
	}

	if (wh[w - 1] == 0) cal[cnt] = 0;

	
	for (int i = 0; i < cal.size(); i++) {
		cout << i << " : " << cal[i] << endl;
	}

	for (int i = 0; i < w; i++) {
		cout << cal[cal_wh[i]] << " ";
	}cout << endl;

	int answer = 0;
	int temp2;
	for (int i = 0; i < w; i++) {
		temp2 = cal[cal_wh[i]] - wh[i];
		if (temp2 <= 0) continue;
		answer += temp2;
	}

	cout << answer;

	return 0;
}

/*
100 18
28 100 43 33 37 100 87 15 52 35 54 86 60 24 99 56 4 40

100 15
28 100 43 33 37 100 87 15 52 35 54 86 60 24 99
*/