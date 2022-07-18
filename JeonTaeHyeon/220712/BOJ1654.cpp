#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int k, n;
int cable[10001];
long long min_, max_, mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k >> n;
	min_ = 1;
	for (int i = 0; i < k; i++)
	{
		cin >> cable[i];
		//max_ = max(cable[i], max_);
		if (cable[i] > max_)max_ = cable[i];
	}
	int res = 0;
	while (min_ <= max_) {
		mid = (min_ + max_) / 2;
		int number = 0;
		for (int i = 0; i < k; i++)
		{
			number += cable[i] / mid;
		}
		if (number < n) {
			max_ = mid - 1;
		}
		if (number >= n) {
			min_ = mid + 1;
			if (res < mid)res = mid;
		}
	}
	cout << res;
}