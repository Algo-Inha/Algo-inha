
# 문제풀이
## 숫자의 표현


https://school.programmers.co.kr/learn/courses/30/lessons/12924
 ```c++
#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int size=n;//size =n/2를 하지 않아도 효율성 통과..?
    for(int i=1;i<=size;i++){
        int sum=0;
        for(int j=i;j<=size;j++){
            sum+=j;
            if(sum>n)break;
            if(sum==n){
                cout<<sum<<endl;
                ++answer;
                break;
        }
    }
    }
    return answer;
}
 ```
DP 문제인줄 알았는데 완탐문제였습니다. size/2를 하지않아도 시간초과가 발생하지 않았고, 중요했던건 sum>n일 때의 처리를 해주는 것이었던것 같습니다.


##  듣보잡
https://www.acmicpc.net/problem/1764
```c++
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		s.insert(name);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		if (s.find(name) != s.end()) {
			ans.insert(name);
		}
	}
	cout << ans.size() << endl;
	for (auto a : ans) {
		cout << a << endl;
	}
}
```
중복되는 이름에 대한 처리가 필요한 문제가 아니었기 때문에 set을 사용하여 쉽게 풀 수 있었습니다.

## 나이트의 이동
https://www.acmicpc.net/problem/7562
```c++
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (!visit[xx][yy] && xx >= 0 && yy >= 0 && xx < n && yy < n) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
				cnt[xx][yy] = cnt[x][y] + 1;
			}
		}

	}

}



int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++)
	{
		cin >> n;
		int i, j;
		cin >> i >> j;
		q.push({ i,j });
		visit[i][j] = true;
		bfs();
		cin >> i >> j;
		cout << cnt[i][j] << endl;

		for (int hh = 0; hh < n; hh++)
		{
			memset(visit[hh], NULL, sizeof(visit[hh]));
			memset(cnt[hh], NULL, sizeof(visit[hh]));
		}

	}

}
```
8방향에 대한 index설정을 잘해준 후 bfs를 돌리면 쉽게 풀 수 있는 문제였습니다.


##  올림픽
https://www.acmicpc.net/problem/8979
```c++
int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        cin >> g[index] >> s[index] >> b[index];
    }
    for (int i = 1; i <= n; i++) {
        if (g[i] > g[m]) {
            res++;
        }
        else if (g[i] == g[m]) {
            if (s[i] > s[m]) {
                res++;
            }
            else if (s[i] == s[m]) {
                if (b[i] > b[m]) {
                    res++;
                }
            }
        }
    }

    cout << res + 1;
}
```
정렬을 사용하지 않고 경우에 따라 res값을 증가시켜주는 형태로 풀었습니다.
