#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdlib>
#include<queue>
#include<string.h>

using namespace std;
#define _max 1001

int time[_max];
int degree[_max];
int tot[_max];
int n, k;
int last;
vector<int>v[_max];


void res() {
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (!degree[i]) {
			q.push(i);
			tot[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			degree[next] -= 1;
			tot[next] = max(tot[next], tot[cur] + time[next]);
			if (!degree[next]) {
				q.push(next);
			}
		}

	}
}

void ini() {
	memset(time, NULL, sizeof(time));
	memset(degree, NULL, sizeof(degree));
	memset(tot, NULL, sizeof(tot));
	for (int i = 1; i <= n; i++)
	{
		v[i].clear();
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> time[i];
		}
		for (int i = 0; i < k; i++)
		{
			int num1, num2;
			cin >> num1 >> num2;
			v[num1].push_back(num2);
			degree[num2]++;
		}
		cin >> last;
		res();
		cout << tot[last] << "\n";
		ini();
	}
}
