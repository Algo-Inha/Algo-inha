#include<iostream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<map>
#include<limits.h>

using namespace std;

int n, r;
int recommend[101], when[101], cur;

int main() {

	cin >> n >> r;
	for (int i = 1; i <= r; ++i) {
		int vote;
		cin >> vote;
		if (recommend[vote] > 0) recommend[vote]++;
		else {
			if (cur < n) {
				recommend[vote]++;
				when[vote] = i;
				cur++;
			}
			else {
				int drop;
				int reco = INT_MAX;
				for (int i = 1; i <= 100; ++i) {
					if (!recommend[i]) continue;
					if (reco > recommend[i]) {
						drop = i;
						reco = recommend[i];
					}
					else if (reco == recommend[i]) {
						if (when[i] < when[drop]) drop = i;
					}
				}
				recommend[vote]++;
				when[vote] = i;
				recommend[drop] = 0;
				when[drop] = 0;
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
		if (when[i]) cout << i << ' ';

	return 0;
}