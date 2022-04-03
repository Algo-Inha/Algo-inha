//https://www.acmicpc.net/problem/1806
//�κ���
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
//��������

int N, S;
long long sum;
int start_num, end_num;
queue<int> q;
int ans = 999999999;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	int temp = 0;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sum += temp;
		q.push(temp);
		end_num = i;
		//���� ���� S���� ũ�� start++
		while (sum >= S) {
			//cout << "�����" << start_num << " " << end_num << endl;
			ans = min(ans, end_num - start_num + 1);
			sum -= q.front();
			q.pop();
			start_num++;
		}
	}
	if (ans >= 100000) ans = 0;
	cout << ans;

	return 0;
}