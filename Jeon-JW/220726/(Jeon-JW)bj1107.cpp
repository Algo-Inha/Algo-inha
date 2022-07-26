//https://www.acmicpc.net/problem/1107
//������
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


int N, M;
bool button[10];
int temp;

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		button[temp] = 1;
	}

	string str = to_string(N);

	int answer = abs(N - 100); // ���Ʒ��� ������ ��

	bool flag;
	string str_temp;
	// ��ȣ�� ���Ѵ�� ������ ������ �� ����.
	for (int i = 0; i < 1000001; i++) {
		flag = 0;
		string str_temp = to_string(i);
		for (int j = 0; j < str_temp.length(); j++) {
			if (button[str_temp[j] - 48]) {
				flag = 1;
				break;
			}
		}
		// ��ȣ�� ǥ�� ������ ���
		if (!flag) {
			temp = abs(N - i) + str_temp.length();
			answer = min(answer, temp);
			//cout << i << endl;
		}
	}

	cout << answer;

	return 0;
}