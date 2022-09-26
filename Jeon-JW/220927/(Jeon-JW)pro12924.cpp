//https://school.programmers.co.kr/learn/courses/30/lessons/12924
//숫자의 표현
#include <string>
#include <vector>

using namespace std;
int answer = 0;


int solution(int n) {
    int temp;
    for (int i = 1; i <= n / 2; i++) {
        temp = i;
        for (int j = i + 1; j <= n; j++) {
            if (temp == n) answer++;
            if (temp > n) break;
            temp += j;
        }
    }
    answer += 1;
    if (n == 1) answer = 1;

    return answer;
}