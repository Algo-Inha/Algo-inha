//https://programmers.co.kr/learn/courses/30/lessons/1829
//카카오 프렌즈 컬러링북
#include <vector>
#include <stack>

using namespace std;

bool visited[101][101];
int maxm, maxn;

int dfs(int m, int n, int value, vector<vector<int>> graph) { //row, col
	if (m < 0 || n < 0 || m >= maxm || n >= maxn) return 0;

	if (visited[m][n] || m < 0 || n < 0 ||// 방문했을 경우 빠져나옴
		graph[m][n] != value || graph[m][n] == 0) { //값이 같아야하고, 0이면 안됨
		return 0;
	}
	visited[m][n] = true;

	return dfs(m + 1, n, value, graph)
		+ dfs(m, n + 1, value, graph)
		+ dfs(m - 1, n, value, graph)
		+ dfs(m, n - 1, value, graph) + 1;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int t = 0; // dfs의 값을 가져오기 위한 변수
	maxm = 0; maxn = 0;
	maxm = m; maxn = n;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			visited[i][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && picture[i][j] != 0) { // 방문하지않았거나, 색칠안해도될경우
				t = dfs(i, j, picture[i][j], picture);
				number_of_area++;
			}
			if (t > max_size_of_one_area) max_size_of_one_area = t;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}