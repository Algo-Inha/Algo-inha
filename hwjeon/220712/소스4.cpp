//좌표압축
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
		v.push_back(input); //push_back을 통해 요소를 추가한다, uhique시킬 벡터
		back.push_back(input);//원래 배열
	}

	sort(v.begin(), v.end()); //sort함수를 통해 정렬하였다.
	v.erase(unique(v.begin(), v.end()), v.end()); //unique와 erase로 중복된 원소를 없앤다.

	for (int i = 0; i < n; i++) {
		printf("%d ", lower_bound(v.begin(), v.end(), back[i]) - v.begin());//lower_bound 함수로 back[i] 보다 
																			//작은 원소의 갯수를 출력한다.
	}
}