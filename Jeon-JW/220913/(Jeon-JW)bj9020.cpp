//https://www.acmicpc.net/problem/9020
//�������� ����
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

int n, T;
int max_num;
vector<int> num;
bool arr[10001];

int main() {

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		num.push_back(n);
		max_num = max(max_num, n);
	}

	arr[0] = 1; arr[1] = 1;
	for (int i = 2; i <= sqrt(max_num); i++) {
		if (arr[i] == 1) continue;
		for (int j = i + i; j <= max_num; j += i) {
			arr[j] = 1;
		}
	}
	//arr[i] = 0�̸� �Ҽ�

	

	for (int test_case = 0; test_case < T; test_case++) {
		for (int i = num[test_case] / 2; i >= 2; i--) {
			if ((arr[i] || arr[num[test_case] - i]) == 0) { // �� �� �Ҽ��� ���
				//cout << test_case << " " << i << " " << num[test_case] - i << '\n';
				cout << i << " " << num[test_case] - i << '\n';
				break;
			}
		}
	}




	return 0;
}