//https://www.acmicpc.net/problem/1946
//���� ���
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


//�ٸ� ��� �����ڿ� ������ �� �����ɻ� ������ �������� ���� �� ��� �ϳ��� �ٸ� �����ں��� �������� �ʴ� �ڸ� �����Ѵٴ� ��Ģ�� ������. 
//��, � ������ A�� ������ �ٸ� � ������ B�� ������ ���� ���� �ɻ� ����� ���� ������ ��� �������ٸ� A�� ���� ���ߵ��� �ʴ´�. -- �� ���� �ٽ�
int T, N;

int temp1, temp2;
//100,000

int main() {

	vector<pair<int, int>> v;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N;
		int cnt = 1; // �� ���� ù��° �� 1���� �Ծ���.
		v.clear();
		for (int i = 0; i < N; i++) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}
		sort(v.begin(), v.end()); // ��������

		int pivot = 0;
		for (int i = 1; i < N; i++) {
			if (v[pivot].second > v[i].second) {
				pivot = i;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}


	return 0;
}


//1 4
//2 5
//3 6
//4 2
//5 7
//6 1
//7 3
//
//
//3 6 -> 1 4�� �Ѵ� ������ ���� Ż��
//
//7 3 -> 1 4�� �Ѵ� ������ ���� Ż��
//
//4 2 -> ��� �����ں��� �ּ� �Ѱ����� ����� �����ϱ� ����
//
//1 4-> ��� �����ں��� �ּ� �Ѱ����� ����� �����ϱ� ���� 
//
//5 7 -> 1 4�� �Ѵ� ������ ���� Ż��
//
//2 5 -> 1 4�� �Ѵ� ������ ���� Ż��
//
//6 1-> ��� �����ں��� �ּ� �Ѱ����� ����� �����ϱ� ���� 