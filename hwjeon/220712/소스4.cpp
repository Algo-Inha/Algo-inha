//��ǥ����
//vector, push_back, sort, lower_bound
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v, back;
	int n, input;
	cin >> n;
	/*
	int* arr = new int[n];
	int* count = new int[n] {};
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i]>arr[j])
			{
				count[i] ++;
			}
		}

		cout << count[i] << " ";
	}
	

	delete[] arr;
	delete[] count;
	*/
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input); //push_back�� ���� ��Ҹ� �߰��Ѵ�, uhique��ų ����
		back.push_back(input);//���� �迭
	}

	sort(v.begin(), v.end()); //sort�Լ��� ���� �����Ͽ���.
	v.erase(unique(v.begin(), v.end()), v.end()); //unique�� erase�� �ߺ��� ���Ҹ� ���ش�.

	for (int i = 0; i < n; i++) {
		printf("%d ", lower_bound(v.begin(), v.end(), back[i]) - v.begin());//lower_bound �Լ��� back[i] ���� 
																			//���� ������ ������ ����Ѵ�.
	}
}