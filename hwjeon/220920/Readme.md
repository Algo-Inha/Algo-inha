
> 220906
> 상급이의 여행
```c++
#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			int a, b;
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}
}

```
>- 이게 맞나 싶어서 좀 걸렸던 것 같습니다. 
>- 너무 어렵게 생각할 필요가 없던 것 같습니다다. 
>- 얻어걸린 것 이라면 정확한 풀이를 알고 싶습니다




>소수&팰린드롬
```c++
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	string numb;
	int number = 1003001;
	int num[1003002];
	cin >> n;
	if (n == 1) cout << 2;
	else {
		for (int i = 0; i < number; i++)
		{
			num[i] = i;
			numb = to_string(i);
			string buf = numb;
			reverse(numb.begin(), numb.end());
			if (numb != buf) {
				num[i] = 0;
			}
		}


		for (int i = 2; i <= number; i++)
		{
			if (num[i] == 0) continue;
			for (int j = i + i; j <= number; j += i)
			{
				num[j] = 0;
			}

		}
		for (int i = n; i < number; i++)
		{
			if (num[i] != 0)
			{
				cout << i << endl;
				break;

			}
		}
	}
	
}
```
>- reverse함수에 대해 알 수 있었습니다.
>- 에라테스테네스의 체를 한번 더 확인 할 수 있었습니다.
>- 1인경우라던가 1003001이 정답인 경우 등 고쳐보았지만 틀렸다고 뜹니다 ㅠ..


>키패드 누르기
```c++ 
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lefthand = 10, righthand = 12, leftdist = 0, rightdist = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "l";
			lefthand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "r";
			righthand = numbers[i];
		}
		else
		{
			if (numbers[i] == 0)
				numbers[i] = 11;
			int tmp_l = abs(lefthand - numbers[i]);
			int tmp_r = abs(righthand - numbers[i]);

			leftdist = (tmp_l / 3) + (tmp_l % 3); //3개의 숫자마다 줄이 바뀌어 있음을 이용
			rightdist = (tmp_r / 3) + (tmp_r % 3);

			if (leftdist == rightdist)
			{
				if (hand == "right")
				{
					answer += "r";
					righthand = numbers[i];
				}
				else
				{
					answer += "l";
					lefthand = numbers[i];
				}
			}
			else if (leftdist < rightdist)
			{
				answer += "l";
				lefthand = numbers[i];
			}
			else
			{
				answer += "r";
				righthand = numbers[i];
			}
		}
	}
	return answer;
}
```
>- 키패드에서 2 5 8 0 의 숫자일 때 거리를 구하는 것에서 막혀서 구글링을 하였습니다.
>- 3을 나눈 몫과 나머지를 이용한 풀이가 인상깊어서 기억에 남습니다.

 >이진 변환 반복하기
 ```c++
 #include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer(2, 0);
	int zero = 0, round = 0;

	while (s != "1")
	{
		string tmp = "";
		int size = 0, num;
		round++;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '0')
				zero++;
			else
				tmp += "1";
		}

		num = tmp.size();
		s = "";
		while (num > 0)
		{
			s += to_string(num % 2);
			num /= 2;
		}
	}

	answer[0] = round;
	answer[1] = zero;
	return answer;
}
 ```
 >- strcmp로 비교를 하여 0을 지울생각으로 처음에 접근하였습니다.
 >- 구글링을 통해 0을 굳이 지우지 않고도 풀 수 있다는 것을 알게 되었습니다. 
 >- 10진수를 2진수로 바꾸는 방법도 한번 더 할 수 있었습니다.
 

