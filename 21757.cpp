// https://www.acmicpc.net/problem/21757
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int main() {
	long long ans = 0;
	//vector<long long> v;
	vector<long long> an_v;

	int n;
	cin >> n;
	long long temp;
	cin >> temp;
	an_v.push_back(temp);
	for (int i = 1; i < n; i++) {
		cin >> temp;
		an_v.push_back(temp + an_v[i - 1]);
	}
	/*long long temp1;
	an_v.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		temp1 = an_v[i - 1] + v[i];
		an_v.push_back(temp1);
	}*/

	long long cnt[4] = { 1,0,0,0 };
	if (an_v[n - 1] % 4 != 0) {
		cout << 0 << endl;
	}
	else
	{
		long long f1 = an_v[n - 1] / 4;
		long long f2 = f1 * 2;
		long long f3 = f1 * 3;
		long long f4 = f1 * 4;

		for (int i = 0; i < n; i++) {
			/*if (an_v[i] == f1) {
				for (int j = i + 1; j < n; j++) {
					if (an_v[j] == f2) {
						for (int k = j + 1; k < n; k++) {
							if (an_v[k] == f3) {
								for (int m = k + 1; m < n; m++) {
									if (an_v[m] == f4) ans++;
								}
							}
						}
					}
				}
			}*/
			if (an_v[i] == f3) {
				cnt[3] += cnt[2];
			}
			if (an_v[i] == f2) {
				cnt[2] += cnt[1];
			}
			if (an_v[i] == f1) {
				cnt[1] += cnt[0];
			}
		}
		cout << cnt[3];
	}
	//cout << ans << endl;


	return 0;
}