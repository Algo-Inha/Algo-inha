//https://www.acmicpc.net/problem/11000
// ���ǽ� ����
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int s, t;
int N;
vector<pair<int, int>> classes;


// ���� �������� �켱������ ���� ����.
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		classes.push_back(make_pair(s, t));
	}
	//ù��° ���Ҹ� �������� �������� ����
	sort(classes.begin(), classes.end());
	pq.push(classes[0].second);
	for (int i = 1; i < N; i++) {
		//���� ���� ������ ���� �ð� <= ���� �������� ���� ���� �ð�
		// -> ���� ���ǽǿ��� ������ �� �ֱ� ������ pop����
		if (pq.top() <= classes[i].first) {
			pq.pop();
			pq.push(classes[i].second);
		}
		else {
			pq.push(classes[i].second);
		}
	}
	cout << pq.size();

	return 0;
}