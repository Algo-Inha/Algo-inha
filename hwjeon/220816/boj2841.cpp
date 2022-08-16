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
//너무 오래 걸렸다. 테스트 케이스만 맞출려고 하지말고 크게 보아야겠다.