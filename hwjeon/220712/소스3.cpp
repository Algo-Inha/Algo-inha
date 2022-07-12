//랜선 자르기
//이분탐색 방법
#include<iostream>
using namespace std;

int main(){
	int k, n,answer;
	int maxi = 0;
	long long mid, high, low;
	cin >> k >> n;
	int* num = new int[k];
	/*
	int sum = 0, answer, a_sum = 0;
	int max = 0;

	for (int i = 0; i < k; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	max = sum / n;

	for (int i = max; i >0; i--)
	{
		for (int j = 0; j < k; j++)
		{
			a_sum += num[j] / i;
		}
		if (a_sum>=n)
		{
			answer = i;
			break;
		}
		a_sum = 0;
	}

	cout << answer;
	*/
	for (int i = 0; i < k; i++)
	{
		cin >> num[i];
		if (maxi < num[i]) maxi = num[i];
	}
	low = 1;
	high = maxi;
	answer = 0;

	while (low <= high)
	{
		mid = (low + high) / 2; //점점 절반으로 줄여나간다
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += num[i] / mid;

		if (cnt >= n) { //갯수가 n개 이상일 때 
			low = mid + 1;  
			if (answer < mid) answer = mid; // mid>anwer이 될 때 answer이 최댓값을 가짐
		}
		else {// cnt < n 
			high = mid - 1; //low가 1이므로 low+high = mid/2가 되게 하기 위함
		}
	}
	
	cout << answer;
	delete[] num;
}