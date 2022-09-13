#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int arr[10001] = {0};
	for (int i = 2; i < 10001; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i < 10001; i++)
	{
		if (arr[i] == 0)continue;
		for (int j = 2*i; j < 10001; j+=i)
		{
			arr[j] = 0;
		}
		
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num1, num2;
			num1 = n / 2 - j;
			num2 = n - num1;
			if (arr[num1]!=0 && arr[num2]!=0)
			{
				cout << num1 << " " << num2 << endl;
				break;
			}
		}
	}
}