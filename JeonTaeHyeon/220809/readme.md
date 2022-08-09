
# 문제풀이
## 양궁대회
https://school.programmers.co.kr/learn/courses/30/lessons/92342
 ```c++
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int res=-1;
int N;
int temp[11];
vector<int> answer;

void back(int cur,int* score,vector<int>info){
    if(cur==N){
        int sumR=0;
        int sumA=0;
        for(int i=0;i<=10;i++){
            if(score[i]>info[i])sumR+=i;
            else sumA+=i;
        }
        if(sumR>sumA){
            if(sumR-sumA==res){
                for(int i=10;i>=0;i--){
                    if(answer[i]<score[i]){
                        answer.clear();
                        for(int j=0;j<=10;j++){
                            answer.push_back(score[i]);
                        }
                        break;
                    }
                    else{
                        break;
                    }
                    
                }
            }
            
            
            else{
                res=max(res,sumR-sumA);
                answer.clear();
                for(int j=0;j<=10;j++){
                            answer.push_back(score[j]);
                        }
            }
        }
        return;
    }
    for(int i=0;i<=10;i++){
        ++score[cur];
        ++cur;
        back(cur,score,info);
        cur--;
        score[cur]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    N=n;
    back(0,temp,info);
    return answer;
}
 ```
dfs를 이용하여 풀려했는데 실패했습니다. 푸는 방법은 알것 같아서 다시 풀어보겠습니다.


## 2개 이하로 다른 비트
https://school.programmers.co.kr/learn/courses/30/lessons/77885?language=cpp
```c++
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto n:numbers){
        if(n%2==0){
            answer.push_back(n+1);
        }//짝수는 항상 +1이 들어감
        else{
            long long temp=n;
            string res="";
            while(temp-1>0){
                if(temp%2==0){
                    res='0'+res;
                }
                else{
                    res='1'+res;
                }
                temp/=2;
            }
            if(temp)res='1'+res;
            //2진수로 만들기
            for(int i=res.size()-1;i>=0;i--){
                if(res[i]=='0'){
                    res[i]='1';
                    res[i+1]='0';
                    break;
                }//규칙 1 : 2진수 비트가 0이면 1로바꿔주고 하위비트를 0으로 바꿔줌
                if(i==0){
                    res='1'+res;
                    res[1]='0';
                    break;
                }//규칙 2 : 모든 비트가 1이라면 MSB1을 추가하고 하위비트를 0으로 바꿔줌
            }
            temp=0;
            long long e=1;
            for(int i=res.size()-1;i>=0;i--){
                if((res[i]-'0'))temp+=e;
                e*=2;
            }//다시 정수로 바꾸기
            answer.push_back(temp);
            }
        }
    
    return answer;
}
```
홀수일 때의 규칙을 찾는 것이 어려웠습니다.
숫자를 2진수 string으로 바꾸어 연산을 한 후 다시 10진수로 바꿔주는 방법을 사용했는데, 다른 분들 풀이를 보니 이렇게 하지 않고 10진수인 상태에서 계산을 할 수 있었습니다. 그 방법이 속도와 메모리면에서 훨씬 더 좋은 코드인 것 같습니다. 



## 게리멘더링 2

https://www.acmicpc.net/problem/17779
```c++
//게리멘더링 2
//https://www.acmicpc.net/problem/17779
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

const int INF = INT_MAX;
int N;
int map[21][21];

int diff(int x, int y, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0] += map[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1] += map[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += map[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += map[r][c];
			}
			//5번 선거구
			else {
				population[4] += map[r][c];
			}
		}
	}

	sort(population.begin(), population.end());

	return population[4] - population[0];
}

int minDiff() {
	int res = INF;

	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= N - x - 1; d1++) {
				for (int d2 = 1; d2 <= N - y && d2 <= N - x - 1; d2++) {
					res = min(res, diff(x, y, d1, d2));
				}
			}
		}
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> map[x][y];
		}
	}

	cout << minDiff() << endl;
}
```
혼자서 해결하지 못해 다른분의 풀이를 참고했습니다.
선거구의 경계를 처리할 때 오류가 있었던 것 같습니다.

##  최댓값과 최솟값

https://school.programmers.co.kr/learn/courses/30/lessons/12939?language=python3
```python
def solution(s):
    arr=list(map(int,s.split(' ')))
    return str(min(arr))+" "+str(max(arr))
```
처음으로 파이썬으로 푼 문제입니다. 왜 파이썬을 써야하는지 잘 알게되었습니다.


## 오큰수

https://www.acmicpc.net/problem/17298
```c++
int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	for (int i = n-1; i >=0; i--)
	{
		while (!s.empty() && s.top() <= num[i])s.pop();

		if (!s.empty())res[i]= s.top();
		else res[i] = -1;

		s.push(num[i]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << " ";
	}
}
```
스택을 사용하여 푸는 문제였습니다. 가장 뒤쪽의 숫자를 먼저 스택에 푸쉬하고,  앞의 숫자와 비교하여 오큰수가 될수있다면 ```res[i]= s.top();```을 해주고 될수 없다면 ``num[i])s.pop();```을 해주어 결과를 구했습니다.

