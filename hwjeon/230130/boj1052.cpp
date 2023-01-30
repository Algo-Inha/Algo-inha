#include <iostream>
using namespace std;

int main(void)
{
	int N, K;
	cin >> N >> K;

	if (N <= K)
	{
		cout << 0 << "\n";
		return 0;
	}

	int result;

	for (result = 0; ; result++)
	{
		int cnt = 0;
		int tempN = N;
		while (tempN)
		{
			if (tempN % 2)
			{
				cnt++;
			}
			tempN /= 2;
		}
		if (cnt <= K)
		{
			break;
		}
		N++;
	}
	cout << result << "\n";
	return 0;
}