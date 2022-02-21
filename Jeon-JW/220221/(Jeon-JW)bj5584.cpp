// https://www.acmicpc.net/problem/5884
// ����ī�޶�
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

int n;
vector<pair<int, int>> cow;
//unordered_map<int, int> um_y;
//unordered_map<int, int> um_x;
unordered_map<string, int> um;
//int visit[2][3]; // (y, x)-(0,1) / [3���� ��ǥ]
// �ƹ��� �����ص� �������δ� �ð��� �ȵɰͰ���.
int select_int[3];
string select_str[3];
bool check[50000]; // vector�� �Ҵ�������ߴµ� ��Ÿ�ӿ���

//���� ī�޶�� �� 3�� // ���� �������� ��� ���� �����ϴ�.
int main() {

	cin >> n;
	int temp_y, temp_x;
	for (int i = 0; i < n; i++) {
		cin >> temp_y >> temp_x;
		cow.push_back(make_pair(temp_y, temp_x));
		//um_y[temp_y]++;
		//um_x[temp_x]++;
		um["y" + to_string(temp_y)]++;
		um["x" + to_string(temp_x)]++;
	}
	//�ִ� ��Ȯ��
	for (auto elem : um) {
		if (select_int[0] < elem.second) {
			select_int[2] = select_int[1];
			select_str[2] = select_str[1];
			select_int[1] = select_int[0];
			select_str[1] = select_str[0];
			select_int[0] = elem.second;
			select_str[0] = elem.first;
		}
		else if (select_int[1] < elem.second) {
			select_int[2] = select_int[1];
			select_str[2] = select_str[1];
			select_int[1] = elem.second;
			select_str[1] = elem.first;
		}
		else if (select_int[2] < elem.second) {
			select_int[2] = elem.second;
			select_str[2] = elem.first;
		}
	}
	
	/*for (int i = 0; i < 3; i++) {
		cout << select_str[i] << " " << select_int[i] << endl;
	}*/
	// ī�޶�� Ȯ�ΰ����� ���� �� Ȯ��
	bool dir;
	int num=0;
	for (int i = 0; i < 3; i++) {
		if (select_str[i][0] == 'y') dir = 0;
		else dir = 1;
		num = stoi(select_str[i].substr(1));
		
		for (int j = 0; j < n; j++) {
			if (check[j]) continue;
			if (dir == 0) {
				if (cow[j].first == num) check[j] = 1;
			}
			else {
				if (cow[j].second == num) check[j] = 1;
			}
		}
	}

	bool flag = 0;
	for (int i = 0; i < n; i++) {
		if (check[i] == 0) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	
	return 0;
}