//https://www.acmicpc.net/problem/18870
//��ǥ����
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int main() {

	cin >> N;
	long temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		v1.push_back(make_pair(temp, i));
	}
	//ù��° ���ұ������� sort
	sort(v1.begin(), v1.end());
	//v2���� ���� ������ sort�ϱ� ���ؼ� ������ ���ܿ���.
	v2.push_back(make_pair(v1[0].second, 0));
	int pivot = 0;
	for (int i = 1; i < N; i++) {
		if (v1[i - 1].first == v1[i].first) { // ���� ���� ���.
			v2.push_back(make_pair(v1[i].second, pivot));
		}
		else { // �ٸ� ���� ���.
			pivot++;
			v2.push_back(make_pair(v1[i].second, pivot));
		}
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i < N; i++) {
		cout << v2[i].second << " ";
	}
	

	return 0;
}