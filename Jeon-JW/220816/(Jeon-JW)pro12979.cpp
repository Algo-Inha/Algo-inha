//https://school.programmers.co.kr/learn/courses/30/lessons/12979
//기지국 설치
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 1;
    for (int i = 0; i < stations.size(); i++) {
        int width = stations[i] - w - index; // 고려할 범위
        if (width > 0) {
            if (width % (w * 2 + 1) == 0) {
                answer += width / (w * 2 + 1); // 기지국 세워야할 넓이로 더해주기
            }
            else {
                answer += width / (w * 2 + 1) + 1;
            }
        }
        index = stations[i] + w + 1;// 다음 고려할 범위를 위해서 계산
    }
    // 마지막에 고려하지 않은 범위가 있을 경우 이부분도 고려해주기.
    if (index <= n) {
        if ((n - index + 1) % (w * 2 + 1) == 0) {
            answer += (n - index + 1) / (w * 2 + 1);
        }
        else {
            answer += (n - index + 1) / (w * 2 + 1) + 1;
        }
    }

    return answer;
}
//쉬운문제였는데 왜 막혔는지 모르겠다.... level3을 봐서 그런거같기도..