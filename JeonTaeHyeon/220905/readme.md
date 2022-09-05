
# 문제풀이
## 상근이의 여행
https://www.acmicpc.net/problem/9372
 ```c++
int main() {
	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
		}
		cout << n - 1 << "\n";
	}
}
 ```
알고리즘 설계시간에 배웠던 것이 생각나서 이게맞나 하고 풀었는데 맞아서 깜짝놀랐습니다.


## 키패드누르기
https://school.programmers.co.kr/learn/courses/30/lessons/67256?language=cpp
```c++
string solution(vector<int> numbers, string hand) {
    ;
    pair<int, int>L = { 1,4 };
    pair<int, int>R = { 3,4 };
    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            L = { 1,numbers[i] / 3 + 1 };
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            R = { 3,numbers[i] / 3 };
            answer += 'R';
        }
        else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
            int temp = 0;
            if (numbers[i] == 0) { temp = 4; }
            else { temp = numbers[i] / 3 + 1; }
            int sizeL = abs(L.first - 2) + abs(L.second - temp);
            int sizeR = abs(R.first - 2) + abs(R.second - temp);
            if (sizeL < sizeR) {
                L = { 2,temp };
                answer += 'L';
            }
            else if (sizeL > sizeR) {
                R = { 2,temp };
                answer += 'R';
            }
            else {
                if (hand == "right") {
                    R = { 2,temp };
                    answer += 'R';
                }
                else if (hand == "left") {
                    L = { 2,temp };
                    answer += 'L';
                }
            }

        }
    }
    return answer;
}
```
piar<int,int>에 손가락 위치를 계속 업데이트 해줘서 가까운 것을 누르도록 했습니다. 

## 탑

https://www.acmicpc.net/problem/2493
```c++
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> h;

		if (koi.empty()) {
			cout << "0 ";
			koi.push({h,i});
			cur = i;
		}
		else {
			if (koi.top().first > h) {
				cout << koi.top().second << " ";
				koi.push({ h,i });
			}
			else {
				while (!koi.empty() && koi.top().first < h) {
					koi.pop();
					++cur;
				}
				if (koi.empty()) {
					cur = i;
					cout << "0 ";
					koi.push({ h,i });
				}
				else {
					cur = i;
					cout << koi.top().second << " ";
					koi.push({ h,i });
				}
			}
		}
	}
}
```
스택을 처음 배울 때 배웠던 경험이 있는 것 같습니다. 처음에 시간초과가 떠서 당황했는데 다행히 출력속도 문제였어서 해결했습니다.


## 이진변환 반복하기


https://school.programmers.co.kr/learn/courses/30/lessons/70129
```python
def solution(strr):
    answer = []
    zero=0
    change=0
    while(len(strr)!=1):
        size=int(len(strr))
        strr=strr.replace('0','')
        temp=int(len(strr))
        zero+=size-temp
        strr=""
        change+=1
        while(temp):
            re=temp%2
            temp//=2
            strr=str(re)+strr
    answer.append(change)
    answer.append(zero)
    return answer
```
파이썬의 replace함수를 사용하면 쉽게 풀 수 있을 것이라 생각하여 파이썬으로 풀었습니다. 파이썬 초보라서 바보같이 append([change,zero])를 해놓고 왜 틀렸는지 몰라 오랫동안 고민했습니다.

## 소수&팰린드롬

https://www.acmicpc.net/problem/1747
```c++
int prime[1111112];
int n;

int main() {
	for (int i = 1; i <= _size; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i <= sqrt(_size); i++)
	{
		if (prime[i] == 0)continue;
		for (int j = i * i; j <= _size; j += i)
		{
			prime[j] = 0;
		}
	}

	cin >> n;
	if (n == 1) {
		cout << "2";
	}
	else {
		for (int i = n; i <= _size; i++)
		{
			int flag = true;
			if (prime[i]) {
				string temp = to_string(prime[i]);
				for (int i = 0; i < temp.size() / 2; i++)
				{
					if (temp[i] != temp[temp.size() - (i + 1)]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					cout << prime[i];
					break;
				}
			}
		}
	}
}
```
이전에 소수 관련 문제를 풀어봐서 그래도 쉽게 접근할 수 있었습니다. 주의해야 했던점은 n이 1000000일 때와 1003001이 그 다음 소수이므로 배열을 그 이상으로 선언해줘야 했고 n은 1일 때 예외처리를 잘 해줬어야 하는 문제였습니다.

