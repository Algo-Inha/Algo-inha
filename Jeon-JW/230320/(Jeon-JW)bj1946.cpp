//https://www.acmicpc.net/problem/1946
//신입 사원
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다는 원칙을 세웠다. 
//즉, 어떤 지원자 A의 성적이 다른 어떤 지원자 B의 성적에 비해 서류 심사 결과와 면접 성적이 모두 떨어진다면 A는 결코 선발되지 않는다. -- 이 줄이 핵심
int T, N;

int temp1, temp2;
//100,000

int main() {

	vector<pair<int, int>> v;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		int cnt = 1; // 맨 앞의 첫번째 거 1등은 먹어줌.
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}
		sort(v.begin(), v.end()); // 오름차순

		int pivot = 0;
		for (int i = 1; i < N; i++) {
			if (v[pivot].second > v[i].second) {
				pivot = i;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}


	return 0;
}


//1 4
//2 5
//3 6
//4 2
//5 7
//6 1
//7 3
//
//
//3 6 -> 1 4가 둘다 순위가 높아 탈락
//
//7 3 -> 1 4가 둘다 순위가 높아 탈락
//
//4 2 -> 모든 지원자보다 최소 한가지는 등수가 높으니까 가능
//
//1 4-> 모든 지원자보다 최소 한가지는 등수가 높으니까 가능 
//
//5 7 -> 1 4가 둘다 순위가 높아 탈락
//
//2 5 -> 1 4가 둘다 순위가 높아 탈락
//
//6 1-> 모든 지원자보다 최소 한가지는 등수가 높으니까 가능 