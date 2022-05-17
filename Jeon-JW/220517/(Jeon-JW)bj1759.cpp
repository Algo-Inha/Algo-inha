//https://www.acmicpc.net/problem/1759
//��ȣ �����
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> v;
bool visit[15];

int L, C; // ��ȣ����, ���ɼ��ִ� ���ĺ� ����
//�ּ� �Ѱ��� ����, �ΰ��� ���� ���ĺ��� �����ϴ� ������ �迭

void recur(int cnt, int a_cnt, int b_cnt, int start) {
	if (cnt == L) {
		if (a_cnt >= 1 && b_cnt >= 2) {
			for (int i = 0; i < C; i++)
				if (visit[i]) cout << v[i];
			cout << "\n";
		}
		else return;
	}


	for (int i = start; i < C; i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			visit[i] = 1;
			recur(cnt + 1, a_cnt + 1, b_cnt, i + 1);
			visit[i] = 0;
		}
		else {
			visit[i] = 1;
			recur(cnt + 1, a_cnt, b_cnt + 1, i + 1);
			visit[i] = 0;
		}
	}

}



int main() {

	cin >> L >> C;
	char c;
	for (int i = 0; i < C; i++) {
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());

	recur(0, 0, 0, 0);


	return 0;
}