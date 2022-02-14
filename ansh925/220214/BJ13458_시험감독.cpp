//https://www.acmicpc.net/problem/13458
#include <iostream>

using namespace std;

int n, b, c;
long long sum = 0;
int arr[1000001] = { 0, };

int main()
{	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> b >> c;
		
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= b)
			sum++;
		else
		{
			arr[i] = arr[i] - b;
			sum++;

			if (arr[i] % c == 0)
				sum += arr[i] / c;
			else
				sum += (arr[i] / c) + 1;
		}
	}	

	cout << sum << endl;

	return 0;
}