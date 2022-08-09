
> 220809
> 양궁대회
```c++
#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int max_score = -1;

int get_score(vector<int> &a, vector<int> &r) {
	int apeach = 0, ryan = 0;
	for (int i = 0; i < 11; ++i) {
		if (a[i] == 0 && r[i] == 0) continue; // 둘 다 0점이면 패스

		if (a[i] >= r[i]) apeach += (10 - i); // 어피치 >= 라이언이면 어피치가
		else ryan += (10 - i); // 어피치 < 라이언이면 라이언이 점수 획득
	}

	if (ryan > apeach) return ryan - apeach;
	else return -1;
}

bool shoot_lower_score(vector<int> &ryan) {
	for (int i = 11 - 1; i >= 0; --i) { // 0점 과녁부터 비교
		if (ryan[i] > answer[i]) return true;
		else if (ryan[i] < answer[i]) return false;
	}
	return false;
}

void func(vector<int> &apeach, vector<int> &ryan, int chance, int idx) {
	if (idx == 11 || chance == 0) {
		int score = get_score(apeach, ryan);
		if (score != -1) {
			/*
				낮은 점수를 더 많이 맞힌 경우가 우선 순위가 있기 때문에,
				화살이 남아있으면 0점에 나머지 화살을 모두 쏨
			*/
			if (chance > 0) ryan[idx - 1] = chance;

			if (score == max_score && shoot_lower_score(ryan)) {
				answer = ryan;
			}

			else if (score > max_score) {
				max_score = score;
				answer = ryan;
			}

			ryan[idx - 1] = 0;
		}
		return;
	}

	if (chance > apeach[idx]) { // 어피치보다 한 발 더 맞추기
		ryan[idx] = apeach[idx] + 1;
		func(apeach, ryan, chance - ryan[idx], idx + 1);
		ryan[idx] = 0;
	}

	func(apeach, ryan, chance, idx + 1); // 쏘지 않고 다음 과녁으로
}

vector<int> solution(int n, vector<int> info) {
	vector<int> ryan(11, 0);

	func(info, ryan, n, 0);

	if (max_score == -1) return { -1 };

	return answer;
}
```
>- dfs로 풀은 풀이도 볼 수 있었는데 참고하여 같이 공부해보겠습니다.



>2개 이하로 다른비트
```c++
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;

	for (long long i = 0; i < numbers.size(); i++) {
		long long num = numbers[i];
		long long temp = num;
		int pos = 0;

		//짝수인 경우 +1
		if (num % 2 == 0) {
			answer.push_back(num + 1);
			continue;
		}

		//맨 앞이 0인 자리 찾기
		while ((temp & 1) == 1) {
			temp = temp >> 1;
			pos++;
		}

		//홀수인 경우 맨 앞자리 0을 1로, 그 다음 오른쪽 자리 1을 0으로 바꿔줌
		num += pow(2, pos) - pow(2, pos - 1);

		answer.push_back(num);
	}
	return answer;
}
```
>- 규칙을 코드로 어떻게 작성을 해야 하는지 확인을 더 해보았습니다.


>게리맨더링2
```c++ 
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int people[21][21];
int answer = 999999999;

void solution(int x, int y, int d1, int d2) {
	if (x + d1 + d2 > n || 1 > y - d1 || y + d2 > n) return;
	else {
		int label[21][21] = { 0 };
		int num[6] = { 0 };

		//5번구역 테두리 라벨링하기
		for (int i = x, j = y; i <= x + d1, j >= y - d1; i++, j--) label[j][i] = 5;
		for (int i = x, j = y; i <= x + d2, j <= y + d2; i++, j++) label[j][i] = 5;
		for (int i = x + d1, j = y - d1; i <= x + d1 + d2, j <= y - d1 + d2; i++, j++) label[j][i] = 5;
		for (int i = x + d2, j = y + d2; i <= x + d2 + d2, j >= y + d2 - d1; i++, j--) label[j][i] = 5;


		//안에 있는 구역 5로 채우기. for문으로 가능할듯.
		for (int y = 0; y <= n; y++) {
			int count = 0;
			int temp[21];
			for (int f = 0; f <= 20; f++)
				temp[f] = label[y][f];
			for (int x = 0; x <= n; x++) {
				if (label[y][x] == 5 && count == 0) {
					//                    cout<<x<<" "<<y<<"\n";
					count++;
				}
				else if (label[y][x] == 0 && count == 1) {
					label[y][x] = 5;
				}
				else if (label[y][x] == 5 && count == 1) {
					count++;
				}
				if (count == 2)
					break;
			}
			if (count == 1) {
				for (int f = 0; f <= 20; f++)
					label[y][f] = temp[f];
			}
		}



		//1,2,3,4 라벨링
		for (int i = 1; i <= n; i++) {//x
			for (int j = 1; j <= n; j++) {//y
				if (label[j][i] == 0) {
					if (1 <= i && i < x + d1 && j >= 1 && j <= y && label[j][i] != 5) label[j][i] = 1;
					else if (1 <= i && i <= x + d2 && j > y && j <= n && label[j][i] != 5) label[j][i] = 2;
					else if (i >= x + d1 && i <= n && 1 <= j && j < y - d1 + d2 && label[j][i] != 5) label[j][i] = 3;
					else if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n && label[j][i] != 5) label[j][i] = 4;
				}
			}
		}


				//배열에 넣고 최대차이 구하기
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int index = 1; index <= 5; index++) {
					if (label[j][i] == index) {
						num[index] += people[j][i];
					}
				}
			}
		}

		sort(num, num + 6);
		answer = min(answer, num[5] - num[1]);


	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> people[j][i];


	for (int r = 1; r < n; r++)
		for (int c = 1; c < n; c++)
			for (int d1 = 1; d1 < n; d1++)
				for (int d2 = 1; d2 < n; d2++)
					solution(r, c, d1, d2);

	cout << answer;
}
```
>- 브루트포스 문제였다고 하는데  좀 더 공부 해보겠습니다.

>최댓값과 최솟값
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s)
{
	string answer = "";
	vector<int> data;

	// 슬라이싱
	int idx = 0, start_idx = 0, size = s.size();
	while (true)
	{
		if (s[idx] == ' ')
		{
			string tmp = s.substr(start_idx, idx - start_idx);
			data.push_back(stoi(tmp));
			start_idx = idx + 1;
		}

		if (++idx == size)
		{
			string tmp = s.substr(start_idx);
			data.push_back(stoi(tmp));
			break;
		}
	}

	// 오름차순 정렬
	sort(data.begin(), data.end());
	answer += to_string(data.front()) + ' ' + to_string(data.back());
	return answer;
}
```
>-  생각을 코드로 작성하는 방법을 조금 더 알 수 있었습니다.

>오큰수
```c++
#include<iostream>
#include <stack>
using namespace std;

int a[1000001];
int nge[1000001];
stack<int> s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		while (!s.empty() && a[s.top()] < a[i]) {
			nge[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty()) {
		nge[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) cout << nge[i] << " ";

	return 0;
}
```
>- 스택헤더파일의 함수들을 더 잘 다룰수 있도록 해야겠습니다.
