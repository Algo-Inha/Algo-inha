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

//혼자서 풀었지만 시행착오를 많이 거쳤다. 다음에 큐 문제가 나오면 조금 더 빠르게 풀 수 있을 것 같다