//비밀번호

//극한의 구현...
#include <iostream>
#include <set>

using namespace std;

int N, K;
char edge[4][7];
char str[56];
// 
int hex_to_dec(char* hex, int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			ret = ret * 16 + (hex[i] - '0');
		}
		else { // 'A' ~ 'F'
			ret = ret * 16 + (hex[i] - 'A' + 10);
		}
	}
	return ret;
}

int password() {
	int n = N / 4;
    int ret;
    int idx;
	set<int> candidates;

	// 시간에 맞추어 회전시킵니다.
	for (int i = 0; i < n; i++) {
		idx = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < N / 4; k++) {
				edge[j][k] = str[i+idx];
				idx++;
			}
		}
		
		for (int j = 0; j < 4; j++) {
			ret = hex_to_dec(edge[j], n);
			if (candidates.find(ret) == candidates.end()) { // set 함수의 find 를 사용합니다
				candidates.insert(ret);
			}
		}
	}

	int size = candidates.size();
	set<int>::iterator itr = candidates.begin(); //10진수로 구한 값들을 여기다가 넣어준다. 오름차순
	for (int i = 0; i < size - K; i++) {
		itr++;
	}
	return *itr; //주소를 리턴한다.
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> str[i];
			str[i + N] = str[i];
		}
		cout << '#' << test_case << ' ' << password() << '\n';
	}

	return 0;
}