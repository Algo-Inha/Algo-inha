#include<iostream>
#include<algorithm>
using namespace std;
int arr[4][4];
 
int main() {
	int N, M; // 세로, 가로
	cin >> N >> M;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
		}
	}
 
	int ans = -1; 
 
	for (int s = 0; s < N * M; s++) 
	{
		int sum = 0;
		for (int i = 0; i < N; i++) //  세로
		{
			int point = 0; 
 
			
		}
 
		/* 세로 연결 부분의 경우 */
		for (int j = 0; j < M; j++) //  가로
		{
			int point = 0;
 
			for (int i = 0; i < N; i++) // 세로
			{

			}
			sum += point;
		}
 

	}
 
	cout << ans << '\n';
 
	return 0;
}