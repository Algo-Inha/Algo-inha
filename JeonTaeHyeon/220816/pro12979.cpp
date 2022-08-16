//기지국 설치
//https://school.programmers.co.kr/learn/courses/30/lessons/12979

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int cur = 1;
    int answer = 0;
    for (int i = 0; i < stations.size(); i++) {
        int sta = stations[i] - w;
        int temp = sta - cur;
        if (cur >= sta) {
            cur = stations[i] + w + 1;
            continue;
        }
        if (temp % (w * 2 + 1) == 0) {
            answer += temp / (w * 2 + 1);
        }
        else {
            answer += temp / (w * 2 + 1) + 1;
        }
        cur = stations[i] + w + 1;
    }
    if (cur <= n) {
        if ((n - cur + 1) % (w * 2 + 1) == 0)answer += (n - cur + 1) / (w * 2 + 1);
        else answer += (n - cur + 1) / (w * 2 + 1) + 1;
    }

    return answer;
}