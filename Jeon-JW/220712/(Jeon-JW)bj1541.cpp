//https://www.acmicpc.net/problem/1541
//�Ҿ���� ��ȣ
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string str;
bool flag = 1; // 0:����, 1:��� // ó�� �����Ҷ� ���
long long ans;

int main() {

	cin >> str;
	int len = str.length();

	string temp = "";
	for (int i = 0; i < len; i++) {
		if (str[i] <= '9' && str[i] >= '0') {//������ ���
			temp = temp + str[i];
		}
		else { // ���� �� ���.
			//ó���� ����� �����ϴµ�, ���� ���� ����� �ҷ����� ���ؼ���
			//�ѹ� - �� ������ �� �� �ڴ� ������ ���ִ� �������� �����Ѵ�.
			if (flag) { // ����� ���
				ans += stoi(temp);
			}
			else {
				ans -= stoi(temp);
			}
			temp = "";
			if (str[i] == '-') flag = 0;
		}
	}
	if (flag) { // ����� ���
		ans += stoi(temp);
	}
	else {
		ans -= stoi(temp);
	}
	cout << ans;

	return 0;
}