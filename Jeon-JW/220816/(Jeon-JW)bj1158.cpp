//https://www.acmicpc.net/problem/1158
//요세푸스 문제
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int N, K;
/*int arr1[5001];
bool check[5001];*/
queue<int> q;

int main() {

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	cout << "<";
	int temp;
	//while (!q.empty()) { 잘못생각했네..
	while(q.size() > 1){
		for (int i = 0; i < K - 1; i++) {
			temp = q.front();
			q.push(temp);
			q.pop();
		}
		temp = q.front();
		cout << temp << ", ";
		q.pop();
	}
	temp = q.front();
	cout << temp << ">";


	return 0;
}