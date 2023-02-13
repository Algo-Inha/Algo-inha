//https://www.acmicpc.net/problem/15666
//N°ú M(12)
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int N, M;
int output[9];
int arr[9];

void func(int a, int b) {
	if (b == M) {
		for (int i = 0; i < M; i++) {
			cout << output[i] << " ";
		}
		cout << endl;
		return;
	}

	int temp = 0;

	for (int i = a; i < N; i++) {
		if (arr[i] != temp) {
			output[b] = arr[i];
			temp = output[b];
			func(i, b + 1);
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	func(0, 0);


	return 0;
}