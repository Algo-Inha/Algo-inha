//https://school.programmers.co.kr/learn/courses/30/lessons/12899
//124 나라의 숫자
#include <string>
#include <vector>

using namespace std;

//3으로 떨어짐. 
string solution(int n) {
    string answer = "";
    for (;;) {
        if (n == 0) break;
        n -= 1;
        int temp = n % 3;
        n = n / 3;
        if (temp == 2) {
            answer = "4" + answer;
        }
        else answer = to_string(temp + 1) + answer;
    }


    return answer;
}
/*
1
2
4
11
12
14`
21
22
24
41 10
42 11
44 12 - 4, 0
111 13 - 4, 1
112 14 - 4, 2
114

*/