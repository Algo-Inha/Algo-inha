//https://www.acmicpc.net/problem/11000
// 강의실 배정
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int s, t;
int N;
vector<pair<int, int>> classes;


// 빨리 끝날수록 우선순위가 높게 저장.
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		classes.push_back(make_pair(s, t));
	}
	//첫번째 원소를 기준으로 오름차순 정렬
	sort(classes.begin(), classes.end());
	pq.push(classes[0].second);
	for (int i = 1; i < N; i++) {
		//가장 빨리 끝나는 강의 시간 <= 현재 넣으려는 강의 시작 시간
		// -> 같은 강의실에서 수업할 수 있기 때문에 pop진행
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