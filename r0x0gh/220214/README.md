
﻿
## 1,2,3 더하기
https://www.acmicpc.net/problem/9095
### 문제풀이
```c
//백준 09095번 : 1,2,3 더하기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ott(12, 0);
	
	ott[1] = 1;
	ott[2] = 2;
	ott[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		ott[i] = ott[i - 1] + ott[i - 2] + ott[i - 3];
	}

	int T, n;

	//cout << "ㄱㄱ" << endl; 이부분들이
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		//cout << "n : "; 문제였다
		cin >> n;
		cout << ott[n] << endl;
	}
	
	return 0;
}
```


### 의견
처음으로 백준  제출란에 제출한 문제다. 솔직히 dp개념이 아직 잡히진 않았다. 그래서 올바른 접근인지는 모르겠지만 문제 선정 당시 dp 문제 하나는 넣어야지 했던 게 기억나서 이게 그건가 하면서 풀었다.개념 다 잡고 문제 풀다간 평생 아무것도 못할 것 같아서 문제마다 새로운 개념 나오면 강의 찾아보는 식으로 진행해야겠다고 생각하게 해준 문제였다. 
수1 점화식이 생각나는 풀이라 종이에 풀어보고 코드로 작성했다. 'vector'때문에 코딩 포기했다고 해도 과언이 아닌데 vector부터 강의 들어가며 익히면서 풀었다. 마침 이번 3문제 모두 vector가 나와서 익히는데 좋았다.
생각보다 어렵지 않은 문제가 왜 3시간 동안 해도 틀릴까 답은 맞는데.. 싶었는데 저기 위 코드 주석 보면 알 수 있다.
너무 빈칸이라 뭘 입력해야할지 헷갈려서 만들어 놓은 출력들이 문제였다. 처음 제출해보는 티 너무낸 거 같다.

## 치킨 배달
https://www.acmicpc.net/problem/15686
### 문제풀이
```c
// 백준 15686번 : 치킨 배달
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ans = 999999;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void distance(int c, int what, vector<int> result)
{
	for (int i = 0; i < house.size(); i++)
	{
		int dy = abs(chicken[c].first - house[i].first);
		int dx = abs(chicken[c].second - house[i].second);

		if (result[i] == 0 || result[i] > dy + dx) 
		{
			result[i] = dy + dx;
		}
	}
	
	if(what==M)
	{
		int sum = 0;
		for (int i = 0; i < result.size(); i++)
		{
			sum += result[i];
		}
		if (sum < ans)
		{
			ans = sum;
		}
		return;
	}
	//이 변수를 what이라고 쓴 이유:어떻게 풀어야는지는 알겠는데
	//결과적으로 이 코드가 그래서 뭐 어떻게 이걸 해결한건지 완벽히는 모르겠음
	for (int i = c + 1; i < chicken.size(); i++)
	{
		distance(i, what + 1, result);
	}
	return;//여기까지
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int city;
			cin >> city;

			if (city == 1) { house.push_back({ i,j }); }
			else if (city == 2) { chicken.push_back({ i,j }); }
		}
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		vector<int>result(house.size());
		distance(i, 1, result);
	}

	cout << ans << endl;
}
```

### 의견
종이에 그려가면서 해서 어떻게 상세히 설명을 달아야 할지는 모르겠지만 다음에는 시간을 더 넉넉히 잡고 풀이를 작성할 방도를 모색해봐야 할 것 같다.
풀이 자체는 처음에 그닥 어렵다고 생각하지는 않았다. 문제 풀 당시에 문제 난이도를 보는 방법을 몰라서 쫄지 않은 덕분인 것 같았다. BFS, DFS 뭐 들어본 건 있는데 그건가 싶다가 이건 그런 것은 아니고 컴퓨터에게 단순 반복 작업을 시키는 게 맞다는 판단이 들어서 빠지는 경우가 없게 일일이 찾게 만들어야겠다는 생각이 들었다.
어쨌든 2차원 좌표인데 이를 좀 좌표스럽게 쉽게 저장할 수 있는 방법이 없을까 너무 답답했다. 이걸 내가 아는 vector나 배열로는 너무 험난한 길이 예상되었다. 그러다가 한 블로그에서  **vector<pair<,>>** 를 활용하는 것을 보았다. 이걸 보고 정말 박수를 쳤다. 덕분에 내가 이해하는 그림대로 코드를 구현했다.
하지만 단 한 가지 의문인 것은 치킨집을 선택하는 경우의 수를 구현하는 과정에서 좋은 방법을 찾지 못해서 다른 답을 참고해보았는데 저게 왜 답인지 아직 잘 이해가  가지 않는다.(주석부분)


## 시험감독 
https://www.acmicpc.net/problem/13458
### 문제풀이
```c
//백준 13458번 : 시험감독
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> students(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> students[i];
	}
	int b, c;
	cin >> b >> c;
	
	long long answer = n;
	long long sub_director = 0;
	for (int i = 0; i < n; i++) {
		sub_director = 0;
		students[i] -= b;
		
		if (students[i] > 0) {
			if (students[i] % c == 0) {
				sub_director = students[i] / c;
			}
			else {
				sub_director = students[i] / c + 1;
			}
			answer += sub_director;
		}
	}
	cout << answer;
	return 0;
}

```
### 의견
치킨 배달보다가 보니 선녀였다. 특별할 부분도 없고 이 문제마저도 vector를 사용한 덕에 vector를 익히는 좋은 과정이 된 것 같다.

# Overview
이게 따로 있을 줄 알았으면 앞에서 빼고 여기다 쓸 걸.
