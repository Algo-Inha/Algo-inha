// ���� 15686�� : ġŲ ���
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
	//�� ������ what�̶�� �� ����:��� Ǯ��ߴ����� �˰ڴµ� ��������� �� �ڵ尡 �׷��� �� ��� �̰� �ذ��Ѱ��� �Ϻ����� �𸣰���
	for (int i = c + 1; i < chicken.size(); i++)
	{
		distance(i, what + 1, result);
	}
	return;//�������
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