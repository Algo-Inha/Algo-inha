//비
// https://www.acmicpc.net/problem/14719

#include <iostream>

using namespace std;
//첫 번째 줄에는 2차원 세계의 세로 길이 H과 2차원 세계의 가로 길이 W가 주어진다. (1 ≤ H, W ≤ 500)
//
//두 번째 줄에는 블록이 쌓인 높이를 의미하는 0이상 H이하의 정수가 2차원 세계의 맨 왼쪽 위치부터 차례대로 W개 주어진다.
//
//따라서 블록 내부의 빈 공간이 생길 수 없다.또 2차원 세계의 바닥은 항상 막혀있다고 가정하여도 좋다.
int main()
{
	int height; // 2차원의 높이
	int width; // 2차원의 너비
	cin >> height >> width;
	int arr[501]; // 각 2차원새계의 블록의 높이
	bool left_check;
	bool right_check;
	int ans = 0;
	for (int i = 0; i < width; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i < width-1; i++) // 너비에서 i 로 하나씩 이동중
	{
	
		for (int h = height - arr[i]; h > 0; h--) // i 위치에서 h를 하나씩 줄여보면서 양쪽에 블럭이 있는지 확인
		{
			left_check = false;
			right_check = false;
			for (int left = 0; left < i; left++)
			{
				if (arr[left] >= h + arr[i])
				{
					left_check = true;
					break;
				}
			}
			for (int right = width-1; right > i; right--)
			{
				if (arr[right] >= h + arr[i])
				{
					right_check = true;
					break;
				}
			}
			if ((right_check) && (left_check))
			{
				ans += h;
				break;
			}

		}
	}
	cout << ans << endl;
	
	

}