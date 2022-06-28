
# 줄 서는 방법
### pro12936
+ `순열`
```c++
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long check = 1;
    for (int i = 1; i < n; i++) check *= i; // n개 중 1개를 선택하고 나머지의 경우의 수 -> (n-1)의 경우의 수
    for (int i = 1; i <= n; i++) v.push_back(i); // 1~n까지

    int len = n - 1;

    while (v.size() != 1) { // v에 하나가 남으면 멈추게
        for (int i = 1; i <= v.size(); i++) {
            //i는 1부터 시작하기 때문에 경우의 수로 자기보다 클 때 이전의 값을 넣어주면 된다.
            if (i * check >= k) { // 경우의 수로 자기보다 클 때
                answer.push_back(v[i - 1]); // 그 이전의 값을 뒤로 넣어준다.
                v.erase(v.begin() + i - 1); // v에선 지워줘
                // 원하는 번째의 경우의 수에 고려한 경우의 수를 빼준다.
                k -= (i - 1) * check; // k에선 그만큼의 경우의 수를 빼준다.
                // 하나를 골랐으니 n -> n-1의 경우의 수를 고려하는 셈이다.
                check /= (len--); // 길이의 경우의 수를 빼준다.
                break;
            }
        }
    }

    answer.push_back(v[0]); // 마지막값을 넣어준다.

    return answer;
}
```
>-  너무 수학적인 문제라 마음은 안들지만, 머리좀 아팠다...
>- 해설을 보고 해석하는데 시간이 오래 걸렸다.
>- 언젠가 해설을 안보고도 이런걸 풀 수 있을까...
>- 쉬워보였는데, level3이었다는 사실이 놀랍다 ㅋㅋ;


# 입국 심사
### pro43238
- `이분 탐색`
```c++
long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = (long long)times[0]; // 가장 왼쪽(짧은) 걸리는 시간
    long long right = (long long)times[times.size() - 1] * n; // 가장 오른쪽 걸리는 시간 * 사람의 수 -> 가장 오래걸리는 경우
    long long answer = right; // 
    while (left <= right) { // left와 right교차되는 부분
        long long mid = (right + left) / 2; // 가운데 부분
        long long pass = 0;

        for (int i = 0; i < times.size(); i++) {
            pass += mid / (long long)times[i];
            //둘의 평균을 시간들로 나눠서 더해준다.
            //mid로 계산했을 때 총 걸리는 시간.
        }
        //해당 시간 내에 모든 사람들의 심사가 끝나는지 여부
        if (pass >= n) { // pass로 인원들을 다 계산할 수 있을 때
            right = mid - 1; // right의 범위 줄이기
            if (mid <= answer) answer = mid;
        }
        //안되면 왼쪽을 끌어와 mid를 올려준다.
        else left = mid + 1;
    }

    return answer;
}
```
> - 이분 탐색에 대해 공부하기 위해 고른 문제였는데... 생각보다 이론이랑 매우 달랐다.
> - pass와 mid를 활용해서 이분 탐색을 하는 과정에 대해 이해했지만, 알고리즘 적인 이분탐색과는 좀 다른 느낌이었다.


# 튜플
### pro64065
- `파이썬`
```python
def solution(s):
   stack = []

   s = s[2:-2] # {{, }}빼주기
   s = s.split('},{') # 숫자 나눠주기
   s.sort(key=len) # list가 정렬되는 개사기 파이썬

   for i in s :
       spy = i.split(',') # split이 편한 개사기 파이썬
       for j in spy :
           if not int(j) in stack : # 배열에서 if로 확인해주는 개사기 파이썬
               stack.append(int(j))
   return stack
```
> - 그저 나쁜 파이썬

# 절댓값 힙
### bj11286
- `나쁜 문제.`
- 읽고나니 굳이 풀어야하나 생각이 들었다.

