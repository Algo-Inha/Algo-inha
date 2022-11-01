//백준 에너지모으기
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
	//다음 구슬 고려
	sum += b[cur - 1] * b[cur + 1];
	b.erase(b.begin() + cur);//구슬 빼고
	back(1, b.size(), sum, b);//cur을 1로 넘겨주기
	//구슬을 정했을 때
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