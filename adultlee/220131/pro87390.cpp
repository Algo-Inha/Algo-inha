// https://programmers.co.kr/learn/courses/30/lessons/87390?language=cpp
// 프로그래머스 N^2 배열 자르기
// 처음엔 무식하게 2차원 행렬로 구현하였으나 방향이 잘못 되었음을 파악하고 선회 하였습니다.

#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    //  n : 총 board 의 크기
    // left , right 각각 배열의 양끝 위치를 의미

    int N = right - left + 1; //1차원 배열 크기

    vector<int> answer(N);

    for (int i = 0; i < N; i++ ) {
        int r = left / n; //행
        int c = left % n; //열
        answer[i] = (r < c ? c : r) + 1; //행과 열 값 중 더 큰 값 + 1을 넣음
        left ++; // 1차원 배열의 위치를 이동시킵니다.
    }

    return answer;
}