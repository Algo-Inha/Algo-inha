// https://www.acmicpc.net/problem/1914
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int n, k;

/*
- n���� ������ �ű�� ���ؼ��� n-1���� ������ �̿��� ������� �Űܾ��Ѵ�.
- ���� ū ������ ���� ���� ������� �ű��.
- �̿��� ��տ��� n-1���� ������ ���� ���� ������� �Űܾ� �Ѵ�.
*/

void recur(int n, int start, int end, int temp) {
	if (n == 1) {
		cout << start << " " << end << endl;
		return;
	}
	else {
		recur(n - 1, start, temp, end); // n ���� ��� temp
		cout << start << " " << end << endl;
		recur(n - 1, temp, end, start); // temp�� �ٽ� end��
	}
}

int main() {

	cin >> n; // ������ ����
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