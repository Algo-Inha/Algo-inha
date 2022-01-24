#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set[101]; // node의 parent를 저장하는 배열

int getParent(int node) {
	if (set[node] == node) return node;
	return set[node] = getParent(set[node]);
}

bool cmp(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	sort(costs.begin(), costs.end(), cmp); // 오름차순

	for (int i = 0; i < costs.size(); i++) {
		int start = getParent(costs[i][0]);
		int end = getParent(costs[i][1]);
		int cost = costs[i][2];

		if (start != end) { // 사이클이 만들어지지 않을 경우 다리를 추가
			answer += cost;
			set[end] = start;
		}
	}

	return answer;
}