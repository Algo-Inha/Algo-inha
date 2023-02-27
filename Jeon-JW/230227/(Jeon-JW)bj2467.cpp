//https://www.acmicpc.net/problem/2467
//ฟ๋พื
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int N;
long long arr[100001];
long long a, b, ans;
long long temp;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = N - 1;

	ans = abs(arr[left] + arr[right]);
	a = arr[left];
	b = arr[right];

	while (left < right) {
		temp = arr[left] + arr[right];
		if (abs(temp) < ans) {
			ans = abs(temp);
			a = arr[left];
			b = arr[right];
		}
		if (temp < 0) {
			left++;
		}
		else {
			right--;
		}
	}

	cout << a << " " << b << endl;

	return 0;
}