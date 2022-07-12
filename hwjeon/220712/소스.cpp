//가장 긴 증가하는 부분수열
// dp, max헤더
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() { 
	/*
	int length = 1, check = 0, start=0;
	int size, arr[1001];

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
		
		if (arr[i] > arr[i - 1] && start == 0 && i>0) {
			check = arr[i - 1];
			start = 1;
		}

		if (start==1 && check<arr[i])
		{
			check = arr[i];
			length++;
		}
	}

	cout << length;
	*/
	int arr[1001];
	vector<int> dp(1001, 1); 
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + 1, dp[i]); // i원소가 j원소 보다 클 때 dp값을 1 증가시킨다.
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]); //dp의 최댓값을 구한다.

	cout << ans << endl;
	return 0;

}

