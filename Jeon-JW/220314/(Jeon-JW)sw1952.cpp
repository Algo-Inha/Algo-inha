//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&problemTitle=1952&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1&&&&&&&&&
//수영장
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int money[4];
int month[12];
vector<int> answer;
int dp[12];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; i++) {
			cin >> money[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> month[i];
		}
		int ans = money[3]; // 1년이 기준
		//dp[n] = min(이전월의 최소값 + 해당월 일로계산, 이전월의 최소값 + 해당월 월로계산, 3개월전 최소값 + 3개월 계산)
		//1월 최소가격
		dp[0] = min(money[0] * month[0], money[1]);
		//2월 최소가격
		dp[1] = min(dp[0] + (money[0] * month[1]), dp[0] + money[1]);


		for (int i = 2; i < 12; i++) {
			dp[i] = min(dp[i - 1] + (money[0] * month[i]), min(dp[i - 1] + money[1], dp[i - 3] + money[2]));
		}
		ans = min(ans, dp[11]);

		answer.push_back(ans);
	}
	for (int i = 1; i <= answer.size();i++) {
		cout << "#" << i << " " << answer[i - 1] << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}