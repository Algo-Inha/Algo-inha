//�Ҿ���� ��ȣ
//stoi
#include<iostream>
#include<string>
using namespace std;

int main() {
	string expression;
	int minus_check = 0; //-�� �ѹ� ���� ���� ��� ��ȣ�� -���� �ּڰ��� ����
	string number;
	int answer=0;

	cin >> expression;
	for (int i = 0; i <= expression.size(); i++)
	{

		if (expression[i] == '-' || expression[i] == '+'||i==expression.size()) { // ������ ���ڰ� �������� ���Ƿ� 
			if (minus_check==1)                                                   // i�� �� size�� ���� �� ���� if���� �����ؾ��Ѵ� 
			{
				answer -= stoi(number); //stoi�Լ��� string�� int�÷� ǥ���Ѵ�.
				number = ""; //�ʱ�ȭ ������ ������ �߰��� �ȴ�.
			}
			else {
				answer += stoi(number);
				number = "";
			}
		}
		else
			number += expression[i];

		if ((int)expression[i] == 45)
		{
			minus_check = 1;
		}
	}
	cout << answer;
}