// z
// ㄹㅇ 쉽지 않았음... 
// 마찬가지로 글을 좀 찾아보며 (r,c)를 찾으려고 노력했다.
// 찾은 후에는 r,c를 도달해서 그 값까지의 거리를 구하려고 하였다.
// 제일 어려운 부분이 다른 영역으로 넘어갔을때 그 영역에 값을 제시 하는 부분이었다.

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int  N, r, c;
int count;
// int map[10000][10000] // 보드를 만들고 하려 했으나 지옥이 시작됨
void divv(int x, int y, int len)
{
	if (y == r && x == c)
	{
		cout << count << endl;
		return; // 전역변수를 의미
	}

	if (len == 1)
	{
		count++;
		return; // 종료를 시켜주는것이 가장 어려웠다...  영역을 줄여나가다가 마지막 분기를 확인하는 것이 어려웠다.
	}
	if (!(y<= r && r < y + len && x <= c && c < x + len)) // 정해진 범위의 밖에 나간 경우 해당 len의 크기만큼 더하고 이동
	{
		count += len*len;
		return;
	}
	divv(x			, y			 , len / 2); //1사분면
	divv(x + len / 2, y			 , len / 2); // 2사분면
	divv(x			, y + len /2 , len / 2); // 3사분면
	divv(x + len / 2, y + len / 2, len / 2); // 4분면
    // 이 재귀함수 순서가 아주아주아주 중요하다. 



}

int main()
{
	cin >> N>> r>> c;
	divv(0, 0, pow(2,N)); // 재귀함수를 돌며 정해진 위치를 찾아가는 것이 중요하다.

}