#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;

int n, h;
int top[250001];
int bottom[250001];
int save[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> h;
	int length;

	for (int i = 1; i <= n / 2; i++)
	{
		cin >> length;
		bottom[i] = length;
		cin >> length;
		top[i] = length;
	}

	sort(bottom + 1, bottom + n / 2 + 1, greater<int>());
	sort(top + 1, top + n / 2 + 1, greater<int>());

	int cnt = 1;
	while (true) {
		if (bottom[cnt] == bottom[cnt + 1])++cnt;
		else {
			int k = bottom[cnt] - bottom[cnt + 1];
			while (k) {
				save[bottom[cnt] - k + 1] += cnt;
				k--;
			}
			//	cout << cnt << endl;
			++cnt;
		}
		if (bottom[cnt] == 0)break;
	}
	cnt = 1;
	while (true) {
		if (top[cnt] == top[cnt + 1])++cnt;
		else {
			int k = top[cnt] - top[cnt + 1];
			while (k) {
				save[h - top[cnt] + k] += cnt;
				k--;
			}
			++cnt;
		}
		if (top[cnt] == 0)break;
	}

	sort(save + 1, save + h + 1);



	cnt = 1;
	while (true) {
		if (save[cnt] == save[cnt + 1])cnt++;
		else break;
	}
	cout << save[1] << " " << cnt;
}