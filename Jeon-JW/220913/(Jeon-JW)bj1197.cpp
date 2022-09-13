//https://www.acmicpc.net/problem/1197
//�ּ� ���д� Ʈ��
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int V, E;
int parent[10001];
vector<pair<int, pair<int, int>>> v;
int ans;

int findParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = findParent(parent[x]);
}


int main() {

	cin >> V >> E;
	int temp1, temp2, temp3;
	for (int i = 0; i < E; i++) {
		cin >> temp1 >> temp2 >> temp3;
		v.push_back(make_pair(temp3, make_pair(temp1, temp2)));
	}
	//���� ����ġ �������� ����
	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	bool flag1 = 0;
	for (int i = 0; i < E; i++) {
		flag1 = 0;

		//������ ������� �������
		if (findParent(v[i].second.first) != findParent(v[i].second.second)) {
			parent[findParent(v[i].second.second)] = findParent(v[i].second.first);
			ans = ans + v[i].first;
		}

	}

	cout << ans;

	return 0;
}