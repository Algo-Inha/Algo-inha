// https://www.acmicpc.net/problem/1914
// 하노이 탑
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int n, k;

/*
- n개의 원반을 옮기기 위해서는 n-1개의 원반을 이웃한 기둥으로 옮겨야한다.
- 가장 큰 원반을 최종 목적 기둥으로 옮긴다.
- 이웃한 기둥에서 n-1개의 원반을 최종 목적 기둥으로 옮겨야 한다.
*/

// '\n'때문에 시간초과 ㅋㅋ
void recur(int n, int start, int end, int temp) {
	if (n == 1) {
		cout << start << " " << end << '\n';
		return;
	}
	else {
		recur(n - 1, start, temp, end); // n 말고 모두 temp
		cout << start << " " << end << '\n';
		recur(n - 1, temp, end, start); // temp를 다시 end로
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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