#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	string numb;
	int number = 1003001;
	int num[1003002];
	cin >> n;
	if (n == 1) cout << 2;
	else {
		for (int i = 0; i < number; i++)
		{
			num[i] = i;
			numb = to_string(i);
			string buf = numb;
			reverse(numb.begin(), numb.end());
			if (numb != buf) {
				num[i] = 0;
			}
		}


		for (int i = 2; i <= number; i++)
		{
			if (num[i] == 0) continue;
			for (int j = i + i; j <= number; j += i)
			{
				num[j] = 0;
			}

		}
		for (int i = n; i < number; i++)
		{
			if (num[i] != 0)
			{
				cout << i << endl;
				break;

			}
		}
	}
	
}