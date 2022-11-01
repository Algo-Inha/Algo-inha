//���� ������������
//https://www.acmicpc.net/problem/16198
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>m;
int n,w;
int res;

void back(int cur, int size,int sum,vector<int>b) {
	if (size == 2) {
		res = max(res, sum);
		return;
	}
	if (cur >= size - 1) {
		return;
	}
	back(cur + 1, b.size(), sum, b);
	//���� ���� ���
	sum += b[cur - 1] * b[cur + 1];
	b.erase(b.begin() + cur);//���� ����
	back(1, b.size(), sum, b);//cur�� 1�� �Ѱ��ֱ�
	//������ ������ ��
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		m.push_back(w);
	}
	back(1, m.size(), 0, m);
	cout << res;
}