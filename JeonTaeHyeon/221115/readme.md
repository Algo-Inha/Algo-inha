
# 문제풀이
## 파이프옮기기
https://www.acmicpc.net/problem/11053
 ```c++
int house[17][17];
int dp[17][17];
int n;

int dx[] = {0,1,1};
int dy[] = {1,1,0};
int res;

void dfs(int num1, int num2) {
	queue<pair<int, pair<int, int>>>q;
	q.push({ num1, { num2,0 } });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int type = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == n - 1) {
			++res;
			return;
		}

		for (int i = 0; i <3 ; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			int ttype = i;
			if (abs(type - ttype < 2)) {
				if (xx >= 0 && yy >= 1&&xx<n&&yy<n&&!house[xx][yy]) {
					q.push({ xx,{yy,ttype} });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> house[i][j];
		}
	}

	dfs(0, 1);
	cout << res;
}

 ```
파이프를 밀면서 벽에 부딪히는 것도 고려해줘야 하는데 그러질 않아서 에러가 발생한거 같습니다. 다시 풀어보겠습니다.


##  사탕게임
https://www.acmicpc.net/problem/3085
```c++

void candycounter() {
	int counter = 0;
	int index = 1;

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{

			while (map[x][y] == map[x][y + index]) {
				++counter;
				++index;
			}
			res = max(counter+1, res);
			counter = 0; index = 1;
			while (map[x][y] == map[x + index][y]) {
				++counter;
				++index;
			}
			res = max(counter+1, res);
			counter = 0; index = 1;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] != map[i][j + 1] && map[i + 1][j] != 0) {
				swap(map[i][j],map[i][j + 1]);
				candycounter();
				swap(map[i][j], map[i][j + 1]);
			}

			if (map[i][j] != map[i+1][j]&& map[i + 1][j]!=0) {
				swap(map[i][j], map[i+1][j]);
				candycounter();
				swap(map[i][j], map[i+1][j]);
			}
		}
	}
	cout << res;
}
```
가로나 세로로 인접한 사탕이 서로 다를 때 swap해준 후 candycounter 함수를 호출하여 가장 큰 연속하는 사탕의 수를 구했습니다. 

## 안녕

https://www.acmicpc.net/problem/1535
```c++
void hi(int curhp,int curp,int cur) {
	if (curhp <= 0)return;
	if (cur == n) {
		res = max(res, curp);
		return;
	}

	hi(curhp - hp[cur], curp + p[cur], cur + 1);
	hi(curhp, curp, cur+1);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> hp[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	hi(100, 0, 0);
	cout << res;
}
```
재귀를 통한 완전탐색으로 풀었습니다. 대표적인 재귀 완탐문제였던 것 같습니다.

##  오픈채팅방
https://school.programmers.co.kr/learn/courses/30/lessons/42888
```c++
vector<string> answer, state;
map<string, string> user;

vector<string> solution(vector<string> record) {
    for(int i = 0; i < record.size(); i++)
    {
        string inf[3];
        string token;
        stringstream ss(record[i]);
        int index = 0;
        
        while(ss >> token){
            inf[index] = token;
            ++index;
        }
        string type,uid,name;
        type=inf[0];
        uid=inf[1];
        name=inf[2];
        
        if(type == "Enter")
        {
            state.push_back("님이 들어왔습니다.");
            answer.push_back(uid);
            user[uid] = name;
        }
        else if(type == "Leave")
        {
            state.push_back("님이 나갔습니다.");
            answer.push_back(uid);
        }
        else if(type=="Change")
            user[uid] = name;
    }
    
    for(int i = 0; i < answer.size(); i++)
        answer[i] = user[answer[i]] + state[i];
    
    return answer;
}
```
파싱하는 과정이 너무 귀찮아서 찾아봤는데 sstream을 사용하여 훨씬 쉽게 풀 수 있었습니다. map으로 uid와 name을 처리하여 풀 수 있었습니다.
