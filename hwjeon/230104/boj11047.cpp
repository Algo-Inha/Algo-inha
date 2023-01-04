#include<iostream>
using namespace std;

int main() {
	int arr[11];
	int n, k;
	int sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		sum += k / arr[i];
		k = k % arr[i];
	}

	cout << sum << "\n";
}