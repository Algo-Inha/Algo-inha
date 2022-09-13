//https://www.acmicpc.net/problem/1197
//최소 스패닝 트리
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
	//간선 가중치 오름차순 정렬
	sort(v.begin(), v.end());

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	bool flag1 = 0;
	for (int i = 0; i < E; i++) {
		flag1 = 0;

		//간선이 연결되지 않은경우
		if (findParent(v[i].second.first) != findParent(v[i].second.second)) {
			parent[findParent(v[i].second.second)] = findParent(v[i].second.first);
			ans = ans + v[i].first;
		}

	}

	cout << ans;

	return 0;
}