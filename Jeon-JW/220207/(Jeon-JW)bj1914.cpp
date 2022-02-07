// https://www.acmicpc.net/problem/1914
// �ϳ��� ž
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int n, k;

/*
- n���� ������ �ű�� ���ؼ��� n-1���� ������ �̿��� ������� �Űܾ��Ѵ�.
- ���� ū ������ ���� ���� ������� �ű��.
- �̿��� ��տ��� n-1���� ������ ���� ���� ������� �Űܾ� �Ѵ�.
*/

// '\n'������ �ð��ʰ� ����
void recur(int n, int start, int end, int temp) {
	if (n == 1) {
		cout << start << " " << end << '\n';
		return;
	}
	else {
		recur(n - 1, start, temp, end); // n ���� ��� temp
		cout << start << " " << end << '\n';
		recur(n - 1, temp, end, start); // temp�� �ٽ� end��
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

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