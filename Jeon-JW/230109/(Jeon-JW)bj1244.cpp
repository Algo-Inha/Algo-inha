//https://www.acmicpc.net/problem/1244
//스위치 켜고 끄기
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
bool map[101];
int num;

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}
	cin >> num;
	int sex, temp;
	int pivot;
	for (int i = 0; i < num; i++) {
		cin >> sex >> temp;
		if (sex == 1) {
			for (int j = temp; j <= N; j += temp) {
				map[j] = !map[j];
			}
		}
		else {
			pivot = 0;
			for (int j = 1; j <= N; j++) {
				pivot++;
				if ((temp - pivot) <= 0 || (temp + pivot) > N) break;
				if (map[temp - pivot] != map[temp + pivot]) break;
			}
			if (pivot == 1) {
				map[temp] = !map[temp];
			}
			else {
				for (int k = temp - pivot + 1; k <= temp + pivot - 1; k++) {
					map[k] = !map[k];
				}
			}
		}
		/*for (int i = 1; i <= N; i++) {
			cout << map[i] << " ";
		}
		cout << endl;*/
	}

	for (int i = 1; i <= N; i++) {
		cout << map[i] << " ";
		if (i % 20 == 0) cout << endl;
	}

	return 0;
}