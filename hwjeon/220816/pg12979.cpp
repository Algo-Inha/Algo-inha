#include <iostream>
#include <vector>
using namespace std;

int cal(int m, int k) { //answer 계산하기
	int num;
	if (m<0) return 0;

	if (m%k==0) num = m / k;
	else num = m / k + 1;
	
	return num;
}

int solution(int n, vector<int> stations, int w)
{
	#define len 2*w+1 //기지국포함 전파도달 범위

	int answer = 0;
	if (stations.front() - 1 > w)  //첫 station의 도달범위가 1번째 아파트를 포함하지 않는 경우 
	{
		answer += cal(stations.front() - w - 1, len);
	}

	if (stations.size()!=1)  // size가 한개일 경우 고려하지 않는다.
	{
		for (int i = 1; i < stations.size(); i++) //각 station 사이의 들어갈 수 있는 기지국 갯수 
		{
			answer += cal(stations.at(i) - stations.at(i - 1) - len, len);
		}
	}

	if (n - stations.back() > w) //마지막 station의 도달범위가 n번째 아파트를 포함하지 않는 경우
	{
		answer += cal(n - stations.back() - w, len);
	}

	
	return answer;
}