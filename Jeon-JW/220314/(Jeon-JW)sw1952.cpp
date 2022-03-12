//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE&problemTitle=1952&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1&&&&&&&&&
//������
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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
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
		int ans = money[3]; // 1���� ����
		//dp[n] = min(�������� �ּҰ� + �ش�� �Ϸΰ��, �������� �ּҰ� + �ش�� ���ΰ��, 3������ �ּҰ� + 3���� ���)
		//1�� �ּҰ���
		dp[0] = min(money[0] * month[0], money[1]);
		//2�� �ּҰ���
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}