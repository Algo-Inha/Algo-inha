//숫자의 표현
//https://school.programmers.co.kr/learn/courses/30/lessons/12924

#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int size = n;//size =n/2를 하지 않아도 효율성 통과..?
    for (int i = 1; i <= size; i++) {
        int sum = 0;
        for (int j = i; j <= size; j++) {
            sum += j;
            if (sum > n)break;
            if (sum == n) {
                cout << sum << endl;
                ++answer;
                break;
            }
        }
    }
    return answer;
}
