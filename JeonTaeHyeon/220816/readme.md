
# 문제풀이
## 무기공학

https://www.acmicpc.net/problem/18430
 ```c++
int case1(int x, int y){
	int sum = map[x][y] * 2 + map[x][y - 1] + map[x + 1][y];
	return sum;
}
int case2(int x, int y) {
	int sum = map[x][y] * 2 + map[x][y + 1] + map[x + 1][y];

	return sum;
}
int case3(int x, int y) {
	int sum = map[x][y] * 2 + map[x-1][y] + map[x][y-1];
	return sum;
}
int case4(int x, int y) {
	int sum = map[x][y] * 2 + map[x-1][y] + map[x][y+1];
	return sum;
}

bool check1(int x, int y) {
	if (x + 1 < n && y - 1 >=0 && !visit[x + 1][y] && !visit[x][y - 1])return true;
	else return false;
}
bool check2(int x, int y) {
	if (x + 1 < n && y + 1 < m && !visit[x + 1][y] && !visit[x][y + 1])return true;
	else return false;
}
bool check3(int x, int y) {
	if (x -1 >= 0 && y - 1 >= 0 && !visit[x -1][y] && !visit[x][y - 1])return true;
	else return false;
}
bool check4(int x, int y) {
	if (x - 1 >=0 && y + 1 < m && !visit[x - 1][y] && !visit[x][y + 1])return true;
	else return false;
}


void back(int x, int y, int sum) {
	if (y == m) {
		y = 0;
		x++;
	}
	if (x == n) {
		res = max(res, sum);
		return;
	}


	if (!visit[x][y]) {
		if (check1(x,y)) {
			visit[x][y] = true;
			visit[x + 1][y] = true;
			visit[x][y - 1] = true;
			back(x, y+1, sum + case1(x, y));
			visit[x][y] = false;
			visit[x + 1][y] = false;
			visit[x][y - 1] = false;
		}
		if (check2(x, y)) {
			visit[x][y] = true;
			visit[x + 1][y] = true;
			visit[x][y + 1] = true;
			back(x, y+1, sum + case2(x, y));
			visit[x][y] = false;
			visit[x + 1][y] = false;
			visit[x][y + 1] = false;
		}
		if (check3(x, y)) {
			visit[x][y] = true;
			visit[x - 1][y] = true;
			visit[x][y - 1] = true;
			back(x, y+1, sum + case3(x, y));
			visit[x][y] = false;
			visit[x - 1][y] = false;
			visit[x][y - 1] = false;
		}
		if (check4(x, y)) {
			visit[x][y] = true;
			visit[x - 1][y] = true;
			visit[x][y + 1] = true;
			back(x, y+1, sum + case4(x, y));
			visit[x][y] = false;
			visit[x - 1][y] = false;
			visit[x][y + 1] = false;
		}
	}
	back(x, y+1, sum);
	return;
}


int main() {
	cin >> n>> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	back(0, 0, 0);
	cout<< res;
}
 ```
처음에는 이중for문을 사용한 백트레킹으로 접근하려 했는데 너무 복잡하여 풀지 못했습니다. 결국 for문을 사용하지 않고 더욱 간단하게 찾는 풀이를 참고하여 해결했습니다.


## 기지국 설치
https://school.programmers.co.kr/learn/courses/30/lessons/12979
```c++
int solution(int n, vector<int> stations, int w)
{
    int cur=1;
    int answer = 0;
    for(int i=0;i<stations.size();i++){
        int sta=stations[i]-w;
        int temp=sta-cur;
        if(cur>=sta){
            cur=stations[i]+w+1;
            continue;
        }
        if(temp%(w*2+1)==0){
            answer+=temp/(w*2+1);
        }
        else{
            answer+=temp/(w*2+1)+1;
        }
        cur=stations[i]+w+1;
    }
    if(cur<=n){
        if((n-cur+1)%(w*2+1)==0)answer+=(n-cur+1)/(w*2+1);
        else answer+=(n-cur+1)/(w*2+1)+1;
    }

    return answer;
}
```
수를 나누고 반올림을 하는 방법을 찾았다면 쉽게 풀 수 있었던 것 같습니다.



## 외계인의 기타연주


https://www.acmicpc.net/problem/2841
```c++
int  main() {
	cin >> n >> p;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> l;
		if (guitar[s].empty()) {
			guitar[s].push(l);
			res++;
		}
		else if (!guitar[s].empty() && guitar[s].top() == l) continue;
		else if (!guitar[s].empty() && guitar[s].top() < l) {
			guitar[s].push(l);
			res++;
		}
		else if (!guitar[s].empty() && guitar[s].top() > l) {
			while (!guitar[s].empty() && guitar[s].top() > l) {
				guitar[s].pop();
				res++;
			}
			if (!guitar[s].empty() && guitar[s].top() == l)continue;
			else {
				guitar[s].push(l);
				res++;
			}
		}
	}
	cout << res;
}
```
최근에 스택을 사용한 문제를 여럿 풀어봐서 좀 더 쉽게 접근할 수 있었던 것 같습니다.

##  쿼드압축 후 개수세기

https://school.programmers.co.kr/learn/courses/30/lessons/68936
```c++
void recursive(int x,int y, int size) {
    bool check = true;
    int temp = comp[x][y];
    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++) {
            if (temp != comp[i][j]) {
                check = false;
                break;
            }
        }
    }

    if (check) {
        if (temp == 1) {
            one++;
        }
        if (temp == 0) {
            zero++;
        }
        return;
    }
    else {
        int half = size / 2;
        recursive(x, y, half);
        recursive(x, y+half, half);
        recursive(x+half, y, half);
        recursive(x+half, y+half, half);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    comp=arr;
    int size=arr[0].size();
    recursive(0,0,size);
    vector<int> answer;
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}
```
이전에 비슷한 문제를 풀어본 경험이 있어 재귀로 접근해야 하는 것을 바로 알았습니다. 함수를 재귀적으로 호출할때 어떤 좌표가 들어가야 하는지가 중요한 문제였던 것 같습니다.


## 요세푸스 문제


https://www.acmicpc.net/problem/1158
```python
n,k=map(int,input().split())

arr=[i for i in range(1,n+1)]
res=[]
cur=0

for j in range(n):
    cur+=k-1
    if(cur>=len(arr)):
        cur=cur%len(arr)
    res.append(str(arr.pop(cur)))

print("<",", ".join(res)[:],">",sep='')
```
파이썬은 index가 범위를 초과해도 다시 첫번쨰 index로 넘어온다는 것을 생각하여 python으로 풀면 훨씬 쉬울 것이라고 생각했습니다. 막상 문제는 그렇게 풀지 않았지만 파이썬의 print함수를 사용해보면서 파이썬의 대단함을 다시 한번 느껴보는 문제였습니다.


