//베르트랑 공준
//에라토스테네스의 체

#include<iostream>
using namespace std;

int main() {
	int n;
	int num[300000];

	while (1)
	{
		int count = 0;
		cin >> n;
		for (int i = 0; i <= 2*n; i++)
		{
			num[i] = 1;
		}
		if (n == 0) break;

		for (int i = 2; i <= 2*n; i++)
		{
			if (num[i] == 0) continue;


			for (int  j = 2*i; j <= 2*n; j+=i)
			{
				if (num[j]!=0)
				{
					num[j] = 0;
				}
			}
		}
		for (int i = n+1; i <= 2*n; i++)
		{
			if (num[i]!=0)
			{
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}