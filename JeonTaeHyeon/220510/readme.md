
# 문제풀이
## 꽃길
https://www.acmicpc.net/problem/14620
<!--line-->
 ```c++
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<set>
#include<cstring>
#include<math.h>
using namespace std;

int map[11][11];
bool visit[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int flower;
int money;
int min_=123123123;
int n;

void revisit(int num1, int num2) {
	visit[num1][num2] = false;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = false;
	}
}

void makevisit(int num1, int num2) {
	visit[num1][num2] = true;

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];

		visit[x][y] = true;
	}
}

int bfs(int num1, int num2) {
	int sum = map[num1][num2];

	for (int i = 0; i < 4; i++)
	{
		int x = num1 + dx[i];
		int y = num2 + dy[i];
		if (x >= 1 && y >= 1 && x <= n && y <= n && !visit[x][y]) {
			sum += map[x][y];
		}
		else {
			sum = -1;
			return sum;
		}
	}
	makevisit(num1,num2);
	return sum;
}

void res() {
	if (flower == 3) {
		min_ = min(min_, money);
		return;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j= 2; j < n; j++)
		{
			if (!visit[i][j]) {
				int m=bfs(i,j);
				if (m>=0){
					money += m;
					flower++;
					res();
					money -= m;
					flower--;
					revisit(i, j);
				}
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	res();

	cout << min_;
}
 ```
가장 중요했던것은 언제 visit처리를 해야하는지 였던 것 같습니다. 꽃이 죽는다면 아예 visit처리를 하지 않고 꽃이 살아있을 때만 visit처리를 해줘야했습니다.

## 톱니바퀴
https://www.acmicpc.net/problem/14891
```c++
void spin(int num, int dir, int l, int r) {
	if (dir == 1) {
		int left = num - 1;
		int right = num + 1;
		int leftcmp1;
		int leftcmp2;
		int rightcmp1;
		int rightcmp2;
		if (left >= 0) {
			leftcmp1 = saw[num][6];
			leftcmp2 = saw[left][2];
		}
		if (right < 4) {
			rightcmp1 = saw[num][2];
			rightcmp2 = saw[right][6];
		}

		rotate(saw[num], saw[num] + 7, saw[num] + 8);

		if (left >= 0 && leftcmp1 != leftcmp2 && !l) {
			spin(left, -1, 0, 1);
		}
		if (right < 4 && rightcmp1 != rightcmp2 && !r) {
			spin(right, -1, 1, 0);
		}

	}
	if (dir == -1) {
		int left = num - 1;
		int right = num + 1;
		int leftcmp1;
		int leftcmp2;
		int rightcmp1;
		int rightcmp2;
		if (left >= 0) {
			leftcmp1 = saw[num][6];
			leftcmp2 = saw[left][2];
		}
		if (right < 4) {
			rightcmp1 = saw[num][2];
			rightcmp2 = saw[right][6];
		}

		rotate(saw[num], saw[num] + 1, saw[num] + 8);

		if (left >= 0 && leftcmp1 != leftcmp2 && !l) {
			spin(left, 1, 0, 1);
		}
		if (right < 4 && rightcmp1 != rightcmp2 && !r) {
			spin(right, 1, 1, 0);
		}
	}
}
```
움직이는 톱니를 기준으로 재귀적으로 왼쪽과 오른쪽 톱니를 확인했습니다. 이때 신경써야 했던 것은 인자로 자신을 움직인 톱니가 무엇인지 전달하여 반복적으로 톱니가 돌아가는 것을 방지해야했습니다.

## 개똥벌레
https://www.acmicpc.net/problem/3020
```c++
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;

int n, h;
int top[250001];
int bottom[250001];
int save[500001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> h;
	int length;

	for (int i = 1; i <= n / 2; i++)
	{
		cin >> length;
		bottom[i] = length;
		cin >> length;
		top[i] = length;
	}

	sort(bottom + 1, bottom + n / 2 + 1, greater<int>());
	sort(top + 1, top + n / 2 + 1, greater<int>());

	int cnt = 1;
	while (true) {
		if (bottom[cnt] == bottom[cnt + 1])++cnt;
		else {
			int k = bottom[cnt] - bottom[cnt + 1];
			while (k) {
				save[bottom[cnt] - k + 1] += cnt;
				k--;
			}
			//	cout << cnt << endl;
			++cnt;
		}
		if (bottom[cnt] == 0)break;
	}
	cnt = 1;
	while (true) {
		if (top[cnt] == top[cnt + 1])++cnt;
		else {
			int k = top[cnt] - top[cnt + 1];
			while (k) {
				save[h - top[cnt] + k] += cnt;
				k--;
			}
			++cnt;
		}
		if (top[cnt] == 0)break;
	}

	sort(save + 1, save + h + 1);



	cnt = 1;
	while (true) {
		if (save[cnt] == save[cnt + 1])cnt++;
		else break;
	}
	cout << save[1] << " " << cnt;
}
```
처음엔 쉬운문제라고 생각했는데 생각대로 푸니 역시 시간초과가 나왔습니다.
새로 풀 때는 내림차순으로 석순과 종유석을 정렬하여  누적합을 이용하여 계산했습니다.

## 타겟 넘버
https://programmers.co.kr/learn/courses/30/lessons/43165
```c++
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans=0;

void res(int size, int cur,int sum,int target,vector<int>v){
    if(cur==size){
        if(sum==target){
            ++ans;
        }
        return;
    } 
    int temp=v[cur];
    
    res(size,cur+1,sum+temp,target,v);
    res(size,cur+1,sum-temp,target,v);
}

int solution(vector<int> numbers, int target) {
    res(numbers.size(),0,0,target,numbers);
    int answer = ans;
    return answer;
}
```
재귀적으로 모든 경우를 확인하여 tartget의 값과 sum의 값이 같을때 count 해주는 방식으로 해결했습니다.
