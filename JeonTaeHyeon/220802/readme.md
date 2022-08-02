
# 문제풀이
## 거리두기 확인하기
https://school.programmers.co.kr/learn/courses/30/lessons/81302
 ```c++
#include <string>
#include <vector>
#include<iostream>
using namespace std;

char map[5][5];
bool visit[5][5];
bool flag=true;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


void dfs(int x, int y,int cur){
    if(flag){
    if(cur==2){
        if(map[x][y]=='P')flag=false;
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0&&yy>=0&&xx<5&&yy<5&&map[xx][yy]!='X'&&!visit[xx][yy]){
            visit[xx][yy]=true;
            if(map[xx][yy]=='P'){
                flag=false;
            }
            dfs(xx,yy,cur+1);
        }
    }
    }
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int t=0;
    while(t<5){
        flag=true;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                map[i][j]=places[t][i][j];
                cout<<map[i][j];
            }
            cout<<endl;
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(map[i][j]=='P'&&flag){
                    visit[i][j]=true;
                    dfs(i,j,0);
                }
            }
        }
        if(flag)answer.push_back(1);
        else answer.push_back(0);
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                visit[i][j]=false;            }
        }
        t++;
    }
    
    return answer;
}
 ```
맨해튼 거리가 2 이하임을 만족하는 범위에 다른 응시자가 있다면 false를 그렇지 않다면 true를 반환하도록 하였습니다.


## 회의실 배정
https://www.acmicpc.net/problem/1931
```c++
int s[1001];
int DP[1001];
int n;


int main() {
	vector<pair<int, int>>v;

	int n ,start,end;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		v.push_back({ end,start });
	}

	sort(v.begin(), v.end());
	
	int time = v.front().first;
	int cnt = 1;
	for (int i = 1; i <n ; i++)
	{
		if (v[i].second >= time) {
			cnt++;
			time = v[i].first;
		}
	}

	cout << cnt;


}
```
회의가 끝나는 시간을 기준으로 정렬을 하여 풀어야 하는 문제였습니다. 정렬한 후 회의가 시작하는 시간과 끝나는 시간을 비교하여 회의의 최대 개수를 구하였습니다.



## 타일채우기

https://www.acmicpc.net/problem/2133
```c++
int main() {
	cin >> n;
	dp[2] = 3;
	dp[0]=1;
	for (size_t i = 4; i <= 30; i+=2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j+=2)
		{
			dp[i] += 2 * dp[i-j];
		}
	}
	cout << dp[n];
}
```
혼자서 해결하지 못해 다른분의 풀이를 참고했습니다.
가로의 크기가 4이상인 경우에서 크기가 2가 증가할 때마다 고려해야 하는 경우의 수가 2개씩 더 생기기 때문에 
```c++
for (int j = 4; j <= i; j+=2)
		{
			dp[i] += 2 * dp[i-j];
		}
```
해당 코드가 필요하였습니다. 

##  단지번호붙이기

https://www.acmicpc.net/problem/2667
```c++
int dp[91];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int MAP[26][26];
int visit[26][26];
string input[26];
multiset<int> s;

void bfs(int num1, int num2) {
	queue < pair<int, int>>q;
	int cnt = 1;
	q.push({ num1,num2 });
	visit[num1][num2] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(!visit[xx][yy]&& MAP[xx][yy] && xx >= 0 && yy >= 0 && xx < n && yy < n) {
				visit[xx][yy] = true;
				q.push({ xx,yy });
				++cnt;//단지의 크기 측정하기
			}
		}
	}
	
	s.insert(cnt);//단지 크기 insert
	cnt = 0;//까먹지 않고 초기화하기


}


int main() {
	cin >> n;
	int cnt=0;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		for (int j = 0; j < n; j++)
		{
			 MAP[i][j]=input[i][j]-'0';
		}
	}
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j]&&MAP[i][j]) {
				bfs(i, j);
				++cnt;//단지의 개수 측정
			}
		}
	}
	cout << cnt << endl;
	for (auto a : s) {
		cout << a << endl;
	}
}
```
bfs를 이용하여 풀었습니다. 단지 하나의 크기는 bfs함수가 끝날때 multiset에 insert하여 출력하였고, 총 단지의 개수는  bfs함수가 호출될 때마다 cnt를 증가시켜 출력하였습니다.


## 안전 영역

https://www.acmicpc.net/problem/2468
```c++
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int h = 0;
int cnt = 0;
queue<pair<int, int>> q;
int map[101][101];
int visit[101][101];


void bfs() {
	cnt = cnt + 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (!visit[xx][yy] && xx > 0 && yy > 0 && xx <= n && yy <=n  && map[xx][yy]>=h) {
				q.push({ xx,yy });
				visit[xx][yy] = true;
			}
		}


	}
}

int main() {
	int res = 0;
	cin >> n;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (; h < 101; h++)
	{


		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] >= h&&!visit[i][j]) {//안전지대인 경우
					q.push({ i,j });
					visit[i][j] = true;
					bfs();
				}
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				visit[i][j] = NULL;
			}
		}//까먹지 말고 초기화
		res = max(res, cnt);
		cnt = 0;
	}

	cout << res;
}
```
높이를 증가시키면서 어떤 높이 일떄 bfs함수를 가장 많이 호출시킬 수 있는지 파악하는 문제였습니다. 위의 단지번호 붙이기와 유사한 문제였던 것 같습니다. 

