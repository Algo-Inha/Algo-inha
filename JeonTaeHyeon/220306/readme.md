
# 문제풀이
## 정사각형
https://www.acmicpc.net/problem/2529 
```c++
void back(int cur) {
	if (cur == k + 1) {
		string temp="";
		for (int i = 0; i < k; i++)
		{
			if (insign[i] == '<') {
				if (save[i] > save[i + 1])return;
			}
			else if (insign[i] == '>') {
				if (save[i] < save[i + 1])return;
			}
			temp += to_string(save[i]);
		}
		temp += to_string(save[k]);
		long long tempmx = stoll(temp);
		long long tempmn = stoll(temp);
		if (mx < tempmx) {
			resmx = temp;
			mx = tempmx;
		}

		if (mn >tempmn) {
			resmn = temp;
			mn = tempmn;
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!visit[i]) {
			visit[i] = true;
			save[cur] = i;
			back(cur + 1);
			visit[i] = false;
		}
	}
}


int main() {
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char sign;
		cin >> sign;
		insign.push_back(sign);
	}
	back(0);

	cout << resmx << endl << resmn;
}
 ```
백트렉킹을 사용하여 모든 경우의 수를 다 확인하는 방법을 사용했습니다. 무조건 부등호 수+1개의 숫자가 완성이 됐을 때 유효성 검사를 하였는데 사실 모든 step에서 유효성 검사가 가능하기 때문에 그렇게 다시 짠다면 더 효율적일 것 같습니다.


##  자두나무
https://www.acmicpc.net/problem/2240
```c++
int  main() {
	cin >> t >> w;
	for (int i = t; i >= 1; i--)
	{
		int temp;
		cin >> temp;
		plum[i] = temp;
	}
	memset(dp, -1, sizeof(dp));

	/*
	dp[time][move][position]

	case 1: 현재위치에서 자두가 떨어질 때
	dp[time+1][move][postion]=	dp[time][move][position]+1;


	case 2: 다른위치에서 자두가 떨어질 때

	1)자리를 옮기지 않음
	dp[time+1][move][postion]=dp[time][move][position];
	
	2)자리를 옮김
	dp[time+1][move+1][!postion]=dp[time][move][position]+1;

	*/

	dp[0][0][1] = 0;
	for (int time = 0; time < t; time++)
	{
		for (int move = 0; move <= w; move++) {
			for (int pos = 1; pos < 3; pos++)
			{
				int npos = plum[time + 1];
				if (dp[time][move][pos] >= 0) {
					if (npos == pos) {
						dp[time + 1][move][pos] = dp[time][move][pos] + 1;
					}
					else {
						if (move < w) {
							dp[time + 1][move + 1][npos] = max(dp[time][move][pos] + 1, dp[time + 1][move + 1][npos]);
						}
						dp[time + 1][move][pos] = dp[time][move][pos];
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i <= w; i++)
	{
		for (int j = 1; j < 3; j++) {
			res = max(res,dp[t][i][j]);
		}
	}

	cout << res;

}
```
어떤 반례를 넣어봐도 다 맞았다고 나오는데 뭐가 틀렸는지 모르겠습니다. ㅠㅡㅠ

## 이모티콘 할인행사


https://school.programmers.co.kr/learn/courses/30/lessons/150368
```c++
#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
int emo = 0;
int money = 0;
vector<int> v;
int arr[4] = {10,20,30,40};
vector<vector<int>> users; vector<int> emoticons;

void dfs() {                        
    if(v.size() == emoticons.size()) {
        int emo_tmp = 0;
        int money_tmp = 0;
        
        for(int i=0; i<users.size(); i++) {
            int p = 0;
            
            for(int j=0; j<emoticons.size(); j++) {
                if(users[i][0] <= v[j]) {
                    p = p + emoticons[j] * (100-v[j]) / 100;
                }//할인율이 더 높을때 
            }
            
            if(p >= users[i][1]) { emo_tmp++; }//이모티콘 plus
            else { money_tmp = money_tmp + p; }
        }
        
        if(emo < emo_tmp) {
            emo = emo_tmp;
            money = money_tmp;
        }
        else if(emo == emo_tmp && money < money_tmp) {
            money = money_tmp;
        }
        return;
    }
    
    for(int i=0; i<4; i++) {
        v.push_back(arr[i]);
        dfs();
        v.pop_back();
    }
}
 
vector<int> solution(vector<vector<int>> u, vector<int> e) {
    vector<int> answer;
    users=u;emoticons=e;
    dfs();
    
    answer.push_back(emo);
    answer.push_back(money);
    
    return answer;
}


```
부등호와 비슷한 문제였습니다. 난이도 자체는 부등호보다는 쉽다고 느껴졌던거 같습니다.
