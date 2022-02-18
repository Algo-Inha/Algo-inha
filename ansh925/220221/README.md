
## BJ 2606
### 바이러스_1
- `DFS`
```c++
void DFS(int x)
{
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (check[y] != true)
		{
			DFS(y);
			cnt++;
		}
	}
}
```
> - 벡터를 이용해서 DFS 구현
> - 처음에 벡터 이용해서 풀어보려다가 결국에 안되서 바이러스_2에서 배열로 해결했다.   
> 이 코드는 풀이를 참고한건데, int y=v[x][i]; 부분에서 왜 갑자기 벡터 2차원배열을 사용한건지 잘 모르겠다.
   
   
### 바이러스_2
- `DFS`
```c++
void DFS(int x)
{	
	cnt++;
	check[x] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (map[x][i] && !check[i])
			DFS(i);
	}
}
```
> - 벡터 사용하지 않고 2차원배열을 이용해서 DFS 구현
> - 벡터 사용하는것보다 코드 자체는 더 간단한걸로 보인다.
>  - 2차원 배열을 돌며 check이 0인 경우와 map이 1인 경우에서 DFS 재귀 호출
   
## BJ 21318
### 피아노체조_1
- `배열 사용`
```c++
for (int i = 1; i <= N; i++)
	{
		if (difficulty[i] > difficulty[i + 1])
			cnt++;
		miss[i + 1] = cnt;
	}

for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		cout << miss[y] - miss[x] << '\n';
	}	
```
> - 벡터 사용하지 않고 배열에 난이도와 실수할 횟수를 저장
> - 현재 악보의 난이도가 다음 악보의 난이도보다 높을 경우 cnt++   
> for문을 돌며 매번 miss[]에 cnt값 저장. cnt++되는 경우에만 miss[] 값 증가   
> 입력한 악보의 위치 x,y에 대해서 그 사이에 cnt값 차이가 실수한 횟수가 되므로 miss[y]-miss[x]를 출력
> - 의문점: ``` ios_base::sync_with_stdio(0);	cin.tie(0); 	cout.tie(0); ```
> 이걸 쓰지 않으면 시간초과가 남
   
### 피아노체조_2
- `벡터 사용`
```c++
for (int i = 0; i < N; i++)
	{
		cin >> n;
		v.push_back(n);

		if (i == 0)
			continue;
		if (v[i - 1] > n)
			cnt[i] = cnt[i - 1] + 1;
		else
			cnt[i] = cnt[i - 1];
	}
while (Q--)
	{
		int x, y, ans = 0;
		cin >> x >> y;
		ans = cnt[y - 1] - cnt[x - 1];
		cout << ans << '\n';
	}
```
> - 벡터를 사용해서 악보 난이도 저장
> - for문을 돌며 이전 벡터(i-1)에 저장된 악보의 난이도가 현재 난이도(입력n)보다 높은 경우 cnt[]에 +1   
> 피아노체조_1에서의 cnt++한 후, miss[]에 저장해주는 방법과 유사   
> 마찬가지로 입력한 악보의 위치 x,y에 대해서 cnt[] 사이의 차이 cnt[y-1]-cnt[x-1] 출력
> - 의문점 동일

## BJ 14719
### 빗물
```c++
for (int i = 1; i < w - 1; i++)
	{
		int left = 0, right = 0;
		for (int j = 0; j < i; j++)
			left = max(left, v[j]);
		for (int j = w - 1; j > i; j--)
			right = max(right, v[j]);
		ans += max(0, min(left, right) - v[i]);
	}
```
> - 벡터 이용 세로 블록값 저장
> - 왼쪽 블록부터 시작해서 for문으로 현재 위치를 한 칸씩 증가시키며 현재 위치 기준 왼쪽의 max값과 오른쪽 max값을 구한 뒤,
> 둘 중 더 작은값에서 현재 위치의 벡터값, 즉 현재 위치의 블록값을 뺀 값이 그 세로줄에서 빗물이 차는 양이다.   
> 그 양이 0보다 작을수는 없으므로 ```max(0, min(left, right) - v[i]);``` 를 ans에 더해준다.   
> for문을 돌며 모든 세로줄에 대해서 같은 방법으로 진행하면 ans에 빗물이 차는 총 양 저장, ans 출력
   

## PG 72410
### 신규 아이디 추천
```c++
string solution(string new_id)
{
	// step1
	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = tolower(new_id[i]);
	}

	// step2
	for (int i = 0; i < new_id.length();)
	{
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') ||
			new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			i++;
			continue;
		}
		new_id.erase(new_id.begin() + i);
	}

	// step3
	for (int i = 1; i < new_id.length();)
	{
		if (new_id[i] == '.' && new_id[i - 1] == '.')
		{
			new_id.erase(new_id.begin() + i);
			continue;
		}
		else
			i++;
	}

	// step4
	if (new_id.front() == '.')
		new_id.erase(new_id.begin());
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);

	// step5
	if (new_id.length() == 0)
		new_id = "a";

	// step6
	if (new_id.length() >= 16)
	{
		while (new_id.length() != 15)
			new_id.erase(new_id.begin() + 15);
	}
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);

	// step7
	if (new_id.length() <= 2)
	{
		while (new_id.length() != 3)
			new_id += new_id.back();
	}

	return new_id;
}
```
> - 주어진 7단계에 대해서 차례대로 진행하면 비교적 수월하게 해결 가능하다.
> - 2,3단계에서 문자열의 중간을 제거하는 부분에서 막혀서 풀이를 참고하였는데,
>  for문의 중괄호 안에 i++를 해주는 것을 통해 해결 가능한 방법을 새로 알게되었다.   
>  조건부 문제열 제거시 erase 함수를 사용했다. 2,3단계를 제외하고 나머지 단계는 생각보다 간단했다.
>  - 제출 후 다른 사람의 풀이를 보던 중, strchr 함수를 사용하여 문자열 검색을 쉽게하는 방법을 알게되었다.   
>  ```strchr``` : 문자열(char형) 내에 일치하는 문자가 있는지 검사하는 함수   
>  ex) ```strchr("-_.",char);```  : char형 문자열 char1 문자열에서 -, _, . 3개의 특수문자가 있는지 검사하는 함수

## BJ 5884
### 감시카메라
```c++
void DFS(int cnt, vector<pair<int, int>> v)
{
	if (ans)
		return;
	if (v.size() > 3)
		return;
	if (cnt == N)
	{
		ans = true;
		return;
	}

	if (cnt == 0)
	{
		v.push_back({ arr_x[0],-1 });
		DFS(cnt + 1, v);
		v.pop_back();

		v.push_back({ -1,arr_y[0] });
		DFS(cnt + 1, v);
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first == arr_x[cnt])
			{
				flag = true;
				DFS(cnt + 1, v);
				break;
			}
			if (v[i].second == arr_y[cnt])
			{
				flag = true;
				DFS(cnt + 1, v);
				break;
			}
		}

		if (!flag)
		{
			v.push_back({ arr_x[cnt],-1 });
			DFS(cnt + 1, v);
			v.pop_back();

			v.push_back({ -1,arr_y[cnt] });
			DFS(cnt + 1, v);
		}
	}
}
```
> - 혼자 힘으로는 해결하지 못하겠어서 인터넷의 풀이를 참고했다.   
> 코드를 보고 한줄씩 디버깅도 해봤는데, 코드의 어느부분에서 cnt값이 -가되는지(작아지는지) 모르겠다.   
> 풀이를 봤는데도 전체적으로 코드 이해가 잘 안된다.

