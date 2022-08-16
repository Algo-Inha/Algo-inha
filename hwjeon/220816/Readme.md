
> 220816
> 외계인의 기타연주
```c++
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n, p, count=0;
	int line, pr;
	stack<int> sarr[6];
	cin >> n >> p;
	for (int i = 0; i <n; i++)
	{
		cin >> line >> pr;

		if (sarr[line-1].empty() == 1 || sarr[line-1].top()<pr)
		{
			sarr[line-1].push(pr);
			count++;
		}
		else if (sarr[line - 1].top() == pr)
		{
			continue;
		}
		else {
			while (sarr[line - 1].top() > pr )
			{
				sarr[line-1].pop();
				count++;
				if (sarr[line - 1].size() == 0)
				{
					break;
				}
			}
			if (sarr[line - 1].size() == 0 || (sarr[line-1].size()!=0 && sarr[line - 1].top() != pr))
			{
				sarr[line - 1].push(pr);
				count++;
			}

		}
	}
	cout << count;

}

```
>-너무 오래 걸렸다. 테스트 케이스만 맞출려고 하지말고 크게 보아야겠다.




>요세푸스문제
```c++
#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, k, count = 0;
	cin >> n >> k;
	queue<int> q;


	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	cout << "<";
	while (1)
	{
		count++;
		if (count%k==0)
		{
			cout << q.front();
			q.pop();
			if (q.empty()!=1)
			{
				cout << ", ";
			}
		}
		else
		{
			q.push(q.front());
			q.pop();
		}
		
		if (q.empty() == 1) {
			cout << ">";
			break;
		}
		
	}
}
```
>- 혼자서 풀었지만 시행착오를 많이 거쳤다. 다음에 큐 문제가 나오면 조금 더 빠르게 풀 수 있을 것 같다.


>기지국설치
```c++ 
#include <iostream>
#include <vector>
using namespace std;

int cal(int m, int k) { //answer 계산하기
	int num;
	if (m<0) return 0;

	if (m%k==0) num = m / k;
	else num = m / k + 1;
	
	return num;
}

int solution(int n, vector<int> stations, int w)
{
	#define len 2*w+1 //기지국포함 전파도달 범위

	int answer = 0;
	if (stations.front() - 1 > w)  //첫 station의 도달범위가 1번째 아파트를 포함하지 않는 경우 
	{
		answer += cal(stations.front() - w - 1, len);
	}

	if (stations.size()!=1)  // size가 한개일 경우 고려하지 않는다.
	{
		for (int i = 1; i < stations.size(); i++) //각 station 사이의 들어갈 수 있는 기지국 갯수 
		{
			answer += cal(stations.at(i) - stations.at(i - 1) - len, len);
		}
	}

	if (n - stations.back() > w) //마지막 station의 도달범위가 n번째 아파트를 포함하지 않는 경우
	{
		answer += cal(n - stations.back() - w, len);
	}

	
	return answer;
}
```
>- 테스트 케이스가 몇 개가 실행이 되지않아 해결을 못하였습니다.
>- 정확성 43.6, 효율성 22.1 으로 채점되었습니다.
>

