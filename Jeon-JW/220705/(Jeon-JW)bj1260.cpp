//https://www.acmicpc.net/problem/1260
//DFS와 BFS
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

bool visitedbfs[1001];
bool visiteddfs[1001];

int mat[1001][1001];

void bfs(int s, int n) { // s는 시작정점 n은 개수
	queue<int> que; // 큐 생성

	int j;
	visitedbfs[s] = true;
	que.push(s);
	cout << s;
	while (!que.empty()) {
		for (int i = 1; i <= n; i++) {
			if (mat[s][i] == 1 && visitedbfs[i] == 0 || mat[i][s] == 1 && visitedbfs[i] == 0) {
				que.push(i);
			}
		}
		int v = que.front();
		if (visitedbfs[v] == 0) {
			cout << " " << v;
			visitedbfs[v] = 1;
			s = v;
		}
		que.pop();
	}
}

void dfs(int s, int n) {
	stack<int> stack1; // stack 생성

	stack1.push(s);
	visiteddfs[s] = 1;
	cout << s;
	while (int(stack1.empty()) == false) {
		for (int i = n; i > 0; i--) {
			if (mat[s][i] == 1 && visiteddfs[i] == 0 || mat[i][s] == 1 && visiteddfs[i] == 0) {
				stack1.push(i);
			}
		}
		int v = stack1.top();
		if (visiteddfs[v] == 0) {
			cout << " " << v;
			visiteddfs[v] = 1;
			s = v;
		}
		stack1.pop();
	}
}


int v, e, start;
int row, col;
int main() {
	cin >> v >> e >> start;
	//정점의 개수, 간선의 개수, 탐색시작시점
	for (int i = 0; i < e; i++) {
		cin >> row >> col;
		mat[row][col] = 1;
	}
	dfs(start, v);
	cout << endl;
	bfs(start, v);




	return 0;
}