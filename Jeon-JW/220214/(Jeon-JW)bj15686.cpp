//https://www.acmicpc.net/problem/15686
//치킨배달
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M; // M이 최대 치킨집
int map[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> check;
vector<pair<int, int>> chi;
bool selected[13];
int answer = 9999999;

int cal() {
	int sum = 0;
	int dist;
	int d;
	for (int i = 0; i < home.size(); i++) {
		d = 9999999;
		for (int j = 0; j < check.size(); j++) {
			dist = abs(home[i].first - check[j].first) + abs(home[i].second - check[j].second);
			d = min(d, dist);
		}
		sum += d;
	}
	return sum;
}

// n은 몇번 했는지
void comb(int idx, int n) {
	if (n >= M) {
		answer = min(answer, cal());
		return;
	}

	for (int i = idx; i < chi.size(); i++) {
		if (selected[i]) continue;
		selected[i] = 1;
		check.push_back(chi[i]);
		comb(i, n + 1);
		selected[i] = 0;
		check.pop_back();
	}
}



int main() {

	cin >> N >> M;
	int temp;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) {
				home.push_back(make_pair(i, j));
			}
			if(temp == 2) chi.push_back(make_pair(i, j));
		}
	}

	//조합?
	comb(0, 0);

	cout << answer << endl;

	return 0;
}