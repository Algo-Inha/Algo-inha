#include <iostream>
using namespace std;

int main() {
	int n, arr[101], std, g, y, i, k;

	cin >> n;  

	for (i = 1; i <= n; i++)
	{
		cin >> arr[i];  
	}

	cin >> std;   
	for (k = 0; k < std; k++)
	{
		cin >> g >> y;  

		if (g == 1)  
		{
			for (i = 1; i <= n; i++)
			{
				if (i%y == 0)  
					arr[i] = !arr[i];  
			}
		}

		else  
		{
			arr[y] = !arr[y];  
			for (i = 1; arr[y + i] == arr[y - i]; i++)   
			{
				if (y + i > n || y - i < 1)  
					break;
				arr[y + i] = !arr[y + i];   
				arr[y - i] = !arr[y - i];   
			}
		}
	}

	for (i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
		if (i % 20 == 0)  //20개의 숫자를 출력했다면 줄바꾸기
			cout << "\n";
	}

}