//정사각형
//https://www.acmicpc.net/problem/1485
#include<iostream>
#include<algorithm>

using namespace std;

pair <int, int> c[4];
long long dis[6];

long long caldis(long long x1, long long y1,long long x2, long long y2) {

	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			cin >> c[i].first;
			cin >> c[i].second;
		}
		int cnt=0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++) {
				dis[cnt] = caldis(c[i].first, c[i].second, c[j].first, c[j].second);
				cnt++;
			}
		}

		sort(dis, dis + 6);

		if (dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3] && dis[4] == dis[5])check = true;
		cout << check << endl;
	}
}