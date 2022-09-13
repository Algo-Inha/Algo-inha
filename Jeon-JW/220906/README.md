
#  키패드 누르기
### pro67256
https://school.programmers.co.kr/learn/courses/30/lessons/67256
+ `구현`
```c++
int arr[2][10] = { // 키패드 좌표
    {3,0,0,0,1,1,1,2,2,2},
    {1,0,1,2,0,1,2,0,1,2}
};
bool r;
int rh[2] = { 3,2 };
int lh[2] = { 3,0 };

string solution(vector<int> numbers, string hand) {
    string answer = "";
    if (hand[0] == 'r') r = 1; // 오른손잡이

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num % 3 == 1) { // 1 4 7
            answer += "L";
            lh[0] = arr[0][num];
            lh[1] = arr[1][num];
        }
        else if (num % 3 == 0 && num != 0) {// 3 6 9
            answer += "R";
            rh[0] = arr[0][num];
            rh[1] = arr[1][num];
        }
        else { // 2 5 8 0
            int llen = abs(lh[0] - arr[0][num]) + abs(lh[1] - arr[1][num]);
            int rlen = abs(rh[0] - arr[0][num]) + abs(rh[1] - arr[1][num]);

            if (llen == rlen) {
                if (r) {
                    answer += "R";
                    rh[0] = arr[0][num];
                    rh[1] = arr[1][num];
                }
                else {
                    answer += "L";
                    lh[0] = arr[0][num];
                    lh[1] = arr[1][num];
                }
            }
            else if (llen < rlen) {
                answer += "L";
                lh[0] = arr[0][num];
                lh[1] = arr[1][num];
            }
            else {
                answer += "R";
                rh[0] = arr[0][num];
                rh[1] = arr[1][num];
            }
        }
    }

    return answer;
}
```
>-  사장님이 쉽고 구현이 친절한 문제였습니다.


# 상근이의 여행
### bj9372
https://www.acmicpc.net/problem/9372
- `구현`
```c++
cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			//v.push_back(make_pair(a, b));
		}
		cout << N - 1 << '\n';


	}
```
> - 처음엔 조금 헤매다가 몇번 수기로 풀어보고 알게되었습니다.


# 소수&펠린드롬
### bj1747
https://www.acmicpc.net/problem/1747
- `소수`
```c++
void eratos() {
	arr[1] = 1;
	for (int i = 2; i * i < 2000000; i++) {
		if (arr[i]) continue;
		for (int j = i * 2; j < 2000000; j += i) {
			arr[j] = true;
		}
	}
}

bool palin(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) return false;
	}
	return true;
}

//main
	cin >> N;

	eratos();
	for (int i = N; i < 2000000; i++) {
		if (arr[i])continue;
		if (palin(i)) {
			cout << i;
			break;
		}
	}

```
>- 문제를 처음보고 소수다 싶어서 에라토스테네스의 체를 구현했지만 숫자가 생각보다 너무 커서 과연 이게 맞을까 고민을 잠시했었습니다.


# 이진 변환 반복하기
### pro70129
https://school.programmers.co.kr/learn/courses/30/lessons/70129?language=cpp
- `문자열 처리`
```c++
string to_binary(int num) {
    string s = "";
    while (num > 0) {
        if (num % 2 == 1)s = "1" + s;
        else s = "0" + s;
        num >>= 1;
    }
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    string strtemp;
    int cnt = 0;
    int ans_cnt = 0;
    for (;;) {
        strtemp = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                strtemp += "1";
            }
            else {
                cnt++;
            }
        }
        s = to_binary(strtemp.length());
        ans_cnt++;
        if (s == "1") break;
    }
    answer.push_back(ans_cnt);
    answer.push_back(cnt);

    return answer;
}
```
>- 굳이 따지자면 문자열 처리 문제이지만 C++으로도 쉽게 처리가능한 문제였습니다.

- 이번 주 시간이 많이 부족해서 한 문제를 못풀고 readme를 쓰는 시간이 너무 늦었습니다. 죄송합니다.
