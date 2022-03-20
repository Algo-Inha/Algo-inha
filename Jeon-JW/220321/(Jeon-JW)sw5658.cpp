#define _CRT_SECURE_NO_DEPRECATE
//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo&categoryId=AWXRUN9KfZ8DFAUo&categoryType=CODE&&&&&&
//보물상자 비밀번호
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int N, K;
int N_temp;
vector<int> ans;
vector<int> number;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("sample_input.txt", "r", stdin);

	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		number.clear();

		cin >> N >> K;
		N_temp = N / 4;
		string str = "";
		cin >> str;
		for (int i = 0; i < N_temp - 1; i++) {
			str += str[i];
		}
		//cout << "str = " << str << endl;
		// 1B3B3B81F75E + 1B  (3(N_temp)-1)

		for (int i = 0; i <= str.length() - N_temp; i++) {
			string str_temp = "";
			int i_temp = 0;
			for (int j = i; j < i + N_temp; j++) {
				str_temp += str[j];
			}
			//cout << "str_temp = " << str_temp << endl;
			for (int j = 0; j < str_temp.length(); j++) {
				if (str_temp[j] >= 'A') {
					i_temp += (str_temp[j] - 'A' + 10) * pow(16, N_temp - j - 1);
				}
				else {
					i_temp += (str_temp[j] - '0') * pow(16, N_temp - j - 1);
				}
			}
			//cout << "i_temp = " << i_temp << endl;
			number.push_back(i_temp);
		}

		sort(number.rbegin(), number.rend());

		/*for (int i = 0; i < number.size(); i++) {
			cout << number[i] << endl;
		}*/

		//K번째 찾기 -- 이부분이 틀린거같은데.
		if (K == 1) {
			ans.push_back(number[0]);
			//cout << number[0] << endl;
		}
		//else {
		//	int k_temp = 1;
		//	for (int i = 1; i < number.size(); i++) {
		//		if (k_temp == K) {
		//			ans.push_back(number[i - 1]);
		//			cout << number[i - 1] << endl;
		//			break;
		//		}
		//		if (number[i] == number[i - 1]) continue;
		//		k_temp++;
		//		cout << k_temp << endl;
		//	}
		//	//ans.push_back(number[K - 1]);
		//}
		else {//number i~(number.size()-1)
			int k_temp = 1;
			for (int i = 1; i < number.size(); i++) {
				k_temp++;
				if (number[i - 1] == number[i]) {
					k_temp--;
					continue;
				}
				if (k_temp == K) {
					ans.push_back(number[i]);
					break;
				}
				//cout << k_temp << "number[i] = " << number[i] << endl;
			}
			//ans.push_back(number[K - 1]);
		}
	}

	for (int i = 1; i <= T; i++) {
		cout << "#" << i << " " << ans[i - 1] << "\n";
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}