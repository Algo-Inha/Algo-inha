//https://www.acmicpc.net/problem/5884
#include <iostream>
#include <vector>
using namespace std;

int N;
int arr_x[50000] = { 0 };
int arr_y[50000] = { 0 };
bool ans = false;

void DFS(int cnt, vector<pair<int, int>> v)
{
	if (ans)
		return;
	if (v.size() > 3)
		return;
	if (cnt == N)
	{
		ans = true;
		return;
	}

	if (cnt == 0)
	{
		v.push_back({ arr_x[0],-1 });
		DFS(cnt + 1, v);
		v.pop_back();

		v.push_back({ -1,arr_y[0] });
		DFS(cnt + 1, v);
	}
	else
	{
		bool flag = false;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first == arr_x[cnt])
			{
				flag = true;
				DFS(cnt + 1, v);
				break;
			}
			if (v[i].second == arr_y[cnt])
			{
				flag = true;
				DFS(cnt + 1, v);
				break;
			}
		}

		if (!flag)
		{
			v.push_back({ arr_x[cnt],-1 });
			DFS(cnt + 1, v);
			v.pop_back();

			v.push_back({ -1,arr_y[cnt] });
			DFS(cnt + 1, v);
		}
	}
}

int main()
{	
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr_x[i] >> arr_y[i];

	if (N <= 3)
	{
		cout << "1\n";
		return 0;
	}

	DFS(0, v);

	cout << ans << "\n";
	return 0;
}