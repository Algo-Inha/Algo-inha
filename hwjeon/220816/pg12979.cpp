#include <iostream>
#include <vector>
using namespace std;

int cal(int m, int k) { //answer ����ϱ�
	int num;
	if (m<0) return 0;

	if (m%k==0) num = m / k;
	else num = m / k + 1;
	
	return num;
}

int solution(int n, vector<int> stations, int w)
{
	#define len 2*w+1 //���������� ���ĵ��� ����

	int answer = 0;
	if (stations.front() - 1 > w)  //ù station�� ���޹����� 1��° ����Ʈ�� �������� �ʴ� ��� 
	{
		answer += cal(stations.front() - w - 1, len);
	}

	if (stations.size()!=1)  // size�� �Ѱ��� ��� ������� �ʴ´�.
	{
		for (int i = 1; i < stations.size(); i++) //�� station ������ �� �� �ִ� ������ ���� 
		{
			answer += cal(stations.at(i) - stations.at(i - 1) - len, len);
		}
	}

	if (n - stations.back() > w) //������ station�� ���޹����� n��° ����Ʈ�� �������� �ʴ� ���
	{
		answer += cal(n - stations.back() - w, len);
	}

	
	return answer;
}