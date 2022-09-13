
> 220906
> 스킬트리
```c++
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int cur, next;
	bool flag;

	for (int i = 0; i < skill_trees.size(); i++) {
		flag = true;
		next = 0;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			cur = skill.find(skill_trees[i][j]);
			if (cur == -1) {
				continue;
			}
			else {
				if (next++ != cur) {
					flag = false;
					break;
				}
			}
		}
		if (flag == true)
			answer++;
	}
	return answer;
}
```
>- for문을 통해 하려고 했으나 풀지못하였습니다.
>- 구글링을 하다가 find 함수를 사용법을 터득하였습니다.

># 골드바흐의 추측
```c++
#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	int arr[10001] = {0};
	for (int i = 2; i < 10001; i++)
	{
		arr[i] = i;
	}
	for (int i = 2; i < 10001; i++)
	{
		if (arr[i] == 0)continue;
		for (int j = 2*i; j < 10001; j+=i)
		{
			arr[j] = 0;
		}
		
	}
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num1, num2;
			num1 = n / 2 - j;
			num2 = n - num1;
			if (arr[num1]!=0 && arr[num2]!=0)
			{
				cout << num1 << " " << num2 << endl;
				break;
			}
		}
	}
}
```
>-  에라토스테네스의 체를 코드를 작성하는데에 있어서 점점 숙달되어가는 것 같습니다.
>- 개행문자를 사용하지 않아서 틀렸다고 떠서 방황을 좀 하였습니다.


>최소직사각형
```c++ 
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int answer = 0;
	int max = 0, min[4] = { 0 }, minmax = 0;
	for (int i = 0; i < sizes.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (sizes[i][j] > max) {
				max = sizes[i][j];
			}
		}

		if (sizes[i][0]>sizes[i][1])
		{
			min[i] = sizes[i][1];
		}
		else {
			min[i] = sizes[i][0];
		}
		if (min[i]>minmax)
		{
			minmax = min[i];
		}
	}
	answer = minmax * max;
	return answer;
}
```
>- 기초적인 for문 if문을 통하여 작성을 하였는데 생각보다 빨리 풀려졌습니다.

 >구간 합 구하기 5
 ```c++
#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int arr[1025][1025] = { 0 };
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2 + 1; i++)
		{
			for (int j = y1; j < y2 + 1; j++)
			{
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}
}
 ```
 >- 풀면서도 시간초과가 뜰 것 같다는 느낌은 있었습니다.
 >- dp문제임을 확인하였는데 dp를 좀 더 공부를 해야함을 느꼈습니다.
 
 

