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
	//이 변수를 what이라고 쓴 이유:어떻게 풀어야는지는 알겠는데 결과적으로 이 코드가 그래서 뭐 어떻게 이걸 해결한건지 완벽히는 모르겠음
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