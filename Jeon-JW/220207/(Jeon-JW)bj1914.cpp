// https://www.acmicpc.net/problem/1914
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int n, k;

/*
- n개의 원반을 옮기기 위해서는 n-1개의 원반을 이웃한 기둥으로 옮겨야한다.
- 가장 큰 원반을 최종 목적 기둥으로 옮긴다.
- 이웃한 기둥에서 n-1개의 원반을 최종 목적 기둥으로 옮겨야 한다.
*/

void recur(int n, int start, int end, int temp) {
	if (n == 1) {
		cout << start << " " << end << endl;
		return;
	}
	else {
		recur(n - 1, start, temp, end); // n 말고 모두 temp
		cout << start << " " << end << endl;
		recur(n - 1, temp, end, start); // temp를 다시 end로
	}
}

int main() {

	cin >> n; // 원판의 개수
	string s = to_string(pow(2, n));
	int finddot = s.find('.');
	s = s.substr(0, finddot);
	s[s.length() - 1] -= 1;
	cout << s << endl;
	if (n <= 20) {
		recur(n, 1, 3, 2);
	}


	return 0;
}