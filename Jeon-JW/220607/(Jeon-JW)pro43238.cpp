//https://programmers.co.kr/learn/courses/30/lessons/43238?language=cpp
//입국심사
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = (long long)times[0]; // 가장 왼쪽(짧은) 걸리는 시간
    long long right = (long long)times[times.size() - 1] * n; // 가장 오른쪽 걸리는 시간 * 사람의 수 -> 가장 오래걸리는 경우
    long long answer = right; // 
    while (left <= right) { // left와 right교차되는 부분
        long long mid = (right + left) / 2; // 가운데 부분
        long long pass = 0;

        for (int i = 0; i < times.size(); i++) {
            pass += mid / (long long)times[i];
            //둘의 평균을 시간들로 나눠서 더해준다.
            //mid로 계산했을 때 총 걸리는 시간.
        }
        //해당 시간 내에 모든 사람들의 심사가 끝나는지 여부
        if (pass >= n) { // pass로 인원들을 다 계산할 수 있을 때
            right = mid - 1; // right의 범위 줄이기
            if (mid <= answer) answer = mid;
        }
        //안되면 왼쪽을 끌어와 mid를 올려준다.
        else left = mid + 1;
    }

    return answer;
}