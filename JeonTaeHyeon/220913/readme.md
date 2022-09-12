
# 문제풀이
## 스킬트리

https://school.programmers.co.kr/learn/courses/30/lessons/49993
 ```c++
#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees){
    int answer = 0;
    for(int k=0;k<skill_trees.size();k++){
        string comp="";
    for(int j=0;j<skill_trees[k].size();j++){
   for(int i=0;i<skill.size();i++){
       if(skill[i]==skill_trees[k][j])comp+=skill_trees[k][j];   
   } 
    }
        cout<<comp<<endl;
        if(comp.size()==0)++answer;
        for(int i=0;i<comp.size();i++){
            if(skill[i]!=comp[i])break;
            if(i==comp.size()-1)++answer;
        }
    }
    return answer;
}
 ```
스킬트리와 관련없는 문자는 무시하고 스킬트리와 관련있는 문자만 string에 더해서 스킬트리에 맞으면 ++을 해주는 방식으로 풀었습니다. for문이 많이 써서 풀었는데 더 좋은 풀이가 있을 것 같습니다.


##  최소 스패닝 트리
https://www.acmicpc.net/problem/1197
```c++

```
풀수 있을 것 같았는데 생각보다 어려워서 풀지 못했습니다. 크루스칼 - 프림 알고리즘이라는데 배운기억만있고 내용은 하나도 없습니다 ㅠㅠ

## 골드바흐의 추측


https://www.acmicpc.net/problem/9020
```c++
int prime[10001];
int t,n;

int main() {
	for (int i = 2; i <= 10000; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(10000); i++)
	{
		if (prime[i] == 0) {
			continue;
		}
		for (int j =i*i; j <= 10000; j=j+i)
		{
			prime[j] = 0;
		}
	}

	cin >> t;
	while (t--) {
		int dif = 10001;
		int cur = 0;
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			if (prime[i]) {
				if (prime[n - i]) {
					if (dif > abs(2 * i - n)) {
						dif = abs(2 * i - n);
						cur = i;
					}
				}
			}
		}
		if (cur < n - cur)cout << cur << " " << n - cur<<"\n";
		else { cout << n - cur <<" " << cur<<"\n"; }
	}
}
```
에라토스테네스의 채를 사용하여 풀었습니다. 여러 tc가 주어지는 문제에서 개행문자를 빠뜨려서 틀리는 실수를 고쳐야 될것 같습니다.


## 최소직사각형



https://school.programmers.co.kr/learn/courses/30/lessons/86491
```c++
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int getmax(vector<vector<int>>v){
    int res=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<2;j++){
            res=max(res,v[i][j]);
        }
    }
    return res;
}

int solution(vector<vector<int>> sizes) {
    int m=getmax(sizes);
    vector<int>res;
    for(int i=0; i<sizes.size();i++){
        int temp=min(sizes[i][0],sizes[i][1]);
        res.push_back(temp);
    }
    sort(res.begin(),res.end());
    
    int answer = res[res.size()-1]*m;
    return answer;
}
```
전체에서 가장 큰놈이랑 모든 가로세로중 작은 값들 중 가장 큰값을 찾아서 곱하면 되는 문제였습니다.

## 구간 합 구하기5


https://www.acmicpc.net/problem/11660
```c++
int dp[1025][1025];
int m;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];

		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] + dp[x1 - 1][y1 - 1] - dp[x1 - 1][y2] - dp[x2][y1 - 1] <<"\n";

	}

}
```
점화식이 길고 자주 보이는 점화식이 아니라서 생각하는데에 오래걸렸습니다. 열심히 풀고 개행문자를 빠뜨려서 절망했습니다.
