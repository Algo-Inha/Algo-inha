안녕하십니까 스터디에 합류하게된 안승현입니다~!   
스터디 자체가 처음이고 git도 많이 안써봤으며 코딩 실력은 많이 미흡하지만 최선을 다해서 해보겠습니다.   
라고 하기엔 설연휴를 끼면서 시간을 많이 할애하지 못했는데, 앞으로는 성실하게 다 풀어오겠습니다..ㅎ   


# 하노이탑
## BJ 1914

- `재귀함수`

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

- `DFS`

```c++
void DFS(int x, int y)
{
	if (x == N / 2)
	{
		int start=0, link=0;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true)
					start += arr[i][j];
				if (check[i] == false && check[j] == false)
					link += arr[i][j];
			}
		}
		int temp = abs(start - link);
		if (ans > temp)
			ans = temp;

		return;
	}

	for (int i = y; i < N; i++)
	{
		check[i] = true;
		DFS(x + 1, i + 1);
		check[i] = false;
	}
}
```

> - 탐색 문제인것까지는 파악을 했는데, 작년에 알설 수업에서 배운게 하나도 기억이 나지 않아서 난감했다.
> 최대한 풀이를 안보고 작성해보려고 강의노트를 다시 보면서 기억을 조금씩 되살리려고 노력해봤다.
> - 정작 DFS 함수보다는 for문에서 계속 실수가 있었긴 했지만 그래도 나름 풀이는 안보고 해결할 수 있었다.
   
# 촌수계산
## BJ 2644

- `BFS`

```c++
void BFS(int x)
{
	q.push(x);
	visited[x] = true;

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for(int i = 1; i <= n; i++)
		{
			if (arr[x][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = true;
				depth[i] = depth[x] + 1;
			}
		}
	}
}
```

> - 앞선 스타트와 링크 문제를 풀면서 탐색을 다시 복습하는 시간을 가졌어서 이 문제도 탐색을 이용해야된다고 생각했다.
> - 최원익 교수님의 제자답게 패드에 직접 손코딩을 하고 하나씩 손디버깅을 해보면서 BFS 함수를 작성했다.
> - 시간은 많이 걸리지만 코딩 초보에게는 직접 손으로 queue를 그려가면서 디버깅해보는게 코드 자체를 이해하는데는 최고인것 같다. 그래도 나름 선방했던 문제였다.

   
# 
