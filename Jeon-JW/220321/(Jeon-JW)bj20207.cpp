//https://www.acmicpc.net/problem/20207
//달력
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cal[366];
vector<pair<int, int>> SE;
int N;
int answer;

int main() {

	cin >> N;
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		SE.push_back(make_pair(temp1, temp2));
	}

	// 오름차순 정렬
	sort(SE.begin(), SE.end());

	//for (int i = 0; i < N; i++) {
	//	cout << SE[i].first << " " << SE[i].second << endl;
	//}

	// 층계로 마킹
	for (int i = 0; i < N; i++) {
		//check
		for (int j = SE[i].first; j <= SE[i].second; j++) {
			cal[j]++;
		}
	}
	// 직사각형 계산하기
	int top = 0;
	int length = 0;
	for (int i = 1; i < 366; i++) {
		if (cal[i] > 0) {
			top = max(top, cal[i]);
			length++;
		}
		if (cal[i] == 0 || i == 365) {
			answer += top * length;
			top = 0;
			length = 0;
		}
	}

	cout << answer;

	return 0;
}