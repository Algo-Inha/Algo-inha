
# 하노이탑
## BJ 1914

+ `재귀함수`

```c++
void Hanoi(int n, int start, int by, int end)
{
	if (n == 1)
		//cout << start << " " << end << endl;
		printf("%d %d\n", start, end);
	else
	{
		Hanoi(n - 1, start, end, by);
		//cout << start << " " << end << endl;
		printf("%d %d\n", start, end);
		Hanoi(n - 1, by, start, end);
	}
}
```
> - 전에 하노이탑 문제가 대표적인 재귀함수를 사용하는 문제라는 걸 들은 기억이 있어서 재귀함수 사용했다.
> - 처음에 계속 시간초과가 났는데, endl 때문인줄 모르고 한참 해메다가 나중에서야 printf로 수정했더니 통과되었다.

```c++
path = to_string(pow(2, num));

int x = path.find('.');
path = path.substr(0, x);
path[path.length() - 1] -= 1;
```
> - main함수의 총 이동 횟수를 계산하는 과정에서 2^n-1 이라는 식은 알고있지만 표현하는 문법이 헷갈려 인터넷에 올라와있는 풀이를 참고하여 to_string 함수를 사용했다.
> - 이후에 20이하인 경우에 대해서 재귀함수를 실행했다.


# 스타트와 링크
## BJ 14889
